#include <iostream>
using namespace std;

template<typename T>
struct Node
{
 T val;
 Node<T>* left;
 Node<T>* right;
 Node(T val):val{val},left{nullptr},right{nullptr}{}
};

template<typename T>
class BST
{
 Node<T>* root=nullptr;

 void display(Node<T>*& r)
 {
  if(r==nullptr)return;
  display(r->left);
  cout<<r->val<<" ";
  display(r->right);
 }

 Node<T>* search(Node<T>*& r,const T &val)
 {
  if(r==nullptr)return nullptr;
  if(r->val==val)return r;
  else if(val<r->val)return search(r->left,val);
  else return search(r->right,val);
 } 

 void insert(const T &val,Node<T>*& r)
 {
  if(!r){r=new Node<T>(val);return;}
  if(val>r->val)insert(val,r->right);
  else if(val<r->val)insert(val,r->left);
  // If val == r->val, do nothing or update if needed, here we do nothing
 }

 // Recursive helper to count nodes in range
 int countInRange(Node<T>* node, int a, int b)
 {
  if(!node) return 0;

  // If node value is smaller than a, then skip left subtree
  if(node->val < a)
   return countInRange(node->right, a, b);

  // If node value is greater than b, skip right subtree
  if(node->val > b)
   return countInRange(node->left, a, b);

  // Node is in range, count it + left + right
  return 1 + countInRange(node->left, a, b) + countInRange(node->right, a, b);
 }

 public:
 void insert(const T &val){insert(val,root);}
 Node<T>* search(const T &val){return search(root,val);}
 void display(){display(root);}
 bool isEmpty(){return root==nullptr;}

 int countInRange(int a, int b)
 {
  return countInRange(root, a, b);
 }
};

int main()
{
    BST<int> a;
    a.insert(1);
    a.insert(5);
    a.insert(10);
    a.insert(50);
    a.insert(40);
    a.insert(100);

    int low=5, high=45;
    cout << "Number of nodes in range [" << low << ", " << high << "] : " << a.countInRange(low, high) << endl;

    return 0;
}
