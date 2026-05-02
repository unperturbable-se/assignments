#include <iostream>
using namespace std;

struct Node
{
    int a;
    int b;
    Node *next;
    Node(int a, int b)
    : a(a), b(b), next(nullptr)
    {
    }
};

class HashTable
{
    Node* buckets[1000];

    int hashFunction(int sum)
    {
        return sum % 1000;
    }

public:
    HashTable()
    {
        for (int i = 0; i < 1000; i++)
        {
            buckets[i] = nullptr;
        }
    }

    bool insertAndCheck(int a, int b, int &x1, int &y1, int &x2, int &y2)
    {
        int sum = a + b;
        int idx = hashFunction(sum);

        Node *t = buckets[idx];
        while (t)
        {
            if (t->a != a && t->a != b && t->b != a && t->b != b)
            {
                x1 = t->a;
                y1 = t->b;
                x2 = a;
                y2 = b;
                return true;
            }
            t = t->next;
        }

        Node *n = new Node(a, b);
        n->next = buckets[idx];
        buckets[idx] = n;

        return false;
    }
};

void findPairs(int arr[], int n)
{
    HashTable ht;
    int a1, b1, a2, b2;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ht.insertAndCheck(arr[i], arr[j], a1, b1, a2, b2))
            {
                cout << "(" << a1 << ", " << b1 << ") and (" << a2 << ", " << b2 << ")" << endl;
                return;
            }
        }
    }

    cout << "No pairs found" << endl;
}

int main()
{
    int arr1[] = {3, 4, 7, 1, 2, 9, 8};
    int arr2[] = {3, 4, 7, 1, 12, 9};
    int arr3[] = {65, 30, 7, 90, 1, 9, 8};

    findPairs(arr1, 7);
    findPairs(arr2, 6);
    findPairs(arr3, 7);

    return 0;
}
