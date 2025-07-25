#include <bits/stdc++.h>
using namespace std;

int fibBottomUp(int n) {
    if (n <= 1)
        return n;

    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Fibonacci number at position " << n << " is " << fibBottomUp(n) << endl;

    return 0;
}
