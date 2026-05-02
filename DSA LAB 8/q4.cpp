#include <iostream>
#include <string>
using namespace std;

struct Student
{
 string name;
 int roll;
 int score;

 void display()
 {
  cout<<"Name: "<<name<<"  Roll: "<<roll<<"  Score: "<<score<<endl;
 }

 bool operator<(const Student &other)const
 {
  return name < other.name;
 }

 bool operator>(const Student &other)const
 {
  return name > other.name;
 }

 bool operator==(const Student &other)const
 {
  return name == other.name;
 }
};

template <typename T>
class BST
{
 struct Node
 {
  T data;
  Node* left;
  Node* right;
  Node(const T &d):data(d),left(nullptr),right(nullptr){}
 };
 Node* root=nullptr;

 Node* insert(Node* node,const T &val)
 {
  if(node==nullptr) return new Node(val);
  if(val<node->data) node->left=insert(node->left,val);
  else if(val>node->data) node->right=insert(node->right,val);
  return node;
 }

 Node* search(Node* node,const string &name)
 {
  if(node==nullptr) return nullptr;
  if(node->data.name==name) return node;
  if(name<node->data.name) return search(node->left,name);
  else return search(node->right,name);
 }

 Node* findMin(Node* node)
 {
  while(node && node->left) node=node->left;
  return node;
 }

 Node* deleteScoreLessThan(Node* node,int score)
 {
  if(node==nullptr) return nullptr;
  node->left=deleteScoreLessThan(node->left,score);
  node->right=deleteScoreLessThan(node->right,score);
  if(node->data.score<score)
  {
   Node* temp;
   if(node->left==nullptr) temp=node->right;
   else if(node->right==nullptr) temp=node->left;
   else
   {
    Node* minRight=findMin(node->right);
    node->data=minRight->data;
    node->right=deleteScoreLessThan(node->right,score);
    return node;
   }
   delete node;
   return temp;
  }
  return node;
 }

 void findMaxScore(Node* node,T &maxVal,int &maxScore)
 {
  if(node==nullptr) return;
  if(node->data.score>maxScore)
  {
   maxScore=node->data.score;
   maxVal=node->data;
  }
  findMaxScore(node->left,maxVal,maxScore);
  findMaxScore(node->right,maxVal,maxScore);
 }

 void inorder(Node* node)
 {
  if(node==nullptr) return;
  inorder(node->left);
  node->data.display();
  inorder(node->right);
 }

public:
 void insert(const T &val){root=insert(root,val);}
 T* search(const string &name)
 {
  Node* n=search(root,name);
  if(n) return &n->data;
  return nullptr;
 }
 void deleteScoreLessThan(int score){root=deleteScoreLessThan(root,score);}
 T getMaxScoreStudent()
 {
  T maxVal;
  int maxScore=-9999;
  findMaxScore(root,maxVal,maxScore);
  return maxVal;
 }
 void displayAll(){inorder(root);}
 bool isEmpty(){return root==nullptr;}
};

int main()
{
 Student arr[10]={
  {"Alex",1,45},
  {"Bob",2,5},
  {"Cathy",3,75},
  {"David",4,9},
  {"Elen",5,55},
  {"Frank",6,88},
  {"George",7,92},
  {"Hilda",8,12},
  {"Irene",9,3},
  {"Jack",10,47}
 };

 BST<Student> tree;

 tree.insert(arr[0]);
 tree.insert(arr[2]);
 tree.insert(arr[3]);
 tree.insert(arr[5]);
 tree.insert(arr[6]);
 tree.insert(arr[7]);
 tree.insert(arr[9]);

 cout<<"All students in BST:\n";
 tree.displayAll();

 cout<<"\nSearching for 'Frank'\n";
 Student* s=tree.search("Frank");
 if(s) s->display();
 else cout<<"Not found\n";

 cout<<"\nDeleting students whose score < 10\n";
 tree.deleteScoreLessThan(10);
 tree.displayAll();

 cout<<"\nStudent with MAX score:\n";
 Student top=tree.getMaxScoreStudent();
 top.display();

 // -------------------------
 // Question #4
 // -------------------------
 cout<<"\n\nQuestion#4: Search user-defined value in tree.\n";
 string uname;
 cout<<"Enter student name to search: ";
 cin>>uname;

 Student* found = tree.search(uname);
 if(found)
 {
  cout<<"Student found:\n";
  found->display();
 }
 else
 {
  cout<<"Student not found, inserting new record.\n";
  Student newStu;
  newStu.name = uname;
  cout<<"Enter roll: ";
  cin>>newStu.roll;
  cout<<"Enter score: ";
  cin>>newStu.score;
  tree.insert(newStu);

  cout<<"\nNew tree after insertion:\n";
  tree.displayAll();
 }

 return 0;
}
