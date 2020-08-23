#include <iostream>
#include <map>
#include <string>
using namespace std;

void print(map<string, int> t)
{
    map<string, int>::iterator it;
    cout << t.size() << endl;
    for (it = t.begin(); it != t.end(); it++)
    {
        pair<string, int> item = *it;
        cout << item.first << " --> " << item.second << endl;
    }
}
int main()
{
    map<string, int> t;
    t["red"] = 32;
    t["blue"] = 688;
    t["yellow"] = 122;

    t["blue"] += 312;

    print(t);

    t.insert(make_pair("zebra", 101010));
    t.insert(make_pair("white", 0));
    t.erase("yellow");

    print(t);

    pair<string, int> res = *t.find("red");
    cout << res.first << " --> " << res.second << endl;
    return 0;
}