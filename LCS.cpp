#include <bits/stdc++.h>
using namespace std;

void matrix(int **c, string x, string y)
{
    for (int i = 0; i < x.length() + 1; i++)
    {
        for (int j = 0; j < y.length() + 1; j++)
        {
            if (i == 0 || j == 0)
                c[i][j] = 0;
            else if (x[i - 1] == y[j - 1])
                c[i][j] = c[i - 1][j - 1] + 1;
            else
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
        }
    }
}

void LCS(int **c, string x, string y)
{
    matrix(c, x, y);
    int i = x.length();
    int j = y.length();
    string ans = "";
    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            ans.push_back(x[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (c[i][j - 1] > c[i - 1][j])
                j--;
            else
                i--;
        }
    }

    reverse(ans.begin(), ans.end());
    cout << "The LCS is: " << ans << endl;
    cout << "The length of LCS is: " << c[x.length()][y.length()];
}

int main()
{
    string x, y;
    cout << "Enter the first string: ";
    cin >> x;
    cout << "Enter the second string: ";
    cin >> y;
    // int c[x.length() + 1][y.length() + 1];
    int **c = new int *[x.length() + 1];
    for (int i = 0; i < x.length() + 1; i++)
    {
        c[i] = new int[y.length() + 1];
    }
    LCS(c, x, y);
    return 0;
}