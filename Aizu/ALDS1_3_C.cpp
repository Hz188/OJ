// #include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *prev;
    Node *next;
};

Node *nil; //哨兵节点

void init()
{
    nil = new Node;
    nil->next = nil;
    nil->prev = nil;
}

void insert(int key)
{
    //在头结点后 添加元素
    Node *x = new Node;
    x->key = key;
    x->next = nil->next;
    x->prev = nil;
    nil->next->prev = x;
    nil->next = x;
}

Node *listSearch(int key)
{
    Node *cur = nil->next;
    while (cur->key != key && cur != nil)
    {
        cur = cur->next;
    }

    return cur;
}

void deleteNode(Node *t)
{
    if (t == nil)
    {
        return;
    }
    t->next->prev = t->prev;
    t->prev->next = t->next;
    delete t;
}

void deleteLast()
{
    deleteNode(nil->prev);
}

void deleteFirst()
{
    deleteNode(nil->next);
}

void deleteKey(int key)
{

    deleteNode(listSearch(key));
}

void printList()
{
    Node *cur = nil->next;
    for (int i = 0; cur != nil; i++)
    {
        if (i)
            cout << " ";
        cout << cur->key;
        cur = cur->next;
    }
    cout << endl;
}

int main()
{
    int key, n;
    cin >> n;
    // scanf("%d", &n);
    char com[20];
    init();
    int size = 0;
    int np = 0;
    int nd = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> com;
        // scanf("%s", com);
        if (com[0] == 'i')
        {
            cin >> key;
            // scanf("%d", &key);
            insert(key);
            size++;
            np++;
        }
        else if (com[0] == 'd')
        {
            if (strlen(com) > 6)
            {
                if (com[6] == 'F')
                {
                    deleteFirst();
                }
                else if (com[6] == 'L')
                {
                    deleteLast();
                }
            }
            else
            {
                cin >> key;
                // scanf("%d", &key);
                deleteKey(key);
                nd++;
            }
            size--;
        }
    }

    printList();

    return 0;
}