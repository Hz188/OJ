#include <iostream>
#include <cstring>
using namespace std;
const int LEN = 100005;
struct Task
{
    string name;
    int time;
};

Task task[LEN];
int head = 0; // queue head
int tail = 0; // queue tail
int n;        // task number

void enqueue(Task t)
{
    task[tail] = t;
    tail = (tail + 1) % LEN;
}

Task dequeue()
{
    Task t = task[head];
    head = (head + 1) % LEN;
    return t;
}

int min(int a, int b)
{
    return a > b ? b : a;
}

int main()
{
    int elaps = 0, c; // elapse n. 流逝；时间的过去
    int i, q;
    Task u;
    cin >> n >> q;
    for (i = 1; i <= n; i++)
    {
        cin >> task[i].name >> task[i].time;
    }
    head = 1;
    tail = n + 1;

    while (head != tail)
    {
        u = dequeue();
        c = min(u.time, q);
        u.time -= c;
        elaps += c;
        if (u.time > 0)
        {
            enqueue(u);
        }
        else
        {
            cout << u.name << " " << elaps << endl;
        }
    }
}