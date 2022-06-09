#include <bits/stdc++.h>
using namespace std;

bool feasible(int *c, int i, int m, int w, int total)
{
    return ((w + total >= m) && (w == m || w + c[i] <= m));
}

void subsets(int *c, int *soln, int n, int i, int m, int w, int total)
{
    if (feasible(c, i, m, w, total))
    {
        if (w == m)
        {
            for (int j = 0; j < n; j++)
                cout << soln[j] << " ";
            cout << endl;
        }
        else
        {
            soln[i] = 1;
            subsets(c, soln, n, i + 1, m, w + c[i], total - c[i]);
            soln[i] = 0;
            subsets(c, soln, n, i + 1, m, w, total - c[i]);
        }
    }
}

int main()
{
    int n, m, total;
    cout << "Enter number of subsets: ";
    cin >> n;
    int *c = new int[n];
    int *soln = new int[n + 1];
    cout << "Enter cost of " << n << " subsets in ascending order: ";
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
        total += c[i];
        soln[i] = 0;
    }
    cout << "Enter the maximum cost: ";
    cin >> m;

    subsets(c, soln, n, 0, m, 0, total);

    return 0;
}