#include <bits/stdc++.h>
using namespace std;

int change(int *coins, int *x, int n, int money)
{
    int i = n - 1, tc = 0;
    while (money > 0)
    {
        if (money < coins[i])
            i--;
        else
        {
            money = money - coins[i];
            x[i] = x[i] + 1;
            tc++;
        }
    }
    return tc;
}

int main()
{
    int n;
    cout << "Enter number of denominations: ";
    cin >> n;
    int coins[n];
    cout << "Enter denominations: ";
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    sort(coins, coins + n);
    int x[n] = {0};
    int money;
    cout << "Enter the amount: ";
    cin >> money;

    int total = change(coins, x, n, money);
    cout << total << endl;
    for (int i = 0; i < n; i++)
        cout << coins[i] << " - " << x[i] <<endl;

    return 0;
}