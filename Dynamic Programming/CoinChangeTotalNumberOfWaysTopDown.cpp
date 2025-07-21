#include <bits/stdc++.h>
using namespace std;

int countWaysTopDown(int i, int sum, vector<int>& coins, vector<vector<int>>& dp) {
    if (sum == 0) return 1;
    if (i == 0) return 0;

    if (dp[i][sum] != -1) return dp[i][sum];

    int ways = countWaysTopDown(i - 1, sum, coins, dp);

    if (sum >= coins[i - 1])
        ways += countWaysTopDown(i, sum - coins[i - 1], coins, dp);

    return dp[i][sum] = ways;
}

int main() {
    vector<int> coins = {1, 2, 3};
    int sum = 4;
    int n = coins.size();

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));

    cout << "Total number of ways to make " << sum << " is: "
         << countWaysTopDown(n, sum, coins, dp) << endl;

    return 0;
}

