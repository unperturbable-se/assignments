#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Node
{
    int val;
    Node* left=nullptr;
    Node* right=nullptr;
    
    int height()
    {
        int x=0,y=0;
        if(left)x=left->height();
        if(right)y=right->height();
        return 1+max(x,y);
    }

    int balance()
    {
        int x=0,y=0;
        if(left)x=left->height();
        if(right)y=right->height();
        return x-y;
    }
    
    Node(int val):val{val}{};
};

class AVL
{
private:
    Node* root=nullptr;
  
    void right_rotate(Node*& a)
    {
        cout << "  (Performing Right-Rotate on " << a->val << ")" << endl;
        Node* b=a->left;
        Node* c=b->right;
        
        b->right=a;
        a->left=c;
        a=b;
    }

    void left_rotate(Node*& a)
    {
        cout << "  (Performing Left-Rotate on " << a->val << ")" << endl;
        Node* b=a->right;
        Node* c=b->left;
        
        b->left=a;
        a->right=c;
        a=b;
    }

    void left_right_rotate(Node*&a)
    {
        cout << "  (Performing Left-Right-Rotate on " << a->val << ")" << endl;
        left_rotate(a->left);
        right_rotate(a);
    }

    void right_left_rotate(Node*&a)
    {
        cout << "  (Performing Right-Left-Rotate on " << a->val << ")" << endl;
        right_rotate(a->right);
        left_rotate(a);
    }

    void balanceNode(Node*& a)
    {
        if(!a)return;
        int balance=a->balance();
        
        if(balance>1)
        {
            if(a->left&&a->left->balance()>=0)right_rotate(a);
            else left_right_rotate(a);
        }
        else if(balance<-1)
        {
            if(a->right&&a->right->balance()<=0)left_rotate(a);
            else right_left_rotate(a);
        }
    }

    void display(Node* a)
    {
        if(!a)return;
        display(a->left);
        cout<<a->val << " ";
        display(a->right);
    }

    void insert(int val,Node*& a)
    {
        if(!a){a=new Node{val};return;}
        if(val<a->val)insert(val,a->left);
        else insert(val,a->right);
        
        balanceNode(a);
    }

    void prettyPrint(Node* node, string indent, bool last) {
        if (node != nullptr) {
            cout << indent;
            if (last) {
                cout << "R----";
                indent += "     ";
            } else {
                cout << "L----";
                indent += "|    ";
            }
            cout << node->val << endl;
            prettyPrint(node->left, indent, false);
            prettyPrint(node->right, indent, true);
        }
    }


public:
    void insert(int val) {
        cout << "Inserting " << val << "..." << endl;
        insert(val, root);
    }
    
    void display() {
        cout << "In-order traversal: ";
        display(root);
        cout << endl;
    }
    
    void prettyPrint() {
        prettyPrint(root, "", true);
    }
    
    void forceLeftRotateOnRoot() {
        cout << "\n--- Forcing Left Rotation on Root ---" << endl;
        if (root && root->right) {
            left_rotate(root);
        } else if (root) {
            cout << "  (Cannot left-rotate root: no right child)" << endl;
        }
    }
};


int main()
{
    AVL tree;
    
    int initial_nodes[] = {50, 30, 70, 20, 40, 60, 80};
    cout << "--- Building Initial Tree ---" << endl;
    for (int val : initial_nodes) {
        tree.insert(val);
    }
    
    cout << "\n--- Tree After Initial Insertions ---" << endl;
    tree.prettyPrint();

    cout << "\n--- Inserting Node 55 ---" << endl;
    tree.insert(55);
    
    cout << "\n--- Tree After Inserting 55 ---" << endl;
    tree.prettyPrint();

    tree.forceLeftRotateOnRoot();

    cout << "\n--- Final Tree Structure (After Rotation) ---" << endl;
    tree.prettyPrint();
    
    cout << "\n--- Final In-order Traversal ---" << endl;
    tree.display();
    
    return 0;
}