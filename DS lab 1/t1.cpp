#include <iostream>
using namespace std;

class BankAccount
{
    float balance;
    static int lastID;
    int id;
    public:
    BankAccount(float bal=0):balance{bal}  //acts as both default and parameterized constructor
    {
        id=lastID++;
    }

    BankAccount(BankAccount& a)
    {
     balance=a.balance;
     id=lastID++;
    }
    void display()
    {
        cout<<"---------------------\n";
        cout<<"ID:"<<id<<endl;
        cout<<"Balance:"<<balance<<endl;
    }
    void addBalance(float val){balance+=val;}
    void deductBalance(float val){balance-=val;}
};

int BankAccount::lastID = 0;

int main()
{
    BankAccount account1;
    account1.display();
    BankAccount account2(1000);
    account2.display();
    BankAccount account3(account2);
    account3.deductBalance(200);
    account3.display();
    account2.display();
    return 0;
}