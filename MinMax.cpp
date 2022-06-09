#include <bits/stdc++.h>
using namespace std;

void MinMax(int *arr, int low, int high, int &min, int &max)
{
    if (low == high)
    {
        if (min > arr[low])
            min = arr[low];
        if (max < arr[low])
            max = arr[low];
        return;
    }
    else if ((high - low) == 1)
    {
        if (min > arr[low])
            min = arr[low];
        if (max < arr[low])
            max = arr[low];
        if (min > arr[high])
            min = arr[high];
        if (max < arr[high])
            max = arr[high];
        return;
    }
    int mid = (low + high) / 2;
    MinMax(arr, low, mid, min, max);
    MinMax(arr, mid + 1, high, min, max);
}

int main()
{
    int n = 9;
    cout << "Enter number of terms: ";
    cin >> n;
    cout << "Enter the numbers: ";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int max = -999, min = 999;
    MinMax(arr, 0, n - 1, min, max);
    cout << "The max is: " << max << endl;
    cout << "The min is: " << min;
    return 0;
}