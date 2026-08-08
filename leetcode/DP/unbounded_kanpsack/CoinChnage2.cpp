class Solution {
private:
    int helper(int amount, vector<int>& coins, int idx, vector<vector<int>>& dp) {
        if (amount == 0) {
            return 1;
        }
        if (amount < 0 || idx >= coins.size()) {
            return 0; 
        }

        if (dp[idx][amount] != -1) {
            return dp[idx][amount];
        }

        int include = helper(amount - coins[idx], coins, idx, dp);
        int exclude = helper(amount, coins, idx + 1, dp);          

        return dp[idx][amount] = include + exclude;
    }

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1)); 
        return helper(amount, coins, 0, dp); 
    }
};
