
#include <iostream>
using namespace std;

struct Node
{
    int id;
    Node* left;
    Node* right;
};

Node* createNode(int value)
{
    Node* newNode = new Node;
    newNode->id = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->id)
        root->left = insert(root->left, value);
    else if (value > root->id)
        root->right = insert(root->right, value);

    return root;
}

void inorder(Node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->id << " ";
        inorder(root->right);
    }
}

int main()
{
    Node* root = NULL;
    int ids[] = {50, 30, 70, 20, 40, 60, 80};

    for (int i = 0; i < 7; i++)
        root = insert(root, ids[i]);

    cout << "Employee IDs in BST (Inorder): ";
    inorder(root);

    cout << endl;
    return 0;
}
