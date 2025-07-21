#include <bits/stdc++.h>
using namespace std;

int countWaysBottomUp(vector<int>& coins, int sum) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (j >= coins[i - 1])
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][sum];
}

int main() {
    vector<int> coins = {1, 2, 3};
    int sum = 4;

    cout << "Total number of ways to make " << sum << " is: "
         << countWaysBottomUp(coins, sum) << endl;

    return 0;
}

