#include <bits/stdc++.h>
using namespace std;

void permute(char *a, int i, int n)
{
    int j;
    if (i == n)
        cout << a << endl;
    else
        for (j = i; j < n; j++)
        {
            swap(a[i], a[j]);
            permute(a, i + 1, n);
            swap(a[i], a[j]);
        }
}

int main()
{
    char a[] = "";
    cout << "Enter a string: ";
    cin >> a;
    permute(a, 0, 3);
    return 0;
}