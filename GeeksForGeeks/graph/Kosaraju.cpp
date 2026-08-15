class Solution {
private:

    // Step 1: DFS and store nodes according to finishing time
    void dfsf(unordered_map<int, vector<int>>& mp,
              stack<int>& st,
              vector<int>& vis,
              int u) {

        vis[u] = 1;

        for (auto &it : mp[u]) {
            if (!vis[it]) {
                dfsf(mp, st, vis, it);   // BUG: should pass 'it', not 'u'
            }
        }

        st.push(u);
    }

    // Step 3: DFS on reversed graph
    void DFS(vector<int>& vis,
             int u,
             unordered_map<int, vector<int>>& mpp) {

        vis[u] = 1;

        for (auto &it : mpp[u]) {
            if (!vis[it]) {
                DFS(vis, it, mpp);
            }
        }
    }

public:
    int kosaraju(int V, vector<vector<int>> &edges) {

        // Create original graph
        unordered_map<int, vector<int>> mp;

        for (auto &it : edges) {
            int u = it[0];
            int v = it[1];

            mp[u].push_back(v);
        }

        // --------------------------------
        // STEP 1: Find finishing order
        // --------------------------------

        stack<int> st;
        vector<int> visited(V, 0);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfsf(mp, st, visited, i);
            }
        }

        // --------------------------------
        // STEP 2: Reverse the graph
        // --------------------------------

        unordered_map<int, vector<int>> mpp;

        for (auto &it : mp) {

            int u = it.first;

            for (auto &v : it.second) {
                mpp[v].push_back(u);
            }
        }

        // --------------------------------
        // STEP 3: DFS according to stack order
        // --------------------------------

        int ans = 0;
        vector<int> vis(V, 0);

        while (!st.empty()) {

            int node = st.top();
            st.pop();                  // VERY IMPORTANT

            if (!vis[node]) {
                DFS(vis, node, mpp);
                ans++;
            }
        }

        return ans;
    }
};