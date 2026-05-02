#include <iostream>
#include <list>
using namespace std;

class HashTable 
{
    list<string> buckets[10];

    int hashingFunction(string val)
    {
        int sum = 0;
        for (int i = 0; i < val.size(); i++)
            sum += val[i];
        return sum % 10;       
    }

public:
    void insert(string val)
    {
        buckets[hashingFunction(val)].push_back(val);
    }

    void deleteVal(string val)
    {
        int index = hashingFunction(val);
        buckets[index].remove(val);
    }

    void search(string val)
    {
        int index = hashingFunction(val);
        bool found=false;
        for(string element:buckets[index])
            if(val==element)
               {found=true;break;}

        if (!found) cout << "not found\n";
        else cout << "found\n";
    }

    void display()
    {
        for (int i = 0; i < 10; i++)
        {
            cout << "Bucket " << i << ": ";
            for (auto &val : buckets[i])
                cout << val << " -> ";
            cout << "NULL\n";
        }
    }
};

int main()
{
    HashTable ht;

    ht.insert("apple");
    ht.insert("banana");
    ht.insert("cat");

    cout << "Initial table:\n";
    ht.display();

    cout << "\nSearching for 'banana': ";
    ht.search("banana");

    cout << "Deleting 'apple'\n";
    ht.deleteVal("apple");

    cout << "\nTable after deletion:\n";
    ht.display();

    return 0;
}
