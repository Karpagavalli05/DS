
#include <iostream>
using namespace std;

#define SIZE 10

int table[SIZE];

void initialize() {
    for (int i = 0; i < SIZE; i++) {
        table[i] = -1;
    }
}

void INSERT(int x) {
    int index = x % SIZE;
    int start = index;

    do {
        if (table[index] == -1) {
            table[index] = x;
            cout << "Inserted successfully\n";
            return;
        }

        if (table[index] == x) {
            cout << "Account number already exists\n";
            return;
        }

        index = (index + 1) % SIZE;

    } while (index != start);

    cout << "Hash table is full\n";
}

void SEARCH(int x) {
    int index = x % SIZE;
    int start = index;

    do {
        if (table[index] == x) {
            cout << "Account number found at index "
                 << index << "\n";
            return;
        }

        if (table[index] == -1) {
            cout << "Account number not found\n";
            return;
        }

        index = (index + 1) % SIZE;

    } while (index != start);

    cout << "Account number not found\n";
}

void DISPLAY() {
    cout << "\nIndex\tAccount Number\n";

    for (int i = 0; i < SIZE; i++) {
        cout << i << "\t";

        if (table[i] == -1)
            cout << "Empty";
        else
            cout << table[i];

        cout << "\n";
    }
}

int main() {
    initialize();

    int choice, x;

    do {
        cout << "\n1. INSERT";
        cout << "\n2. SEARCH";
        cout << "\n3. DISPLAY";
        cout << "\n4. EXIT";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter account number: ";
                cin >> x;
                INSERT(x);
                break;

            case 2:
                cout << "Enter account number to search: ";
                cin >> x;
                SEARCH(x);
                break;

            case 3:
                DISPLAY();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 4);

    return 0;
}
