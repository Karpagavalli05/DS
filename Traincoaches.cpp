#include <iostream>
using namespace std;

struct Node
{
    int coach;
    Node* next;
};

Node* head = NULL;

void addBeginning(int n)
{
    Node* newNode = new Node();
    newNode->coach = n;
    newNode->next = head;
    head = newNode;
}

void addEnd(int n)
{
    Node* newNode = new Node();
    newNode->coach = n;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void removeCoach(int n)
{
    if (head == NULL)
    {
        cout << "Train is empty.\n";
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL && temp->coach != n)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Coach not found.\n";
        return;
    }

    if (prev == NULL)
    {
        head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    delete temp;
    cout << "Coach removed successfully.\n";
}

void display()
{
    if (head == NULL)
    {
        cout << "Train is empty.\n";
        return;
    }

    Node* temp = head;

    cout << "Train Coaches: ";

    while (temp != NULL)
    {
        cout << "Coach" << temp->coach << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

int main()
{
    int choice, n;

    do
    {
        cout << "\n--- Train Coach Menu ---\n";
        cout << "1. Add coach at beginning\n";
        cout << "2. Add coach at end\n";
        cout << "3. Remove a coach\n";
        cout << "4. Display all coaches\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter coach number: ";
                cin >> n;
                addBeginning(n);
                break;

            case 2:
                cout << "Enter coach number: ";
                cin >> n;
                addEnd(n);
                break;

            case 3:
                cout << "Enter coach number to remove: ";
                cin >> n;
                removeCoach(n);
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}
