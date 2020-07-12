#include <iostream>
#include <algorithm>
using namespace std;

int A[1000000], n;


int main()
{
    int i, q, key, sum = 0;

    cin >> n;
    for (i = 0; i < n; i++)
        cin >> A[i];

    cin >> q;
    for (i = 0; i < q; i++)
    {
        cin >> key;
        if(*lower_bound(A,A+n,key)==key){  //从A 到 A末尾，找到大于等于key的第一个元素对应的迭代器，再*解引用，若等于key说明找到了
            sum++;
        }
    }

    cout << sum << endl;

    return 0;
}