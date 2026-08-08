class Solution {
    string solve(string &s1, string &s2, int i, int j,
                 vector<vector<string>>& dp) {

        if (i < 0 || j < 0)
            return "";

        if (dp[i][j] != "#")
            return dp[i][j];

        if (s1[i] == s2[j]) {
            return dp[i][j] = string(1, s1[i]) +
                              solve(s1, s2, i - 1, j - 1, dp);
        }

        string left = solve(s1, s2, i - 1, j, dp);
        string right = solve(s1, s2, i, j - 1, dp);

        if (left.size() >= right.size())
            return dp[i][j] = left;

        return dp[i][j] = right;
    }

public:
    bool isSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<string>> dp(n, vector<string>(m, "#"));

        string ans = solve(s1, s2, n - 1, m - 1, dp);

        return ans == s1;
    }
};