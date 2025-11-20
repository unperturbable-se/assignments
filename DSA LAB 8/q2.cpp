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

  Node<T>* search(Node<T>*& r,T val)
  {
    if(r==nullptr)return nullptr;
    if(r->val==val)return r;
    else if(val<r->val)return search(r->left,val);
    else return search(r->right,val);
  } 

   void insert(T val,Node<T>*& r)
   {
    if(!r){r=new Node<T>(val);return;}
    if(val>r->val)insert(val,r->right);
    else insert(val,r->left);
   }

   bool deleteVal(Node<T>*& node,T val)
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
       Node<T>* curr=node->right;
       while(curr->left)curr=curr->left;
       T newVal=curr->val;
       node->val=newVal;
       deleteVal(node->right,newVal);
       //option2:delete largest node in the left subtree(not implemented)
     }
     else if(node->left)
     {
        Node<T>* temp=node;
        node=node->left;
        delete temp;
     }

     else if(node->right)
     {
       Node<T>* temp=node;
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
   void deleteNode(T val){deleteVal(root,val);} 
   void insert(T val){insert(val,root);}
   void display(){display(root);}
   Node<T>* search(T val){return search(root,val);}
   T* findSmallest()
   {
     Node<T>* curr=root;
     if(!curr)return nullptr;
     while(curr->left)curr=curr->left;
     return &(curr->val);
   }
   bool isEmpty(){return root==nullptr;}
 };

 class Combatant
 {
   string name;
   int hp;
   int attack;
   public:

   bool isDead(){return hp<=0;}
   bool operator<(Combatant& b)
   {
    return attack<b.attack;
   }

   bool operator>(Combatant& b)
   {
    return attack>b.attack;
   }

   bool operator=(Combatant& b)
   {
    return attack=b.attack;
   }

   bool operator!=(Combatant& b)
   {
    return attack!=b.attack;
   }

   void display()
   {
    cout<<"Name:"<<name<<endl;
    cout<<"Attack:"<<attack<<endl;
    cout<<"Health:"<<hp<<endl;
   } 
   
   void hit(Combatant& b)
   {
    b.hp-=attack;
   }
   Combatant(string name,int attack,int hp):name{name},attack{attack},hp{hp}{};
 };

 int main()
{
  BST<Combatant> heroes;
  BST<Combatant> enemies;

  heroes.insert({"Alex",21,60});
  heroes.insert({"Peter",30,70});
  heroes.insert({"James",10,60});
  heroes.insert({"Bob",91,100});
  heroes.insert({"Alin",88,90});
  heroes.insert({"Brine",12,60});

  enemies.insert({"Alon",21,60});
  enemies.insert({"Pete",30,70});
  enemies.insert({"Jameson",10,60});
  enemies.insert({"Bobby",91,100});
  enemies.insert({"linay",88,90});
  enemies.insert({"Bronks",12,60});

  int turn=0;
  Combatant* currentHero = heroes.findSmallest();
  Combatant* currentEnemy = enemies.findSmallest();

  while(!heroes.isEmpty() && !enemies.isEmpty())
  {
    cout<<"BST BATTLE ARENA!!!\n";

    if(turn%2==0) //heroes
    {
      cout<<"The heroes are attacking\n";
      cout<<"Current Hero:"<<endl;

      if(currentHero==nullptr || currentHero->isDead()) currentHero=heroes.findSmallest();
      currentHero->display();

      if(currentEnemy==nullptr || currentEnemy->isDead()) currentEnemy=enemies.findSmallest();
      cout<<"Current Enemy:"<<endl;
      currentEnemy->display();

      currentHero->hit(*currentEnemy);

      if(currentEnemy->isDead())
      {
        cout<<"Enemy is dead\n";
        enemies.deleteNode(*currentEnemy);
        currentEnemy = enemies.findSmallest();
      }
    }

    else //enemies
    {
      cout<<"The enemies are attacking\n";
      cout<<"Current Enemy:"<<endl;

      if(currentEnemy==nullptr || currentEnemy->isDead()) currentEnemy=enemies.findSmallest();
      currentEnemy->display();

      if(currentHero==nullptr || currentHero->isDead()) currentHero=heroes.findSmallest();
      cout<<"Current Hero:"<<endl;
      currentHero->display();

      currentEnemy->hit(*currentHero);

      if(currentHero->isDead())
      {
        cout<<"Oops! the hero died\n";
        heroes.deleteNode(*currentHero);
        currentHero = heroes.findSmallest();
      }
    }

    turn++;
  }

  if(enemies.isEmpty()) cout<<"Heroes won";
  else cout<<"Enemies won";

  return 0;
}
