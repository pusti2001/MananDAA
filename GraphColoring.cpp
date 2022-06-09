#include <bits/stdc++.h>
using namespace std;

bool isSafe(int **arr, char *soln, int index)
{
    for (int i = 0; i < index; i++)
        for (int j = i + 1; j < index; j++)
            if (arr[i][j] && soln[i] == soln[j])
                return false;

    return true;
}

void coloring(int **arr, char *soln, char *color, int i, int n, int m)
{
    if (isSafe(arr, soln, i))
    {
        if (i == n)
        {
            for (int j = 0; j < n; j++)
                cout << soln[j] << " ";
            cout << endl;
        }
        else
            for (int j = 0; j < m; j++)
            {
                soln[i] = color[j];
                coloring(arr, soln, color, i + 1, n, m);
                soln[i] = 'x';
            }
    }
}

int main()
{
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of colors: ";
    cin >> m;
    cout << "Enter adjacency matrix: " << endl;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    char color[] = "RGB";
    char soln[n];
    cout << endl;
    coloring(arr, soln, color, 0, n, m);
    return 0;
}