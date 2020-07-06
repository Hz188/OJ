#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

int S[1000];
int top;

void push(int x)
{
    S[++top] = x;
}

int pop()
{
    top--;
    return S[top + 1];
}

int main()
{
    int a, b;
    top = 0;
    char s[100];

    while (cin >> s)
    {
        if (s[0] == '+')
        {
            a = pop();
            b = pop();
            push(a + b);
        }
        else if (s[0] == '-')
        {
            a = pop();
            b = pop();
            push(b - a);
        }
        else if (s[0] == '*')
        {
            a = pop();
            b = pop();
            push(a * b);
        }
        else
        {
            push(atoi(s));
        }
    }

    cout << pop() << endl;
    return 0;
}