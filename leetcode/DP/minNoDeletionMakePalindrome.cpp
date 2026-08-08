class Solution {
private:
    int solve(string &s, string &s1, int i, int j, vector<vector<int>> &dp) {
        if (i < 0 || j < 0) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (s[i] == s1[j]) {
            return dp[i][j] = 1 + solve(s, s1, i - 1, j - 1, dp);
        }

        return dp[i][j] = max(solve(s, s1, i - 1, j, dp),
                              solve(s, s1, i, j - 1, dp));
    }

public:
    int minInsertions(string s) {

        string s1 = s;
        reverse(s1.begin(), s1.end());

        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        int lcs = solve(s, s1, n - 1, n - 1, dp);

        return n - lcs;
    }
};