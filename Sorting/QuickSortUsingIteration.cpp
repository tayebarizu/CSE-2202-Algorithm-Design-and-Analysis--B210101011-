#include <bits/stdc++.h>
using namespace std;
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortIterative(int arr[], int l, int h) {
    stack<int> st;
    st.push(l);
    st.push(h);

    while (!st.empty()) {
        h = st.top(); st.pop();
        l = st.top(); st.pop();

        int p = partition(arr, l, h);

        if (p - 1 > l) {
            st.push(l);
            st.push(p - 1);
        }

        if (p + 1 < h) {
            st.push(p + 1);
            st.push(h);
        }
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSortIterative(arr, 0, n - 1);

    cout << "Sorted array (Iterative): ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
