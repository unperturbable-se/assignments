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
  r->val.display();
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
  else
  {
    // already exists, update quantity
    r->val.quantity += val.quantity;
  }
 }

 void findMaxQuantity(Node<T>* r,T &maxProd,int &maxQty)
 {
  if(!r)return;
  if(r->val.quantity>maxQty)
  {
   maxQty=r->val.quantity;
   maxProd=r->val;
  }
  findMaxQuantity(r->left,maxProd,maxQty);
  findMaxQuantity(r->right,maxProd,maxQty);
 }

 public:
 void insert(const T &val){insert(val,root);}
 Node<T>* search(const T &val){return search(root,val);}
 void display(){display(root);}
 bool isEmpty(){return root==nullptr;}

 // find product with max quantity
 T getMaxQuantityProduct()
 {
  T maxProd;
  int maxQty=-1;
  findMaxQuantity(root,maxProd,maxQty);
  return maxProd;
 }
};

// ---------------------- Product Struct ----------------------

struct Product
{
 int id;
 int quantity;

 void display()const
 {
  cout<<"Product ID: "<<id<<"  Quantity: "<<quantity<<endl;
 }

 bool operator<(const Product &other)const
 {
  return id < other.id;
 }

 bool operator>(const Product &other)const
 {
  return id > other.id;
 }

 bool operator==(const Product &other)const
 {
  return id == other.id;
 }
};

// ---------------------- MAIN ----------------------

int main()
{
 BST<Product> inventory;

 Product p1{101,30};
 Product p2{55,10};
 Product p3{200,45};
 Product p4{150,5};
 Product p5{300,60};

 inventory.insert(p1);
 inventory.insert(p2);
 inventory.insert(p3);
 inventory.insert(p4);
 inventory.insert(p5);

 cout<<"All products in inventory (in-order):\n";
 inventory.display();

 cout<<"\nSearching for product ID 150:\n";
 Product target{150,0};
 Node<Product>* found = inventory.search(target);
 if(found) found->val.display();
 else cout<<"Product not found\n";

 cout<<"\nUpdating quantity of product ID 150 (adding 10 more)\n";
 inventory.insert({150,10}); // same ID, will update

 cout<<"Inventory after update:\n";
 inventory.display();

 cout<<"\nProduct with MAX quantity:\n";
 Product maxP = inventory.getMaxQuantityProduct();
 maxP.display();

 return 0;
}
