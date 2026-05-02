#include <iostream>
using namespace std;

struct Student
{
    int roll;
    string name;
    bool occupied;
    Student()
    : roll(0), name(""), occupied(false)
    {
    }
};

class StudentHashTable
{
    Student table[15];

    int hashFunction(int roll)
    {
        return roll % 15;
    }

public:
    void InsertRecord(int roll, string name)
    {
        int index = hashFunction(roll);
        int attempt = 0;

        while (attempt < 15)
        {
            int newIndex = (index + attempt * attempt) % 15;

            if (!table[newIndex].occupied)
            {
                table[newIndex].roll = roll;
                table[newIndex].name = name;
                table[newIndex].occupied = true;
                return;
            }

            attempt++;
        }
    }

    void SearchRecord(int roll)
    {
        int index = hashFunction(roll);
        int attempt = 0;

        while (attempt < 15)
        {
            int newIndex = (index + attempt * attempt) % 15;

            if (table[newIndex].occupied && table[newIndex].roll == roll)
            {
                cout << table[newIndex].name << endl;
                return;
            }

            if (!table[newIndex].occupied)
            {
                break;
            }

            attempt++;
        }

        cout << "Record not found" << endl;
    }
};

int main()
{
    StudentHashTable ht;

    ht.InsertRecord(101, "Alice");
    ht.InsertRecord(116, "Bob");
    ht.InsertRecord(131, "Charlie");

    ht.SearchRecord(116);
    ht.SearchRecord(999);

    return 0;
}
