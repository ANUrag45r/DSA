class Solution {
public:

    string solve(string &s1, string &s2,
                 int i, int j,
                 vector<vector<string>> &dp,
                 vector<vector<int>> &vis){

        if(i<0 || j<0)
            return "";

        if(vis[i][j])
            return dp[i][j];

        vis[i][j]=1;

        if(s1[i]==s2[j]){
            return dp[i][j]=solve(s1,s2,i-1,j-1,dp,vis)+s1[i];
        }

        string left=solve(s1,s2,i-1,j,dp,vis);

        string right=solve(s1,s2,i,j-1,dp,vis);

        if(left.size()>right.size())
            return dp[i][j]=left;

        return dp[i][j]=right;
    }

    string longestCommonSubsequence(string s1,string s2){

        int n=s1.size();
        int m=s2.size();

        vector<vector<string>> dp(n,vector<string>(m));
        vector<vector<int>> vis(n,vector<int>(m,0));

        return solve(s1,s2,n-1,m-1,dp,vis);
    }
};