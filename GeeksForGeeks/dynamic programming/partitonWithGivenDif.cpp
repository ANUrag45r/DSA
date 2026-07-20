class Solution {
private:
    int totalSum;

    int solve(vector<int>& arr, int diff, int i, int currSum,
              vector<vector<int>> &dp) {

        if (i == arr.size()) {
            int otherSum = totalSum - currSum;
            return ((currSum - otherSum) == diff);
        }

        if (dp[i][currSum] != -1)
            return dp[i][currSum];

        int pick = solve(arr, diff, i + 1, currSum + arr[i], dp);
        int notPick = solve(arr, diff, i + 1, currSum, dp);

        return dp[i][currSum] = pick + notPick;
    }

public:
    int countPartitions(vector<int>& arr, int diff) {
        totalSum = 0;
        for (int x : arr)
            totalSum += x;

        int n = arr.size();

        vector<vector<int>> dp(n + 1, vector<int>(totalSum + 1, -1));

        return solve(arr, diff, 0, 0, dp) ;
    }
};