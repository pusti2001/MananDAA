#include <bits/stdc++.h>
using namespace std;

int mini(int *array, int n)
{
    int index = 0;

    for (int i = 1; i < n; i++)
        if (array[i] < array[index])
            index = i;

    return index;
}

float optimal(int *c, int *x, int n)
{
    int mtr[n], tc = 0, no = n, count = 0;
    while (no--)
    {
        int i = mini(c, n);
        tc = tc + c[i];
        c[i] = 999;
        mtr[count] = tc;
        x[count++] = i + 1;
    }
    return float(accumulate(mtr, mtr + n, 0)) / float(n);
}

int main()
{
    int n = 3;
    int c[n] = {5, 10, 2};
    int x[n];
    float res = optimal(c, x, n);
    cout << res << endl;
    for (int i = 0; i < n; i++)
        cout << x[i];
    return 0;
}