class Solution {
private:
    bool dfs(unordered_map<int, vector<int>>& mp,
             vector<int>& vis,
             vector<int>& inRec,
             stack<int>& st,
             int u) {

        vis[u] = 1;
        inRec[u] = 1;

        for (int v : mp[u]) {

            if (!vis[v]) {
                if (dfs(mp, vis, inRec, st, v))
                    return true;
            }
            else if (inRec[v]) {
                return true;  
            }
        }

        inRec[u] = 0;
        st.push(u);

        return false;
    }

public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {

        unordered_map<int, vector<int>> mp;

        for (auto &e : prerequisites) {
            int course = e[0];
            int prereq = e[1];

            mp[prereq].push_back(course);
        }

        vector<int> vis(V, 0);
        vector<int> inRec(V, 0);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(mp, vis, inRec, st, i))
                    return {};
            }
        }

        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};