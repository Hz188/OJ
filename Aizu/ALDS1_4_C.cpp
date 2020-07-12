#include <cstring>
#include <iostream>
using namespace std;

const int M = 1046527;
const int NIL = -1;
const int L = 14;

char H[M][L];

// Converts  characters to numeric values
int getChar(char ch)
{
    if (ch == 'A')
    {
        return 1;
    }
    else if (ch == 'C')
    {
        return 2;
    }
    else if (ch == 'G')
    {
        return 3;
    }
    else if (ch == 'T')
    {
        return 4;
    }
    else
        return 0;
}

// Converts a string to numeric values & generates the key
long long getKey(char str[])
{
    long long sum = 0, p = 1, i;
    for (i = 0; i < strlen(str); i++)
    {
        sum += p * (getChar(str[i]));
        p *= 5;
    }
    return sum;
}

int h1(int key)
{
    return key % M;
}

int h2(int key)
{
    return 1 + (key % (M - 1));
}

int find(char str[])
{
    long long key, i, h;

    key = getKey(str);
    for (i = 0;; i++)
    {
        h = (h1(key) + i * h2(key)) % M;
        if (strcmp(H[h], str) == 0)
        {
            return 1;
        }
        else if (strlen(H[h]) == 0)
        {
            return 0;
        }
    }
    return 0;
}

int insert(char str[])
{
    long long key, i, h;
    key = getKey(str);
    for (i = 0;; i++)
    {
        h = (h1(key) + i * h2(key)) % M;
        if (strcmp(H[h], str) == 0)
        {
            return 1;
        }
        else if (strlen(H[h]) == 0)
        {
            strcpy(H[h], str);
            return 0;
        }
    }
    return 0;
}

int main()
{
    int i, n, h;
    char str[L], com[9];
    /*
        这个for循环的目的是 初始化，将所有位置字符串都对外表示为空字符串
        代码的理论含义是，用'\0'将所有的0以后的东西都截断

        如果未初始化 '\0'，如果调用了某些函数，比如strlen
        strlen函数将无法知道空字符是没有的，所以它将继续进行查找，
        一个接一个字符查找直到发现一个空字符为止，或许它找几百个字符才找到，
        而此时strlen函数的这个返回值从本质上说是一个随机数或者说并没有实际意义；
    */
    for (i = 0; i < M; i++)
    {
        H[i][0] = '\0';
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> com >> str;
        if(com[0] == 'i'){
            insert(str);
        } else {
            if(find(str)){
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }
    }
    return 0;
}