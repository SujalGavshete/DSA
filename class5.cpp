#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST
{
private:
    Node *root;
    Node *insert(Node *root, int value)
    {
        if (root == NULL)
        {
            return new Node(value);
        }
        if (value < root->data)
        {
            root->left = insert(root->left, value);
        }
        else if (value > root->data)
        {
            root->right = insert(root->right, value);
        }
        else
        {
            cout << "\nDuplicate value not inserted.\n";
        }
        return root;
    }

public:
    BST()
    {
        root = NULL;
    }
    void createBST()
    {
        int n, value;
        cout << "\nEnter number of nodes:";
        cin >> n;
        cout << "\nEnter node value:";
        for (int i = 1; i <= n; i++)
        {
            cin >> value;
            root = insert(root, value);
        }
    }
    void inorderNonRecursive()
    {
        stack<Node *> S;
        Node *current = root;
        cout << "\nNon-Recursive Inorder Treversal.";
        while (current != NULL || !S.empty())
        {
            while (current != NULL)
            {
                S.push(current);
                current = current->left;
            }
            current = S.top();
            S.pop();
            cout << current->data << " ";
            current = current->right;
        }
    }
    

    void preordeNonRecursive()
    {
        if (root == NULL)
        {
            return;
        }
        stack<Node *> S;
        S.push(root);
        cout << "\nNon-Recursive Preorde Treversal.";

        while (!S.empty())
        {
            Node *current = S.top();
            S.pop();
            cout << current->data << " ";
            if (current->right != NULL)
                S.push(current->right);
            if (current->left != NULL)
                S.push(current->left);
        }
    }
};

int main()
{
    BST tree;
        int choice;
    do
    {

        cout << "\n========Binary Search Tree========" << endl;
        cout << "\n1.create Binary Search Tree " << endl;
        cout << "\n2.inorder Non Recursive Traversal" << endl;
        cout << "\n3.preorde Non Recursive Traversal" << endl;
        cout << "\n4.Exit" << endl;
        cout << "Enter your Choice :-";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
           tree.createBST();
            break;
        case 2:
            tree.inorderNonRecursive();
            break;
        case 3:
            tree.preordeNonRecursive();
            break;
        case 4:
            cout << "exit" << endl;
            break;
        default:
            cout << "Invalid Input" << endl;
            break;
        }
    } while (choice != 4);
    return 0;
}
