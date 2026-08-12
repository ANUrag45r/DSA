class Solution {
private:

    void DFS(unordered_map<int, vector<int>>& mp,
             vector<int>& vis,
             vector<int>& ans,
             int u) {

        if (vis[u] == 1) {
            return;
        }

        vis[u] = 1;
        ans.push_back(u);

        for (auto &it : mp[u]) {
            if (!vis[it]) {
                DFS(mp, vis, ans, it);
            }
        }
    }

public:

    vector<int> dfs(vector<vector<int>>& adj) {

        int v = adj.size();

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < v; i++) {

            for (auto &it : adj[i]) {
                mp[i].push_back(it);
            }
        }

        vector<int> vis(v, 0);

        vector<int> ans;

        for (int i = 0; i < v; i++) {

            if (!vis[i]) {
                DFS(mp, vis, ans, i);
            }
        }

        return ans;
    }
};