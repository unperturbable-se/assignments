#include <iostream>
using namespace std;
template <typename T>
struct Node
{
Node<T>* next=nullptr;
Node<T>* prev=nullptr;
T val;
Node(T val):val{val}{};
Node(){};
void push(T value)
{
    if(next)
    {
        Node<T>* temp=new Node<T>(value);
        temp->prev=this;
        temp->next=next;
        next->prev=temp;
        next=temp;
    }
    else
    {
        next=new Node<T>(value);
        next->prev=this;
    }
}
};

template<typename T>
class Stack
{
   Node<T>* top=nullptr;
   public:
   void push(T val)
   {
       if(!top)top=new Node<T>(val);
       else
       {
       top->push(val);
       top=top->next;
       }
   }

   T pop()
   {
       if(!top)return T();
       T val=top->val;
       if(!top->prev){delete top;top=nullptr;}
       else
       {
           top=top->prev;
           delete top->next;
           top->next=nullptr;
       }
       return val;
   }

   T peek()
   {
       if(!top)return T();
       return top->val;
   }

   bool isEmpty()
   {
       return (!top);
   }

   ~Stack()
   {
       if(!top)return;
       while(top->prev)
       {
           top=top->prev;
           delete top->next;
       }
       delete top;
   }
   
};


string* tokenizer(string s)
{
    static string tokens[100];
    int n=0; 
    for(int i=0;i<s.size();)
    {
        if(isdigit(s[i])||s[i]=='.')
        {
            int j=i; 
            while(j<s.size()&&(isdigit(s[j])||s[j]=='.')) j++;
            tokens[n++]=s.substr(i,j-i);
            i=j;
        }
        else tokens[n++]=s.substr(i++,1);
    }
    tokens[n] = ""; // mark end
    return tokens;
}

bool isOperator(char x)
{
    return (x=='+'||x=='-'||x=='*'||x=='/');
}
float evaluate(float operand1,float operand2,char symbol)
{
    switch(symbol)
    { 
        case '+':return operand1+operand2;
        case '*':return operand1*operand2;
        case '-':return operand1-operand2;
        case '/':return operand1/operand2;

    }
    return 0;
}

int precedence(char x)
{
    if(x=='+'||x=='-')return 0;    
    if(x=='*'||x=='/')return 1;    
    if(x=='^')return 2;   
    return -1; 
}

float solveEquation(std::string equation) 
{
    Stack<float> calc; 
    Stack<char> operators; 
    std::string* tokens = tokenizer(equation);
    for (int i = 0; tokens[i] != ""; i++) 
    {
        if (tokens[i].size() == 1 && isOperator(tokens[i][0])) 
        {
            while (!operators.isEmpty() && precedence(operators.peek()) >= precedence(tokens[i][0])) 
            {
                float b = calc.pop(), a = calc.pop();
                calc.push(evaluate(a, b, operators.pop()));
            }
            operators.push(tokens[i][0]);
        } 
        
        else 
        {
            if(tokens[i]!=" ")calc.push(stof(tokens[i]));
        }
    }
    while (!operators.isEmpty()) 
    {
        float b = calc.pop(), a = calc.pop();
        calc.push(evaluate(a, b, operators.pop()));
    }
    return calc.peek();
}


float solveCompleteEquation(std::string equation) 
{
    Stack<float> st;
    for (int i = 0; i <equation.size(); ++i) 
    {
        if (equation[i] == '(') st.push(i);
        else if (equation[i] == ')') 
        {
            int beg =st.pop();
            std::string sub = equation.substr(beg + 1, i - beg - 1);
            std::string val = std::to_string(solveEquation(sub));
            equation.replace(beg, i - beg + 1, val);
            i = beg + val.size() - 1;
        }
    }
    return solveEquation(equation);
}   



int main() 
{

    cout<<solveCompleteEquation("12+13-5*(0.5+0.5) +1")<<endl;
    cout<<12+13-5*(0.5+0.5) +1;
    return 0;
}
