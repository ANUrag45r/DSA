class Solution {
private:
    int solve(vector<int> &coins, int sum, int i, vector<vector<int>> &dp) {
        if (sum == 0)
            return 0;

        if (i == coins.size())
            return 1e9; 

        if (dp[i][sum] != -1)
            return dp[i][sum];

        if (coins[i] > sum) {
            return dp[i][sum] = solve(coins, sum, i + 1, dp);
        }

        int pick = 1 + solve(coins, sum - coins[i], i, dp);
        int notPick = solve(coins, sum, i + 1, dp);

        return dp[i][sum] = min(pick, notPick);
    }

public:
    int minCoins(vector<int> &coins, int sum) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));

        int ans = solve(coins, sum, 0, dp);

        return (ans >= 1e9) ? -1 : ans;
    }
};