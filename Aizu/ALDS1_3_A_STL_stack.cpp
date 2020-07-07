#include <cstdlib>
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int a, b;
    stack<int> S;
    string s;

    while (cin >> s)
    {
        if (s[0] == '+')
        {
            a = S.top();
            S.pop();
            b = S.top();
            S.pop();
            S.push(a + b);
        }
        else if (s[0] == '-')
        {
            a = S.top();
            S.pop();
            b = S.top();
            S.pop();
            S.push(b - a);
        }
        else if (s[0] == '*')
        {
            a = S.top();
            S.pop();
            b = S.top();
            S.pop();
            S.push(a * b);
        }
        else
        {
            S.push(atoi(s.c_str()));
        }
    }

    cout << S.top() << endl;
    return 0;
}