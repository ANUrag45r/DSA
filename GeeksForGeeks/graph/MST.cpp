class Solution {
    typedef pair<int, int> P; 

public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        
        unordered_map<int, vector<pair<int, int>>> mp;

        for (auto &it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            mp[u].push_back({v, wt});
             mp[v].push_back({u, wt});
           
        }

        int ans = 0;

        priority_queue<P, vector<P>, greater<P>> pq;

        vector<int> vis(V, 0);

        pq.push({0, 0});

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int wt = it.first;
            int node = it.second;

            if (vis[node])
                continue;

            vis[node] = 1;
            ans += wt;

            for (auto &i : mp[node]) {
                int nextNode = i.first;
                int edgeWt = i.second;

                if (!vis[nextNode]) {
                    pq.push({edgeWt, nextNode});
                }
            }
        }

        return ans;
    }
};