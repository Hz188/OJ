#include <iostream>
using namespace std;

const int MAX = 100000;

typedef long long llong;

int n, k;
llong T[MAX];

// 看看k辆最大运载量P的车能装的最大货物数是多少
int check(llong P)
{
    // 遍历 货物数
    int i = 0;
    int j; // 遍历卡车
    for (j = 0; j < k; j++)
    {
        llong s = 0;
        while (s + T[i] <= P)    // 如果还没装超载，就继续装
        {
            s += T[i];
            i++;  // 继续装下一件货物
            if (i == n)
                return n;
        }
    }
    return i;
}

// 二分 逐渐缩小P 找到满足条件的最小P
int solve()
{
    llong left = 0;
    llong right = MAX * 10000; // 货物数 * 最大重量
    llong mid;                 // binarySearch
    while (right - left > 1)
    {
        mid = (left + right) / 2;
        int v = check(mid);   // 检查 P == mid 时候 能装下多少件货物
        if (v >= n)           // 如果 可装的货物 >= n 了 说明目前可以装下，我们向下缩小范围，二分砍掉上半部分
        {
            right = mid;
        }
        else                    // else 就说明不够装n件，我们向上扩大范围，二分砍掉下半部分
        {
            left = mid;
        }
    }

    return right;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> T[i];
    }
    llong ans = solve();

    cout << ans << endl;
}