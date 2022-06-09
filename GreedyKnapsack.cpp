#include <bits/stdc++.h>
using namespace std;

int maxi(float *array, int n)
{
    int index = 0;

    for (int i = 1; i < n; i++)
        if (array[i] > array[index])
            index = i;

    return index;
}

float knapsack(float *ratio, int *w, int *p, float *x, int n, int m)
{
    float tp = 0;
    while (m && ratio)
    {
        int index = maxi(ratio, n);
        if ((m - w[index]) > 0)
        {
            x[index] = 1;
            tp = tp + p[index];
            m = m - w[index];
            ratio[index] = 0;
        }
        else
        {
            float r = float(m) / float(w[index]);
            tp = tp + r * float(p[index]);
            x[index] = r;
            m = 0;
        }
    }
    return tp;
}

int main()
{
    int n, m;
    cout << "Enter number of objects: ";
    cin >> n;

    int p[n];
    int w[n];
    cout << "Enter weight and profit of each item: ";
    for (int i = 0; i < n; i++)
        cin >> w[i] >> p[i];

    cout << "Enter the capacity of knapsack: ";
    cin >> m;

    float ratio[n];
    for (int i = 0; i < n; i++)
        ratio[i] = float(p[i]) / float(w[i]);

    float x[n] = {0};

    float profit = knapsack(ratio, w, p, x, n, m);
    cout << profit << endl;
    for (int i = 0; i < n; i++)
        cout << x[i] << " ";

    return 0;
}