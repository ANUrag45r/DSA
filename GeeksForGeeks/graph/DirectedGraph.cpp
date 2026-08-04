class Solution {
private:
    void solve(unordered_map<int, vector<int>>& mp,
               vector<int>& ind,
               int& cnt,
               queue<int>& q) {

        for (int i = 0; i < ind.size(); i++) {
            if (ind[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {

            int x = q.front();
            q.pop();

            cnt++;

            for (auto it : mp[x]) {
                ind[it]--;

                if (ind[it] == 0) {
                    q.push(it);
                }
            }
        }
    }

public:
    bool isCyclic(int V, vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> mp;

        for (auto &it : edges) {
            int u = it[0];
            int v = it[1];

            mp[u].push_back(v);
        }

        vector<int> ind(V, 0);

        for (auto &it : mp) {
            for (int v : it.second) {
                ind[v]++;
            }
        }

        int cnt = 0;
        queue<int> q;

        solve(mp, ind, cnt, q);

        return cnt != V;
    }
};