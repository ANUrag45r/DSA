class Solution {
    
  private:
  
  bool ispalindrome(string &s, int i ,int j){
      if(i>=j){
          return true;
      }
      if(s[i] == s[j]){
          return ispalindrome(s,i+1,j-1);
      }
      else return false ;
  }
  
  int solve(string &s, int i, int j, vector<vector<int>>&dp){
      if(i>=j){
          return 0;
      }
      if(ispalindrome(s,i,j)==true){
          return 0;
      }
      if(dp[i][j]!=-1){
          return dp[i][j];
      }
      int ans= INT_MAX;
      for(int k=i;k<=j-1;k++){
          int temp = 1+solve(s,i,k,dp)+solve(s,k+1,j,dp);
          ans = min(ans,temp);
      }
      return dp[i][j] = ans;
  }
  public:
    int palPartition(string &s) {
        // code here
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(s,0,n-1,dp);
    }
};