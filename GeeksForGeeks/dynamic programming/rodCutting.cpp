class Solution {
private:
    int solve(vector<int>& prices, int tlen, int i,
              vector<vector<int>> &dp) {

        int n = prices.size();

        if (tlen > n)
            return INT_MIN;

        if (tlen == n)
            return 0;

        if (i > n)
            return INT_MIN;

        if (dp[tlen][i] != -1)
            return dp[tlen][i];

        int take = prices[i - 1] + solve(prices, tlen + i, i, dp);
        int notTake = solve(prices, tlen, i + 1, dp);

        return dp[tlen][i] = max(take, notTake);
    }

public:
    int cutRod(vector<int> &price) {

        int n = price.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 2, -1));

        return solve(price, 0, 1, dp);
    }
};