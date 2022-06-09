#include <bits/stdc++.h>
using namespace std;

int maxi(int *array, int n)
{
    int index = 0;

    for (int i = 1; i < n; i++)
        if (array[i] > array[index])
            index = i;

    return index;
}

int scheduling(int *p, int *d, int *x, int n, int k)
{
    int tp = 0, no = n;
    while (no--)
    {
        int i = maxi(p, n);
        int dl = d[i];
        while (x[dl - 1] != 0 && dl > 0)
            dl--;
        if (dl)
        {
            x[dl - 1] = i + 1;
            tp = tp + p[i];
        }
        p[i] = 0;
    }
    return tp;
}

int main()
{
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;
    int p[n];
    int d[n];
    cout << "Enter profit and deadline for the jobs: ";
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        cin >> d[i];
    }
    int k = *max_element(d, d + n);
    int x[k] = {0};
    int profit = scheduling(p, d, x, n, k);
    cout << profit << endl;
    for (int i = 0; i < k; i++)
    {
        if (x[i] != 0)
            cout << "J" << x[i] << " ";
        else
            cout << "NA ";
    }
    return 0;
}