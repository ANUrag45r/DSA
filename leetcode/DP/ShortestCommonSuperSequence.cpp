class Solution {
private:
    string solve(string &s1, string &s2, int i, int j, vector<vector<string>> &dp) {

        if (i < 0)
            return s2.substr(0, j + 1);

        if (j < 0)
            return s1.substr(0, i + 1);

        if (dp[i][j] != "#")
            return dp[i][j];

        if (s1[i] == s2[j]) {
            return dp[i][j] = solve(s1, s2, i - 1, j - 1, dp) + s1[i];
        }

        string take1 = solve(s1, s2, i - 1, j, dp) + s1[i];

        string take2 = solve(s1, s2, i, j - 1, dp) + s2[j];

        if (take1.length() < take2.length())
            return dp[i][j] = take1;

        return dp[i][j] = take2;
    }

public:
    string shortestCommonSupersequence(string str1, string str2) {

        int n = str1.size();
        int m = str2.size();

        vector<vector<string>> dp(n, vector<string>(m, "#"));

        return solve(str1, str2, n - 1, m - 1, dp);
    }
};