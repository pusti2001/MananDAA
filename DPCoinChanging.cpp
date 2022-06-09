#include <bits/stdc++.h>
using namespace std;

void table(int *coins, int n, int m, int **x)
{
    // For first denomination
    for (int i = 0; i < m + 1; i++)
    {
        if (i % coins[0] == 0)
            x[0][i] = i / coins[0];
        else
            x[0][i] = INT_MAX;
    }

    // For rest denominations
    for (int i = 1; i < n; i++)
        for (int j = 0; j < m + 1; j++)
        {
            int pv = x[i - 1][j];
            int nv = INT_MAX;
            if (coins[i] <= j)
                nv = 1 + x[i][j - coins[i]];
            x[i][j] = min(pv, abs(nv));
        }
}

void coinChange(int *coins, int n, int m, int **x)
{
    table(coins, n, m, x);
    cout << "Coins used: " << endl;
    while (m)
    {
        if (x[n - 1][m] == x[n - 2][m])
            n--;
        else
        {
            m = m - coins[n - 1];
            cout << coins[n - 1] << " ";
        }
    }
}

int main()
{
    int n, m;
    cout << "Enter number of denominations: ";
    cin >> n;
    int *coins = new int[n];
    cout << "Enter the denominations in ascending order: ";
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    cout << "Enter the amount: ";
    cin >> m;
    int **x = new int *[n];
    for (int i = 0; i < n; i++)
        x[i] = new int[m + 1];
    coinChange(coins, n, m, x);
    return 0;
}