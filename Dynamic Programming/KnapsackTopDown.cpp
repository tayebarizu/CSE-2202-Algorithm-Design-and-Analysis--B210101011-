#include <bits/stdc++.h>
using namespace std;

int knapsackTopDown(int i, int W, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp) {
    if (i == 0 || W == 0) return 0;

    if (dp[i][W] != -1) return dp[i][W];

    if (wt[i - 1] <= W) {
        int take = val[i - 1] + knapsackTopDown(i - 1, W - wt[i - 1], wt, val, dp);
        int dontTake = knapsackTopDown(i - 1, W, wt, val, dp);
        dp[i][W] = max(take, dontTake);
    } else {
        dp[i][W] = knapsackTopDown(i - 1, W, wt, val, dp);
    }

    return dp[i][W];
}

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;
    int n = val.size();

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));

    cout << "Maximum value in knapsack: " << knapsackTopDown(n, W, wt, val, dp) << endl;

    return 0;
}

