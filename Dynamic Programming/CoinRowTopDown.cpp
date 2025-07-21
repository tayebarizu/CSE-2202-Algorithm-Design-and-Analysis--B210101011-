#include <bits/stdc++.h>
using namespace std;

int coinRowTopDown(int i, vector<int>& coins, vector<int>& dp) {
    if (i < 0) return 0;
    if (dp[i] != -1) return dp[i];

    dp[i] = max(coinRowTopDown(i - 1, coins, dp), coinRowTopDown(i - 2, coins, dp) + coins[i]);
    return dp[i];
}

int main() {
    vector<int> coins = {5, 1, 2, 10, 6, 2};
    int n = coins.size();
    vector<int> dp(n, -1);

    cout << "Maximum sum without adjacent coins: "
         << coinRowTopDown(n - 1, coins, dp) << endl;

    return 0;
}

