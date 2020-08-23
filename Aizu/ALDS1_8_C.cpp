#include <iostream>
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

Node *find(int value)
{
    Node *node = root;
    while (node != NIL && value != node->key)
    {
        if (value < node->key)
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }
    // if (node == NIL)
    // {
    //     return 0;
    // }
    // else
    // {
    //     return 1;
    // }
    return node;
}

//寻找以node为根的最小值结点
Node *treeMinimum(Node *node)
{
    while (node->left != NIL)
    {
        node = node->left;
    }
    return node;
}

//寻找node的后继(中序遍历的node的后一个结点)即比node大的最小值
Node *treeSuccessor(Node *node)
{
    if (node->right != NIL)
    {
        return treeMinimum(node->right);
    }
    Node *parent = node->parent;
    while (parent != NIL && node == parent->right)
    {
        node = parent;
        parent = parent->parent;
    }
    return parent;
}

void treeDelete(Node *z)
{
    Node *y; //要删除的对象
    Node *x; //y的子节点

    // 确定要删除的结点
    if (z->left == NIL || z->right == NIL)
    {
        y = z;
    }
    else
    {
        y = treeSuccessor(z);
    }

    // 确定y的子节点x
    if (y->left != NIL)
    {
        x = y->left;
    }
    else
    {
        x = y->right;
    }

    if (x != NIL)
    {
        x->parent = y->parent;
    }

    if (y->parent == NIL)
    {
        root = x;
    }
    else
    {
        if (y == y->parent->left)
        {
            y->parent->left = x;
        }
        else
        {
            y->parent->right = x;
        }
    }

    if (y != z)
    {
        z->key = y->key;
    }
    delete y;
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
        else if (command == "find")
        {
            cin >> value;
            Node *result = find(value);
            if (result != NIL)
            {
                cout << "yes" << endl;
            }
            else
            {
                cout << "no" << endl;
            }
        }
        else if (command == "delete")
        {
            cin >> value;
            treeDelete(find(value));
        }
    }

    return 0;
}
