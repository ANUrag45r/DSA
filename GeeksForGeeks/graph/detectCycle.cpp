class Solution {
private:
    bool dfs(unordered_map<int, vector<int>>& adj, int u, int parent,
             vector<int>& vis) {

        vis[u] = 1;

        for (int v : adj[u]) {

            if (!vis[v]) {
                if (dfs(adj, v, u, vis))
                    return true;
            }
            else if (v != parent) {
                return true;
            }
        }

        return false;
    }

public:
    bool isCycle(int V, vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> adj;

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(adj, i, -1, vis))
                    return true;
            }
        }

        return false;
    }
};