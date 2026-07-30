class Solution {
private:
    int solve(string &s, string &s2, int i, int j, vector<vector<int>> &dp) {

        if (i < 0 || j < 0) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (s[i] == s2[j]) {
            return dp[i][j] = 1 + solve(s, s2, i - 1, j - 1, dp);
        }

        return dp[i][j] = max(solve(s, s2, i - 1, j, dp),
                              solve(s, s2, i, j - 1, dp));
    }

public:
    int longestPalindromeSubseq(string s) {

        string s2 = s;
        reverse(s2.begin(), s2.end());

        int n = s.size();
        int m = s2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int ans = solve(s, s2, n - 1, m - 1, dp);

        return ans;
    }
};