#include<iostream>
using namespace std;

const int MAX = 100005;
const int NIL = -1;

struct Node{
    int p;
    int l;
    int r;
};

Node T[MAX]; //存储每个结点，每个结点自身记录了 父亲，左孩子，右兄弟
int n, D[MAX]; // n为结点个数  D为每个结点的深度




void setDepth(int u, int p){
    D[u] = p;
    if(T[u].l != NIL){
        setDepth(T[u].l, p + 1);
    }
    if(T[u].r != NIL){
        setDepth(T[u].r, p);
    }
}
void printChild(int u){
    int leftChild = T[u].l;
    cout << "[";
    
    while(leftChild != NIL){
        if(T[leftChild].r != NIL){
            cout << leftChild << ", ";
        } else{
             cout << leftChild;
        }

        leftChild = T[leftChild].r;
    }
    cout << "]" << endl;
}
void print(int u){
    cout << "node " << u << ": ";
    cout << "parent = " << T[u].p << ", ";
    cout << "depth = " << D[u] << ", ";
    if(T[u].p == NIL){
        cout << "root, ";
    } else if (T[u].l == NIL){
        cout << "leaf, ";
    } else{
        cout << "internal node, ";
    }
    printChild(u);
}






int main(){


    int id;
    int degree;
    int child;
    int i, j;
    int left;
    int root = 0;

    cin >> n;
    for (i = 0; i < n; i++)
    {
        T[i].p = T[i].l = T[i].r = NIL;
    }
    

    for (i = 0; i < n; i++){
        cin >> id >> degree;
        for (j = 0; j < degree; j++) {
            cin >> child;
            if(j == 0){
                T[id].l = child;
            } else{
                T[left].r = child;
            }
            left = child;
            T[left].p = id;
        }
    }

    for (i = 0; i < n; i++)
    {
        if(T[i].p == NIL){
            root = i;
        }
    }

    setDepth(root, 0);

    for (i = 0; i < n; i ++){
        print(i);
    }

    return 0;
}