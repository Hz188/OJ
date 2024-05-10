#include<iostream>
#include<cstdio>
using namespace std;

// int dp[50];
// int fib(int n){
    // if (n == 0 || n == 1) return dp[n] = 1;
    // if(dp[n] != -1) return dp[n];
    // return dp[n] = fib(n - 1) + fib(n - 2);
// }

// int main(){

//     int n;
//     cin >> n;

//     for(int i = 0; i < 50; i++) {
//         dp[i] = -1;
//     }
//     scanf("%d", &n);
//     printf("%d\n", fib(n));

//     return 0;
// }

//----------------------------------
int main() {
    int n; cin >> n;
    int F[50];

    F[0] = 1;
    F[1] = 1;
    for(int i = 2; i <= 50 ; i++) {
        F[i] = F[i - 1] + F[i - 2];
    }

    cout << F[n] << endl;

    return 0;
}