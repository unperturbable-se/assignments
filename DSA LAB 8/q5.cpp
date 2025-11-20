#include <iostream>
using namespace std;

struct Node
{
 int val;
 Node* left;
 Node* right;
 Node(int val):val{val},left{nullptr},right{nullptr}{}
};

bool isBST = true;

int checkBST(Node* root, int minVal = -9999, int maxVal = 9999)
{
 if(!root || !isBST) return 0;

 if(root->val <= minVal || root->val >= maxVal)
 {
  cout<<"Not a BST TREE\n";
  isBST = false;
  return 0;
 }

 checkBST(root->left, minVal, root->val);
 checkBST(root->right, root->val, maxVal);

 return root->val;
}


int main()
{
 isBST=true;

 // -------- Tree 1 ----------
 Node* root1 = new Node(2);
 root1->left = new Node(1);
 root1->right = new Node(3);
 root1->right->right = new Node(5);

 // -------- Tree 2 ----------
 Node* root2 = new Node(10);
 root2->left = new Node(5);
 root2->right = new Node(20);
 root2->right->left = new Node(9);
 root2->right->right = new Node(25);

 cout<<"Root 1 is ";
 checkBST(root1);

 if(isBST) cout<<"a BST TREE\n";

 cout<<"Root 2 is ";
 checkBST(root2);

 if(isBST) cout<<"a BST TREE\n";

 return 0;
}
