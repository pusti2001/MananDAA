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

int loading(int *w, int *x, int n, int m)
{
    while (m > 0)
    {
        int i = mini(w, n);
        if (m - w[i] >= 0)
        {
            x[i] = 1;
            m = m - w[i];
            w[i] = 999;
        }
        else
            break;
    }
    return m;
}

int main()
{
    int n, m;
    cout << "Enter number of containers: ";
    cin >> n;

    int w[n];
    int x[n] = {0};
    cout << "Enter weight of each container: ";
    for (int i = 0; i < n; i++)
        cin >> w[i];

    cout << "Enter the capacity: ";
    cin >> m;

    int wei = m - loading(w, x, n, m);
    cout << wei << endl;
    for (int i = 0; i < n; i++)
        cout << x[i] << " ";
    return 0;
}