#include <iostream>
using namespace std;

// 使用flag的冒泡排序法
int bubbleSort(int A[], int N) //包含N个元素的0起点的数组A
{
    int sw = 0;                // swap count
    bool flag = 1;             // 存在顺序相反的两个元素，若某次循环没有这个标记了，就说明没有这次循环进行交换了，说明交换结束了
    for (int i = 0; flag; i++) // i  未排序部分的起始位置下标
    {
        flag = 0;
        for (int j = N - 1; j >= i + 1; j--)
        {
            if (A[j] < A[j - 1])
            {
                int temp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = temp;
                flag = 1;
                sw++;
            }
        }
    }

    return sw;
}

int main()
{
    int A[100], N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];

    int sw = bubbleSort(A, N);

    for (int i = 0; i < N; i++)
    {
        if (i)
            cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << sw << endl;

    return 0;
}