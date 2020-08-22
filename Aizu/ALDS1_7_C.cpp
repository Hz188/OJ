#include<iostream>
using namespace std;

const int MAX = 10000;
const int NIL = -1;

struct Node {
    int p, l, r;
};

Node T[MAX];
int n;


void preParse(int u){
    if(u == NIL){
        return;
    }
    cout << " " << u;
    preParse(T[u].l);
    preParse(T[u].r);
}

void inParse(int u){
    if(u == NIL){
        return;
    }

    inParse(T[u].l);
    cout << " " << u;
    inParse(T[u].r);
}
void postParse(int u){
    if(u == NIL){
        return;
    }

    postParse(T[u].l);
    postParse(T[u].r);
    cout << " " << u;
}

int main() {
    int id, l, r, root = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        T[i].p = NIL;
    }

    for (int i = 0; i < n; i++){
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

    for (int i = 0; i < n; i ++){
        if(T[i].p == NIL){
            root = i;
        }
    }

    cout << "Preorder" << endl;
    preParse(root);
    cout << endl;

    cout << "Inorder" << endl;
    inParse(root);
    cout << endl;

    cout << "Postorder" << endl;
    postParse(root);
    cout << endl;

    return 0;
}