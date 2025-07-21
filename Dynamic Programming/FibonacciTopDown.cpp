#include <bits/stdc++.h>
using namespace std;

int fibTopDown(int n, vector<int>& dp) {
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = fibTopDown(n - 1, dp) + fibTopDown(n - 2, dp);
    return dp[n];
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    vector<int> dp(n + 1, -1);
    cout << "Fibonacci number at position " << n << " is " << fibTopDown(n, dp) << endl;

    return 0;
}


