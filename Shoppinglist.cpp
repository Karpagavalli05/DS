
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<string> shoppinglist;
    int choice;
    string item;

    do
    {
        cout << "\n--- Shopping List Menu ---\n";
        cout << "1. Add an item\n";
        cout << "2. Remove an item\n";
        cout << "3. Search for an item\n";
        cout << "4. Display all items\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter item to add: ";
            cin >> item;
            shoppinglist.push_back(item);
            cout << "Item added successfully.\n";
            break;

        case 2:
        {
            cout << "Enter item to remove: ";
            cin >> item;

            bool found = false;

            for (int i = 0; i < shoppinglist.size(); i++)
            {
                if (shoppinglist[i] == item)
                {
                    shoppinglist.erase(shoppinglist.begin() + i);
                    cout << "Item removed successfully.\n";
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Item not found.\n";

            break;
        }

        case 3:
        {
            cout << "Enter item to search: ";
            cin >> item;

            bool found = false;

            for (int i = 0; i < shoppinglist.size(); i++)
            {
                if (shoppinglist[i] == item)
                {
                    cout << "Item found in the shopping list.\n";
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Item not found.\n";

            break;
        }

        case 4:
            if (shoppinglist.empty())
            {
                cout << "Shopping list is empty.\n";
            }
            else
            {
                cout << "\nShopping List:\n";

                for (int i = 0; i < shoppinglist.size(); i++)
                {
                    cout << i + 1 << ". " << shoppinglist[i] << endl;
                }
            }
            break;

        case 5:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
