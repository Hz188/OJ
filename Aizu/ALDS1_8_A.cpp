#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int key;
    Node *parent;
    Node *left;
    Node *right;
};

Node *root, *NIL;

//向以node为根的BST插入key的结点
void insert(int value)
{
    Node *node = root;

    Node *p = NIL; //记录父节点

    Node *newNode = new Node;
    newNode->key = value;
    newNode->left = NIL;
    newNode->right = NIL;

    while (node != NIL)
    {
        p = node;
        if (value < node->key)
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }
    newNode->parent = p;
    if (p == NIL)
    {
        root = newNode;
    }
    else
    {
        if (newNode->key < p->key)
        {
            p->left = newNode;
        }
        else
        {
            p->right = newNode;
        }
    }
}

void preOrder(Node *node)
{

    if (node == NIL)
    {
        return;
    }
    cout << " " << node->key;
    preOrder(node->left);
    preOrder(node->right);
}

void inOrder(Node *node)
{
    if (node == NIL)
    {
        return;
    }
    inOrder(node->left);
    cout << " " << node->key;
    inOrder(node->right);
}

int main()
{
    int n;
    string command;
    int value;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> command;
        if (command == "insert")
        {
            cin >> value;
            insert(value);
        }
        else if (command == "print")
        {
            inOrder(root);
            cout << endl;
            preOrder(root);
            cout << endl;
        }
    }

    return 0;
}