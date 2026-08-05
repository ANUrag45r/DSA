class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {

        unordered_map<int, vector<int>> mp;

        for (auto &e : prerequisites) {
            int u = e[1];
            int v = e[0];

            mp[u].push_back(v);
        }

        vector<int> ind(V, 0);

        for (auto &it : mp) {
            for (int v : it.second) {
                ind[v]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < V; i++) {
            if (ind[i] == 0)
                q.push(i);
        }

        vector<int> ans;

        while (!q.empty()) {

            int x = q.front();
            q.pop();

            ans.push_back(x);

            for (int v : mp[x]) {

                ind[v]--;

                if (ind[v] == 0) {
                    q.push(v);
                }
            }
        }

        return ans.size() == V;
    }
};