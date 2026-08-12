class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        unordered_map<int, vector<pair<int, int>>> mp;

        for (auto &it : times) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            mp[u].push_back({v, wt});
        }

        vector<int> result(n + 1, INT_MAX);

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        result[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {

            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Ignore stale entry
            if (time > result[node])
                continue;

            for (auto &it : mp[node]) {

                int nnode = it.first;
                int wt = it.second;

                int newTime = time + wt;

                if (result[nnode] > newTime) {

                    result[nnode] = newTime;

                    pq.push({newTime, nnode});
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {

            if (result[i] == INT_MAX)
                return -1;

            ans = max(ans, result[i]);
        }

        return ans;
    }
};