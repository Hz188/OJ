// stable sort
#include <iostream>
using namespace std;

struct Card
{
    char suit, value;
};

void bubble(Card c[], int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = N - 1; j >= i + 1; j--)
        {
            if (c[j].value < c[j - 1].value)
            {
                Card t = c[j];
                c[j] = c[j - 1];
                c[j - 1] = t;
            }
        }
    }
}

void selection(Card c[], int N)
{
    for (int i = 0; i < N; i++)
    {
        int minj = i;
        for (int j = i; j < N; j++)
        {
            if (c[j].value < c[minj].value)
            {
                minj = j;
            }
        }
        Card t = c[i];
        c[i] = c[minj];
        c[minj] = t;
    }
}
void print(Card c[], int N)
{
    for (int i = 0; i < N; i++)
    {
        if (i)
            cout << " ";
        cout << c[i].suit << c[i].value;
    }
    cout << endl;
}

bool isStable(Card c1[], Card c2[], int N)
{
    for (int i = 0; i < N; i++)
    {
        if (c1[i].suit != c2[i].suit)
            return false;
    }
    return true;
}

int main()
{
    Card C1[100], C2[100];
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> C1[i].suit >> C1[i].value;
        C2[i] = C1[i];
    }

    bubble(C1, N);
    selection(C2, N);
    print(C1, N);
    cout << "Stable" << endl;

    print(C2, N);
    if (isStable(C1, C2, N))
    {
        cout << "Stable" << endl;
    }
    else
    {
        cout << "Not stable" << endl;
    }

    return 0;
}