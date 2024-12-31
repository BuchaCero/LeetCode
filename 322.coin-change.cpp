#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    const int MAX = 1000000;
    int coinChange(vector<int>& coins, int amount) {
        // dp[i] : 組成 i 元所需的最小 coin 數
        vector<int> dp(amount + 1, MAX);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int c : coins) {
                if (i - c >= 0) {
                    dp[i] = min(dp[i], dp[i - c] + 1);
                }
            }
        }
        return (dp[amount] >= MAX) ? -1 : dp[amount];
    }
};

int main() {
    Solution sol;

    vector<int> coins;
    string s;
    getline(cin, s);
    istringstream iss(s);
    int num;
    while (iss >> num) {
        coins.push_back(num);
    }
    int amount;
    cin >> amount;

    cout << sol.coinChange(coins, amount) << endl;
}