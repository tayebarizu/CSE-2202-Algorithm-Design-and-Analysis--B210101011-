#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int l = mid - left + 1;
    int h = right - mid;

    int L[l], R[h];

    for (int i = 0; i < l; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < h; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < l && j < h) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < l)
        arr[k++] = L[i++];

    while (j < h)
        arr[k++] = R[j++];
}

void mergeSortRecursive(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSortRecursive(arr, left, mid);
        mergeSortRecursive(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {6, 3, 9, 5, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSortRecursive(arr, 0, n - 1);

    cout << "Sorted array (Recursive): ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

