/*
why avl? AVL trees are self-balancing, performing rotations to prevent the tree 
from becoming skewed (like a linked list).
This strict balancing guarantees that search, insertion, and deletion operations 
are always efficient, 
with a worst-case time complexity of $O(\log n)$.
*/

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
            cout << node->val << " (BF: " << node->balance() << ")" << endl;
            prettyPrint(node->left, indent, false);
            prettyPrint(node->right, indent, true);
        }
    }

    void convertToAVL(Node*& node) {
        if (!node) return;

        convertToAVL(node->left);
        convertToAVL(node->right);

        balanceNode(node);
    }


public:
    void insert(int val) {
        cout << "Inserting " << val << "..." << endl;
        insert(val, root);
    }
    
    void prettyPrint() {
        if(root) {
            prettyPrint(root, "", true);
        } else {
            cout << "Tree is empty." << endl;
        }
    }
    
    void convertBSTtoAVL() {
        convertToAVL(root);
    }
    
    void setRoot(Node* newRoot) {
        root = newRoot;
    }
};


int main()
{
    AVL treeA;
    
    cout << "--- CREATING UNBALANCED TREE A ---" << endl;
    
    Node* rootA = new Node(10);
    rootA->left = new Node(6);
    rootA->left->left = new Node(4);
    rootA->left->right = new Node(8);
    
    treeA.setRoot(rootA);
    treeA.prettyPrint();

    cout << "\n--- CONVERTING TREE A TO AVL ---" << endl;
    treeA.convertBSTtoAVL();
    treeA.prettyPrint();


    AVL treeB;
    cout << "\n\n--- CREATING UNBALANCED TREE B ---" << endl;
    
    Node* rootB = new Node(10);
    rootB->right = new Node(16);
    rootB->right->left = new Node(12);
    rootB->right->right = new Node(18);
    
    treeB.setRoot(rootB);
    treeB.prettyPrint();

    cout << "\n--- CONVERTING TREE B TO AVL ---" << endl;
    treeB.convertBSTtoAVL();
    treeB.prettyPrint();
    
    return 0;
}


/*
explanation: The code performs single left and right rotations. 
Temporary Node* pointers b and c hold subtrees during the swap. 
In left_rotate(), a is the unbalanced node (like x), 
b is its right child (like y), and c is b's left child (the middle subtree, t2). 
The lines b->left = a and a->right = c relink the nodes. 
The function uses a pointer-reference (Node*& a) to directly modify the caller's pointer. 
The final line a = b makes the original pointer (e.g., root) 
point to b, the new root of this balanced subtree.
*/