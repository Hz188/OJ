#include <algorithm>
#include <iostream>
#include <list>
using namespace std;

int main()
{
    int key, n;
    char com[20];

    list<int> v;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> com;
        // scanf("%s", com);
        if (com[0] == 'i')
        {
            cin >> key;
            v.push_front(key);
        }
        else if (com[6] == 'F')
        {
            v.pop_front();
        }
        else if (com[6] == 'L')
        {
            v.pop_back();
        }
        else if (com[0] == 'd')
        {
            cin >> key;
            for (list<int>::iterator it = v.begin(); it != v.end(); it++)
            {
                if (*it == key)
                {
                    v.erase(it);
                    break;
                }
            }
        }
    }

    int i = 0;
    for (list<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        if (i++)
            cout << " ";
        cout << *it;
    }
    cout << endl;

    return 0;
}