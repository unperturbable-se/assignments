#include <iostream>
using namespace std;

struct Node
{
    char val;
    Node* next;
    Node(char v) { val = v; next = nullptr; }
};

void deleteList(Node* head)
{
    Node* prev;
    while (head)
    {
        prev = head;
        head = head->next;
        delete prev;
    }
}

char getVal(Node* head, int pos)
{
    Node* curr = head;
    for (int i = 0; i < pos; i++) curr = curr->next;
    return curr->val;
}

void display(Node* head)
{
    Node* curr = head;
    while (curr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

bool checkPalindrome(Node* head)
{
    Node* curr = head;
    int length = 0;
    while (curr)
    {
        length++;
        curr = curr->next;
    }
    if (length < 2) return false;

    for (int i = 0; i < length / 2; i++)
    {
        if (getVal(head, i) != getVal(head, length - 1 - i))
            return false;
    }
    return true;
}


Node* stringToList(const string& str)
{
    if (str.empty()) return nullptr;

    Node* head = new Node(str[0]);
    Node* curr = head;
    for (int i = 1; i < str.size(); i++)
    {
        curr->next = new Node(str[i]);
        curr = curr->next;
    }
    return head;
}

int main()
{
    Node* str1 = stringToList("hello");
    Node* str2 = stringToList("abba");
    Node* str3 = stringToList("barb");
    Node* str4 = stringToList("appppa");
    Node* str5 = stringToList("aragog");
    Node* str6 = stringToList("duckcud");

    display(str1);
    cout << "Palindrome: " << (checkPalindrome(str1) ? "true\n" : "false\n");

    display(str2);
    cout << "Palindrome: " << (checkPalindrome(str2) ? "true\n" : "false\n");

    display(str3);
    cout << "Palindrome: " << (checkPalindrome(str3) ? "true\n" : "false\n");

    display(str4);
    cout << "Palindrome: " << (checkPalindrome(str4) ? "true\n" : "false\n");

    display(str5);
    cout << "Palindrome: " << (checkPalindrome(str5) ? "true\n" : "false\n");

    display(str6);
    cout << "Palindrome: " << (checkPalindrome(str6) ? "true\n" : "false\n");

    deleteList(str1);
    deleteList(str2);
    deleteList(str3);
    deleteList(str4);
    deleteList(str5);
    deleteList(str6);

    return 0;
}
