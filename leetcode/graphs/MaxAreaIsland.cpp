class Solution {
private:
    void dfs(vector<vector<int>>& grid, int sr, int sc, int& ans) {
        if ((sr < 0 || sr >= grid.size()) || (sc < 0 || sc >= grid[0].size()) ||
            grid[sr][sc] == 0)
            return;
        grid[sr][sc] = 0;
        ans+=1;
        dfs(grid,sr+1,sc,ans);
        dfs(grid,sr-1,sc,ans);
        dfs(grid,sr,sc-1,ans);
        dfs(grid,sr,sc+1,ans);
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int temp = 0;
                    dfs(grid,i,j,temp);
                    ans = max(ans,temp);
                }
            }
        }
        return ans;
    }
};