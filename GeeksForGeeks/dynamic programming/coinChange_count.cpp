class Solution {
private:
    int solve(vector<int>& coins, int sum, int i, vector<vector<int>>& dp) {
        if (sum == 0)
            return 1;

        if (i == coins.size())
            return 0;

        if (dp[sum][i] != -1)
            return dp[sum][i];

        if (coins[i] > sum) {
            return dp[sum][i] = solve(coins, sum, i + 1, dp);
        }

        int pick = solve(coins, sum - coins[i], i, dp);
        int notpick = solve(coins, sum, i + 1, dp);

        return dp[sum][i] = pick + notpick;
    }

public:
    int count(vector<int>& coins, int sum) {
        int n = coins.size();
        vector<vector<int>> dp(sum + 1, vector<int>(n, -1));
        return solve(coins, sum, 0, dp);
    }
};