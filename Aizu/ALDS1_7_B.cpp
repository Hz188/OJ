#include<iostream>
using namespace std;

const int MAX = 25;
const int NIL = -1;

struct Node {
    int p, l, r;
};

Node T[MAX];
int D[MAX], H[MAX];
int n;

void setDepth(int u, int d){
    if(u == NIL) {
        return;
    }
    D[u] = d;
    setDepth(T[u].l, d + 1);
    setDepth(T[u].r, d + 1);

}

int setHeigth(int u){
    int h1 = 0, h2 = 0;
    if(T[u].l != NIL){
        h1 = setHeigth(T[u].l) + 1;
    }
    if(T[u].r != NIL){
        h2 = setHeigth(T[u].r) + 1;
    }
    return H[u] = (h1 > h2 ? h1 : h2);
}

int getSibling(int u){
    if(T[u].p == NIL)
        return NIL;
    if(T[T[u].p].l != u  && T[T[u].p].l != NIL) {
        return T[T[u].p].l;
    }
    if(T[T[u].p].r != u && T[T[u].p].r != NIL) {
        return T[T[u].p].r;
    }
    return NIL;
}

void print(int u){
    cout << "node " << u << ": ";
    cout << "parent = " << T[u].p << ", ";
    cout << "sibling = " << getSibling(u) << ", ";

    
    int degreen = 0;
    if(T[u].l != NIL)
        degreen++;
    if(T[u].r != NIL)
        degreen++;
    cout << "degreen = " << degreen << ", ";
    cout << "depth = " << D[u] << ", ";
    cout << "height = " << H[u] << ", ";

    if(T[u].p == NIL){
        cout << "root" << endl;
    } else if(T[u].l == NIL && T[u].r == NIL){
        cout << "leaf" << endl;
    } else{
        cout << "internal node" << endl;
    }
}

int main(){

    int id, l, r;
    int root = 0;

    cin >> n;
    for (int i = 0; i < n; i ++){
        T[i].p = NIL;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> id >> l >> r;
        T[id].l = l;
        T[id].r = r;
        if(l != NIL){
            T[l].p = id;
        }
        if(r != NIL){
            T[r].p = id;
        }
    }

    for (int i = 0; i < n; i++){
        if(T[i].p == NIL) {
            root = i;
        }
    }

    setDepth(root, 0);
    setHeigth(root);

    for (int i = 0; i < n;i++){
        print(i);
    }
}