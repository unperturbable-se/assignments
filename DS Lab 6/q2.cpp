#include <iostream>
#include <cstdlib>

using namespace std;

struct Transaction
{
    int id;
    double amount;
    string description;
    int flag;
};

struct Node
{
    Transaction data;
    Node* next;
};

class TransactionStack
{
private:
    Node* top;
    int nextId;

public:
    TransactionStack()
    {
        top = NULL;
        nextId = 1;
    }

    string trimDescription(string desc)
    {
        if (desc.length() <= 20)
        {
            return desc;
        }
        return desc.substr(0, 17) + "...";
    }

    double applyDiscount(double amt)
    {
        if (amt >= 1500)
        {
            return amt * 0.7;
        }
        else if (amt >= 1000)
        {
            return amt * 0.85;
        }
        else if (amt >= 500)
        {
            return amt * 0.95;
        }
        return amt;
    }

    void push(double amt, string desc)
    {
        Transaction t;
        t.id = nextId++;
        t.description = trimDescription(desc);

        if (amt >= 0)
        {
            t.amount = applyDiscount(amt);
            t.flag = 1;
        }
        else
        {
            t.amount = amt;
            t.flag = 0;
        }

        Node* newNode = new Node;
        newNode->data = t;
        newNode->next = top;
        top = newNode;
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    Transaction pop()
    {
        if (isEmpty())
        {
            exit(1);
        }

        Node* temp = top;
        top = top->next;
        Transaction t = temp->data;

        t.amount *= -1;
        t.description += " [REVERSED]";
        t.flag = 2;

        delete temp;
        return t;
    }

    void display()
    {
        Node* curr = top;
        cout << "Top ->";
        while (curr != NULL)
        {
            cout << " [id=" << curr->data.id
                 << ", amt=" << curr->data.amount
                 << ", desc=\"" << curr->data.description
                 << "\", flag=" << curr->data.flag << "]";
            curr = curr->next;
        }
        cout << " Bottom" << endl;
    }
};

struct ExpressionStack
{
    double arr[100];
    int top;

    ExpressionStack()
    {
        top = -1;
    }

    void push(double val)
    {
        arr[++top] = val;
    }

    double pop()
    {
        return arr[top--];
    }

    double peek()
    {
        return arr[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

int precedence(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    if (op == '*' || op == '/')
    {
        return 2;
    }
    return 0;
}

bool isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

string infixToPostfix(string expr)
{
    string postfix = "";
    ExpressionStack opStack;

    for (int i = 0; i < expr.length(); i++)
    {
        char ch = expr[i];

        if (ch == ' ')
        {
            continue;
        }

        if (isdigit(ch) || ch == '.')
        {
            while (i < expr.length() && (isdigit(expr[i]) || expr[i] == '.'))
            {
                postfix += expr[i++];
            }
            postfix += ' ';
            i--;
        }
        else if (ch == '(')
        {
            opStack.push(ch);
        }
        else if (ch == ')')
        {
            while (!opStack.isEmpty() && opStack.peek() != '(')
            {
                postfix += (char)opStack.pop();
                postfix += ' ';
            }
            opStack.pop();
        }
        else if (isOperator(ch))
        {
            while (!opStack.isEmpty() && precedence(opStack.peek()) >= precedence(ch))
            {
                postfix += (char)opStack.pop();
                postfix += ' ';
            }
            opStack.push(ch);
        }
    }

    while (!opStack.isEmpty())
    {
        postfix += (char)opStack.pop();
        postfix += ' ';
    }

    return postfix;
}

double evaluatePostfix(string postfix)
{
    ExpressionStack valStack;

    for (int i = 0; i < postfix.length(); i++)
    {
        char ch = postfix[i];

        if (ch == ' ')
        {
            continue;
        }

        if (isdigit(ch) || ch == '.')
        {
            string num = "";
            while (i < postfix.length() && (isdigit(postfix[i]) || postfix[i] == '.'))
            {
                num += postfix[i++];
            }
            i--;
            valStack.push(atof(num.c_str()));
        }
        else if (isOperator(ch))
        {
            double b = valStack.pop();
            double a = valStack.pop();
            double result;

            if (ch == '+')
            {
                result = a + b;
            }
            else if (ch == '-')
            {
                result = a - b;
            }
            else if (ch == '*')
            {
                result = a * b;
            }
            else
            {
                result = a / b;
            }

            valStack.push(result);
        }
    }

    return valStack.pop();
}

int main()
{
    srand(time(0));

    TransactionStack stack;

    Transaction transactions[7] =
    {
        {0, 1200, "Sale: Blue Jacket", 0},
        {0, 450, "Sale: Cotton Socks", 0},
        {0, -300, "Refund: Defective Shirt", 0},
        {0, 1700, "Sale: Leather Jacket", 0},
        {0, 250, "Sale: Pen Set", 0},
        {0, -100, "Refund: Size Issue", 0},
        {0, 999, "Sale: Handbag - Premium Leather", 0}
    };

    for (int i = 0; i < 4; i++)
    {
        int idx = rand() % 7;
        stack.push(transactions[idx].amount, transactions[idx].description);
    }

    cout << "Pushed Transactions:" << endl;
    stack.display();

    string expr = "(100 + 20) * 0.9 - 5";
    string postfix = infixToPostfix(expr);
    double result = evaluatePostfix(postfix);

    cout << endl;
    cout << "Intermediate Expression Calculation:" << endl;
    cout << "Infix: " << expr << endl;
    cout << "Postfix: " << postfix << endl;
    cout << "Evaluated Result: " << result << endl;

    cout << endl;
    cout << "Pop (remove) one transaction:" << endl;
    Transaction popped = stack.pop();
    cout << "Popped Transaction: " << popped.description << endl;
    cout << "Amount changed to: " << popped.amount << endl;
    cout << "Flag updated to: " << popped.flag << endl;

    cout << endl;
    cout << "Final Stack Output:" << endl;
    stack.display();

    return 0;
}
