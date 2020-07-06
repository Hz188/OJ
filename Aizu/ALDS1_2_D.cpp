#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

long long cnt = 0;
int l;
int A[1000000];
int n;
vector<int> G;

// 指定间隔g的插入排序
void insertionSort(int A[], int n, int g)
{
    for (int i = g; i < n; i++)
    {
        int v = A[i];
        int j;
        for (j = i - g; j >= 0 && A[j] > v; j -= g)
        {
            A[j + g] = A[j];
            cnt++;
        }
        A[j + g] = v;
    }
}

void shellSort(int A[], int n)
{
    // generate G serise G = {1,4 ,13, 40, 121, 364,1093}
    for (int h = 1;;)
    {
        if (h > n)
        {
            break;
        }
        G.push_back(h);
        h = 3 * h - 1;
    }

    for (int i = G.size() - 1; i >= 0; i--) // 按逆序指定G[i] = g;
    {
        insertionSort(A, n, G[i]);
    }
}

int main()
{
    cin >> n;
    // use faster scanf function to input
    for (int i = 0; i < n; i++)
    {
        // scanf("%d", &A[i]);
        cin >> A[i];
    }

    shellSort(A, n);

    cout << G.size() << endl;
    for (int i = G.size() - 1; i >= 0; i--)
    {
        // printf("%d", G[i]);

        if (i != G.size() - 1)
        {
            // printf(" ");
            cout << " ";
        }
        cout << G[i];
    }
    // printf("\n");
    cout << endl;
    // printf("%d\n", cnt);
    cout << cnt << endl;
    for (int i = 0; i < n; i++)
    {
        // printf("%d\n", A[i]);
        cout << A[i] << endl;
    }

    return 0;

   
}