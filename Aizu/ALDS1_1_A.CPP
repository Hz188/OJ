#include <iostream>
using namespace std;
static const int MAX = 100;

// 按顺序输出数组
void trace(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            cout << " ";
        }
        cout << a[i];
    }
    cout << endl;
}

// insert sort

void insertSort(int A[], int n)
{
    int i, j, value;

    trace(A, n);
    for (i = 1; i < n; i++)
    {

        j = i - 1;
        value = A[i];
        while (j >= 0 && A[j] > value)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = value;
        trace(A, n);
    }
}

int main()
{
    int A[MAX];
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    insertSort(A, n);
    return 0;
}
