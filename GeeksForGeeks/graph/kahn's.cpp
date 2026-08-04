class Solution {
private:
    void bfs(unordered_map<int, vector<int>>& mp,
             vector<int>& indegree,
             vector<int>& ans,
             queue<int>& q) {

        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {

            int x = q.front();
            q.pop();

            ans.push_back(x);

            for (auto it : mp[x]) {

                indegree[it]--;

                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
    }

public:
    vector<int> findOrder(int V, vector<vector<int>>& adj) {

        unordered_map<int, vector<int>> mp;

        for (auto &e : adj) {
            int u = e[0];
            int v = e[1];

            mp[u].push_back(v);
        }

        vector<int> indegree(V, 0);

        for (int i = 0; i < V; i++) {
            for (auto it : mp[i]) {
                indegree[it]++;
            }
        }

        vector<int> ans;
        queue<int> q;

        bfs(mp, indegree, ans, q);

        if (ans.size() != V)
            return {};

        return ans;
    }
};