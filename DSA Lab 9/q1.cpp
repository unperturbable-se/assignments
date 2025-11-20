#include <iostream>
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
  Node* root=nullptr;
  
  void right_rotate(Node*& a)
  {
    Node* b=a->left;
    Node* c=b->right;
    
    b->right=a;
    a->left=c;
    a=b;
  }

  void left_rotate(Node*& a)
  {
    Node* b=a->right;
    Node* c=b->left;
    
    b->left=a;
    a->right=c;
    a=b;
  }

  void left_right_rotate(Node*&a)
  {
    left_rotate(a->left);
    right_rotate(a);
  }

  void right_left_rotate(Node*&a)
  {
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

public:
    void insert(int val) {
        insert(val, root);
    }
    
    void display() {
        display(root);
        cout << endl;
    }
    int getHeight() {
        if (!root) return 0;
        return root->height();
    }
};

int main()
{
    AVL tree;
    
    cout << "--- Building Initial Tree ---" << endl;
    
    tree.insert(10);
    tree.insert(20);
    tree.insert(30); 
    tree.insert(40);
    tree.insert(50); 

    cout << "Initial tree (in-order traversal): ";
    tree.display();
    cout << "Initial tree height (as built): " << tree.getHeight() << endl;

    cout << "\n--- Inserting Roll Number 15 ---" << endl;
    
    tree.insert(15);
    
    cout << "Final tree (in-order traversal): ";
    tree.display();
    
    cout << "Final height of the AVL tree: " << tree.getHeight() << endl;
    
    return 0;
}