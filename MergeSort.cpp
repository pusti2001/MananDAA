#include <bits/stdc++.h>
using namespace std;

void Merge(int *arr, int low, int mid, int high)
{
    int nl = (mid - low + 1), nr = (high - mid);
    int left[nl], right[nr];
    for (int i = 0; i < nl; i++)
        left[i] = arr[low + i];
    for (int i = 0; i < nr; i++)
        right[i] = arr[mid + 1 + i];
    int i = 0, j = 0, k = low;
    while (i < nl && j < nr)
    {
        if (left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < nl)
        arr[k++] = left[i++];
    while (j < nr)
        arr[k++] = right[j++];
}

void MergeSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        Merge(arr, low, mid, high);
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements:" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    MergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}