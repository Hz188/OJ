#include <iostream>
using namespace std;

int selectionSort(int A[], int N)
{
    int swapCount = 0;
    int minj;
    int temp;
    int i, j;

    for (i = 0; i < N - 1; i++)
    {
        minj = i;
        for (j = i; j < N; j++)
        {
            if (A[j] < A[minj])
            {
                minj = j;
            }
        }

        if (i != minj)
        {
            temp = A[i];
            A[i] = A[minj];
            A[minj] = temp;
            swapCount++;
        }
    }
    return swapCount;
}

int main()
{
    int A[100];
    int N;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    int swapCount = selectionSort(A, N);

    for (int i = 0; i < N; i++)
    {
        if (i)
            cout << " ";
        cout << A[i];
    }

    cout << endl;

    cout << swapCount << endl;

    return 0;
}