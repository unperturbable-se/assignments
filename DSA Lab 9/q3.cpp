
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
    };


    int main()
    {
        AVL tree;
        
        int initial_nodes[] = {10, 5, 15, 3, 7};
        cout << "--- Building Initial Tree ---" << endl;
        for (int val : initial_nodes) {
            tree.insert(val);
        }
        
        cout << "\n--- Initial Tree Structure ---" << endl;
        tree.prettyPrint();

        cout << "\n--- Inserting Node 12 ---" << endl;
        tree.insert(12);
        
        cout << "\n--- Final Balanced AVL Tree ---" << endl;
        tree.prettyPrint();

        cout << "\n--- Final Tree Height ---" << endl;
        cout << "Height: " << tree.getHeight() << endl;
        
        return 0;
    }
