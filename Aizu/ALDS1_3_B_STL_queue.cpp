#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    int n, q, t;
    string name;
    // use STL queue
    queue<pair<string, int>> Q;
    cin >> n >> q;
    int i;
    for (i = 1; i <= n; i++)
    {
        cin >> name >> t;
        Q.push(make_pair(name, t));
    }

    pair<string, int> u;
    int elaps = 0, a;

    while (!Q.empty())
    {
        u = Q.front();
        Q.pop();
        a = min(u.second, q);
        u.second -= a;
        elaps += a;
        if (u.second > 0)
        {
            Q.push(u);
        }
        else
        {
            cout << u.first << " " << elaps << endl;
        }
    }
}