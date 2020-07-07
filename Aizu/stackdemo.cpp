#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> S;

    S.push(3);  // 3
    S.push(7);  // 3 7 
    S.push(1);  // 3 7 1
    cout << S.size() << endl;   // 3 

    cout << S.top() << endl;    //  1   --> 3 7 1 
    S.pop();                    // 1    --> 3 7

    cout << S.top() << endl;    // 7  --> 3 7
    S.pop();                    // 7  --> 3

    cout << S.top() << endl;    // 3  --> 3
    S.push(5);                  // --> 3 5

    cout << S.top() << endl;    //  3 5 --> 5
    S.pop();                    //  5 --> 3

    cout << S.top() << endl;    //  3 --> 3

    return 0;
}