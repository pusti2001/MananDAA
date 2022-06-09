#include <bits/stdc++.h>
using namespace std;

int binomialCoeff(int **c, int n, int k)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
                c[i][j] = 1;
            else
                c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
    return c[n][k];
}

int main()
{
    int n, k;
    cout << "Enter n and k: ";
    cin >> n >> k;
    int **c = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
        c[i] = new int[k + 1];
    cout << "The binomial coefficient is: " << binomialCoeff(c, n, k);

    return 0;
}