#include <iostream>
using namespace std;

int A[1000000], n;
int binarySearch(int key)
{
    int left = 0, right = n, mid;
    while (left < right)
    {
        mid = (left + right) / 2;
        if (A[mid] == key)
        {
            return 1;
        }
        else if (key < A[mid])
        {
            right = mid;
        }
        else if (key > A[mid])
        {
            left = mid + 1;
        }
    }
    return 0;
}

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
        if (binarySearch(key))
            sum++;
    }

    cout << sum << endl;

    return 0;
}