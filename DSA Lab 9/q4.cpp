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

    void findKthSmallest(Node* node, int& k, int& result) {
        if (!node) return;
            
        findKthSmallest(node->left, k, result);
        
        if (k == 0) return;
        
        k--;
        if (k == 0) {
            result = node->val;
            return;
        }
        
        findKthSmallest(node->right, k, result);
    }

    void findKthLargest(Node* node, int& k, int& result) {
        if (!node) return;
            
        findKthLargest(node->right, k, result);
        
        if (k == 0) return;
        
        k--;
        if (k == 0) {
            result = node->val;
            return;
        }
        
        findKthLargest(node->left, k, result);
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
    
    int getHeight() {
        if (!root) return 0;
        return root->height();
    }

    void printKthSmallest(int k) {
        if (k <= 0) {
            cout << "Invalid k: " << k << endl;
            return;
        }
        int k_copy = k;
        int result = -1;
        
        findKthSmallest(root, k, result);
        
        if (k == 0) {
            cout << k_copy << "th smallest key: " << result << endl;
        } else {
            cout << "K (" << k_copy << ") is larger than the number of nodes." << endl;
        }
    }

    void printKthLargest(int k) {
        if (k <= 0) {
            cout << "Invalid k: " << k << endl;
            return;
        }
        int k_copy = k;
        int result = -1;
        
        findKthLargest(root, k, result);
        
        if (k == 0) {
            cout << k_copy << "th largest key: " << result << endl;
        } else {
            cout << "K (" << k_copy << ") is larger than the number of nodes." << endl;
        }
    }

    void printRootSubtreeHeights() {
        if (!root) {
            cout << "Tree is empty." << endl;
            return;
        }
        
        int leftHeight = 0;
        if (root->left) {
            leftHeight = root->left->height();
        }
        
        int rightHeight = 0;
        if (root->right) {
            rightHeight = root->right->height();
        }
        
        cout << "Height of left side (subtree): " << leftHeight << endl;
        cout << "Height of right side (subtree): " << rightHeight << endl;
    }
};


int main()
{
    AVL tree;
    
    int initial_nodes[] = {10, 5, 15, 3, 7, 12};
    cout << "--- Building Tree ---" << endl;
    for (int val : initial_nodes) {
        tree.insert(val);
    }
    
    cout << "\n--- Final Tree Structure ---" << endl;
    tree.prettyPrint();

    cout << "\n--- K-th Value Search ---" << endl;
    tree.printKthSmallest(2);
    tree.printKthSmallest(5);
    
    cout << endl;
    tree.printKthLargest(1);
    tree.printKthLargest(3);

    cout << "\n--- Root Subtree Heights ---" << endl;
    tree.printRootSubtreeHeights();
    
    return 0;
}