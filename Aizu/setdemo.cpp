#include <iostream>
#include <set>
using namespace std;

void print(set<int> S)
{
    cout << S.size() << ":";
    for (set<int>::iterator it = S.begin(); it != S.end(); it++)
    {
        cout << " " << *it;
    }
    cout << endl;
}

int main()
{
    set<int> s;

    s.insert(8);
    s.insert(1);
    s.insert(7);
    s.insert(4);
    s.insert(8);
    s.insert(4);

    print(s); // 4: 1 4 7 8

    s.erase(7);

    print(s); //3: 1 4 8

    s.insert(2);
    print(s); // 4: 1 2 4 8

    if (s.find(10) == s.end())
    {
        cout << "not found." << endl; //not found.
    }

    return 0;
}