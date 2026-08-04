class Solution {
private:
    void dfs(unordered_map<int, vector<int>>& mp,
             vector<int>& vis, int u) {

        vis[u] = 1;

        for (int v : mp[u]) {
            if (!vis[v]) {
                dfs(mp, vis, v);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && isConnected[i][j] == 1) {
                    mp[i].push_back(j);
                }
            }
        }

        vector<int> vis(n, 0);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(mp, vis, i);
                ans++;
            }
        }

        return ans;
    }
};