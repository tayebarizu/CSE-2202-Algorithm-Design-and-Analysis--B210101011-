#include <bits/stdc++.h>
using namespace std;

int minCoins(int sum, vector<int>& coins, vector<int>& dp) {
    if (sum == 0) return 0;
    if (sum < 0) return INT_MAX;

    if (dp[sum] != -1) return dp[sum];

    int minCount = INT_MAX;

    for (int coin : coins) {
        int res = minCoins(sum - coin, coins, dp);
        if (res != INT_MAX)
            minCount = min(minCount, res + 1);
    }

    dp[sum] = minCount;
    return dp[sum];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int sum = 11;

    vector<int> dp(sum + 1, -1);

    int result = minCoins(sum, coins, dp);

    if (result == INT_MAX)
        cout << "It's not possible to make the sum with given coins." << endl;
    else
        cout << "Minimum coins required: " << result << endl;

    return 0;
}
