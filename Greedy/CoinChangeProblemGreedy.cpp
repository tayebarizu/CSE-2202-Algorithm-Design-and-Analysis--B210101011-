#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> coins = {25, 10, 5, 1};

    int amount;
    cout << "Enter the amount in cents: ";
    cin >> amount;

    int totalCoins = 0;
    cout << "Coins used: ";


    for (int coin : coins) {
        if (amount == 0)
            break;
        int count = amount / coin;
        if (count > 0) {
            cout << "\n" << count << " coin(s) of " << coin << " cent";
            if (count > 1) cout << "s";
        }
        totalCoins += count;
        amount %= coin;
    }

    cout << "\n\nMinimum number of coins required: " << totalCoins << endl;
    return 0;
}
