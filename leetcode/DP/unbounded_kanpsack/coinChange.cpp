class Solution {
public:
    int solve(vector<int>& coins, int n, int amount,
              vector<vector<int>>& dp) {

        if (amount == 0)
            return 0;

        if (n < 0 || amount < 0)
            return INT_MAX / 2;

        if (dp[n][amount] != -1)
            return dp[n][amount];

        if (coins[n] > amount) {
            return dp[n][amount] =
                solve(coins, n - 1, amount, dp);
        }

        return dp[n][amount] = min(
            1 + solve(coins, n, amount - coins[n], dp),
            solve(coins, n - 1, amount, dp)
        );
    }

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        vector<vector<int>> dp(
            n, vector<int>(amount + 1, -1)
        );

        int ans = solve(coins, n - 1, amount, dp);

        return ans >= INT_MAX / 2 ? -1 : ans;
    }
};