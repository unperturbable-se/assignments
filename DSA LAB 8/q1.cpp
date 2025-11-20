#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
    Node(int val):val{val},left{nullptr},right{nullptr}{}
};

class BST
{
  Node* root=nullptr;
  
  void display(Node*& r)
  {
    if(r==nullptr)return;
    display(r->left);
    cout<<r->val<<" ";
    display(r->right);
  }

   void insert(int val,Node*& r)
   {
    if(!r){r=new Node(val);return;}
    if(val>r->val)insert(val,r->right);
    else insert(val,r->left);
   }

   bool deleteVal(Node*& node,int val)
   {
     if(!node)return false;
     if(node->val != val) 
     {
        if(val>node->val)return deleteVal(node->right,val);
        else return deleteVal(node->left,val);
     }

     if(node->left && node->right)
     {
       //option1:delete smallest node in the right subtree
       Node* curr=node->right;
       while(curr->left)curr=curr->left;
       int newVal=curr->val;
       node->val=newVal;
       deleteVal(node->right,newVal);
       //option2:delete largest node in the left subtree(not implemented)
     }
     else if(node->left)
     {
        Node* temp=node;
        node=node->left;
        delete temp;
     }

     else if(node->right)
     {
       Node* temp=node;
       node=node->right;
       delete temp;
     }

     else 
     {
        delete node;
        node=nullptr;
     }
     return true;
   }

  public:
  void deleteNode(int val){deleteVal(root,val);} 
  void insert(int val){insert(val,root);}
  void display(){display(root);}
};

int main()
{
    BST binaryST;
    binaryST.insert(0);
    binaryST.insert(14);
    binaryST.insert(75);
    binaryST.insert(11);
    binaryST.insert(76);
    binaryST.insert(111);
    binaryST.insert(907);
    binaryST.insert(1213);
    binaryST.insert(1000);
    
    binaryST.deleteNode(76);
    binaryST.display();
    return 0;
}