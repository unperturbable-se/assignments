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


int precedence(char x)
{
    if(x=='+'||x=='-')return 0;    
    if(x=='*'||x=='/')return 1;    
    if(x=='^')return 2;   
    return -1; 
}

bool isVariable(char x)
{
    return (x>='a'&&x<='z'||x>='A'&&x<='Z'||x>='0'&&x<='9');
}

string infixToPostfix(string input) //non-bracket implementation
{
 Stack<char> st;
 string output="";
 for (char character:input)
 {
   if(isVariable(character))output+=character;
   else if(character=='(')st.push(character);
   else if(character==')')
   {
    while(!st.isEmpty()&&st.peek()!='(')output+=st.pop();
    st.pop();
   }
   else if(st.isEmpty())st.push(character);
   else if(precedence(character) > precedence(st.peek()))st.push(character);
   else 
   {
    int x=precedence(character);
    if(character=='^')while(!isVariable(st.peek())&&precedence(st.peek())>x)output+=st.pop();
    else while(!isVariable(st.peek())&&precedence(st.peek())>=x)output+=st.pop();
    st.push(character);
   }
 }
 while(!st.isEmpty())output+=st.pop();
 return output;
}


int main() 
{
    string expression="((A+B)*C)-D/(E+F)";
        cout << "Infix: " << expression << endl;
        cout << "Postfix: " << infixToPostfix(expression) << endl;
    return 0;
}
