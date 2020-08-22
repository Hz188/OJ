#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int n;
vector<int> pre, in, post;


int main(){
    int k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        pre.push_back(k);
    }

    for (int i = 0; i < n; i++)    {
        cin >> k;
        in.push_back(k);
    }
    
    
}