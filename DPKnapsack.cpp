#include <bits/stdc++.h>
using namespace std;

void table(int *w, int *p, int n, int m, int **tab)
{

    // For first denomination
    for (int i = 0; i < m + 1; i++)
    {
        if (w[0] <= i)
            tab[0][i] = p[0];
        else
            tab[0][i] = 0;
    }

    for (int i = 1; i < n; i++)
        for (int j = 0; j < m + 1; j++)
        {
            int pv = tab[i - 1][j];
            int nv = 0;
            if (w[i] <= j && j < 2 * w[i])
                nv = p[i] + tab[i][j - w[i]];
            else if (j >= 2 * w[i])
                nv = tab[i][j - 1];
            tab[i][j] = max(pv, nv);
        }
}

void knapsack(int *w, int *p, int n, int m, int **tab)
{
    table(w, p, n, m, tab);
    int no = n;
    int x[n] = {0};
    cout << "The total profit is: " << tab[n - 1][m] << endl;
    cout << "The solution vector is: " << endl;
    while (m)
    {
        if (tab[no - 1][m] == tab[no - 2][m])
            no--;
        else
        {
            m = m - w[no - 1];
            x[no - 1] = 1;
        }
    }

    for (int i = 0; i < n; i++)
        cout << x[i] << " ";
}

int main()
{
    int n, m;
    cout << "Enter the number of objects: ";
    cin >> n;
    cout << "Enter the weight and profit of each object: ";
    int *w = new int[n];
    int *p = new int[n];
    for (int i = 0; i < n; i++)
        cin >> w[i] >> p[i];

    cout << "Enter the capacity of the knapsack: ";
    cin >> m;
    int **tab = new int *[n];
    for (int i = 0; i < n; i++)
        tab[i] = new int[m + 1];
    knapsack(w, p, n, m, tab);
    return 0;
}