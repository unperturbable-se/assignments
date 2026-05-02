#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string name;
    Node* next;
};

void reserve(Node*& head, const string& name)
{
    Node* newNode = new Node{name, nullptr};

    if (!head || name < head->name)
    {
        if (head && head->name == name)
        {
            cout << "Reservation already exists.\n";
            delete newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
        cout << "Ticket reserved for " << name << ".\n";
        return;
    }

    Node* curr = head;
    while (curr->next && curr->next->name < name)
    {
        curr = curr->next;
    }

    if ((curr->name == name) || (curr->next && curr->next->name == name))
    {
        cout << "Reservation already exists.\n";
        delete newNode;
        return;
    }

    newNode->next = curr->next;
    curr->next = newNode;
    cout << "Ticket reserved for " << name << ".\n";
}

void cancel(Node*& head, const string& name)
{
    if (!head)
    {
        cout << "No reservations to cancel.\n";
        return;
    }

    if (head->name == name)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Reservation cancelled for " << name << ".\n";
        return;
    }

    Node* curr = head;
    while (curr->next && curr->next->name != name)
    {
        curr = curr->next;
    }

    if (curr->next && curr->next->name == name)
    {
        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
        cout << "Reservation cancelled for " << name << ".\n";
    }
    else
    {
        cout << "Reservation not found.\n";
    }
}

void check(Node* head, const string& name)
{
    while (head)
    {
        if (head->name == name)
        {
            cout << name << " has a reservation.\n";
            return;
        }
        head = head->next;
    }
    cout << name << " does not have a reservation.\n";
}

void display(Node* head)
{
    if (!head)
    {
        cout << "No passengers.\n";
        return;
    }

    cout << "Passenger List:\n";
    while (head)
    {
        cout << "- " << head->name << "\n";
        head = head->next;
    }
}

void cleanup(Node*& head)
{
    while (head)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    Node* passengerList = nullptr;
    int choice;
    string name;

    do
    {
        cout << "\n--- Airline Reservation Menu ---\n";
        cout << "1. Reserve a ticket\n";
        cout << "2. Cancel a reservation\n";
        cout << "3. Check reservation\n";
        cout << "4. Display passengers\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
            case 1:
            {
                cout << "Enter name to reserve: ";
                getline(cin, name);
                reserve(passengerList, name);
                break;
            }
            case 2:
            {
                cout << "Enter name to cancel: ";
                getline(cin, name);
                cancel(passengerList, name);
                break;
            }
            case 3:
            {
                cout << "Enter name to check: ";
                getline(cin, name);
                check(passengerList, name);
                break;
            }
            case 4:
            {
                display(passengerList);
                break;
            }
            case 5:
            {
                cleanup(passengerList);
                cout << "Exiting...\n";
                break;
            }
            default:
            {
                cout << "Invalid option.\n";
            }
        }
    }
    while (choice != 5);

    return 0;
}
