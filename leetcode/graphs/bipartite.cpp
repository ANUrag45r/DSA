class Solution {
private:
    bool bipartite(unordered_map<int, vector<int>>& mp,
                   vector<int>& color,
                   int u,
                   int curcolor) {

        color[u] = curcolor;

        for (auto &it : mp[u]) {

            if (color[it] == curcolor)
                return false;

            if (color[it] == -1) {
                if (!bipartite(mp, color, it, !curcolor))
                    return false;
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {

        unordered_map<int, vector<int>> mp;

        int V = graph.size();

        for (int i = 0; i < V; i++) {
            mp[i] = graph[i];
        }

        vector<int> color(V, -1);

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!bipartite(mp, color, i, 1))
                    return false;
            }
        }

        return true;
    }
};