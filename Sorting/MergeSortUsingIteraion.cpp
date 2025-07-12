#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int l = mid - left + 1;
    int h = right - mid;

    int L[l], R[h];

    for (int i = 0; i < l; i++) L[i] = arr[left + i];
    for (int j = 0; j < h; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < l && j < h) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < l) arr[k++] = L[i++];
    while (j < h) arr[k++] = R[j++];
}

void mergeSortIterative(int arr[], int n) {
    for (int curr_size = 1; curr_size < n; curr_size *= 2) {
        for (int left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            int mid = min(left_start + curr_size - 1, n - 1);
            int right_end = min(left_start + 2 * curr_size - 1, n - 1);

            merge(arr, left_start, mid, right_end);
        }
    }
}

int main() {
    int arr[] = {6, 3, 9, 5, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSortIterative(arr, n);

    cout << "Sorted array (Iterative): ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
