class Solution {
private:
    int solve(vector<int>& arr, int sum, int tempsum, int i,
              vector<vector<int>> &dp) {

        if (i == arr.size()) {
            if (sum == 0)
                return INT_MAX;
            return abs(sum - tempsum);
        }

        if (dp[sum][i] != -1)
            return dp[sum][i];

        int pick = solve(arr, sum - arr[i], tempsum + arr[i], i + 1, dp);
        int notPick = solve(arr, sum, tempsum, i + 1, dp);

        return dp[sum][i] = min(pick, notPick);
    }

public:
    int minDifference(vector<int>& arr) {
        int sum = 0;
        for (int x : arr)
            sum += x;

        vector<vector<int>> dp(sum + 1, vector<int>(arr.size() + 1, -1));

        return solve(arr, sum, 0, 0, dp);
    }
};