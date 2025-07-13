#include <bits/stdc++.h>
using namespace std;

int coinRowRecursive(int coins[], int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return coins[0];

    return max(coins[n - 1] + coinRowRecursive(coins, n - 2),
               coinRowRecursive(coins, n - 1));
}

int main() {
    int coins[] = {5, 1, 2, 10, 6, 2};
    int n = sizeof(coins) / sizeof(coins[0]);

    cout << "Maximum value (Recursive): " << coinRowRecursive(coins, n);
    return 0;
}

