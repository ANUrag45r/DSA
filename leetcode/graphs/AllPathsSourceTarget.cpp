class Solution {
private: 
    void dfs(unordered_map<int, vector<int>>& mp,
             int it,
             vector<int>& temp,
             vector<vector<int>>& ans,
             int target) {

        temp.push_back(it);

        if (it == target) {
            ans.push_back(temp);
            temp.pop_back();
            return; 
        }

        for (auto &cur : mp[it]) {
            dfs(mp, cur, temp, ans, target);
        }

        temp.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        unordered_map<int, vector<int>> mp;

        int n = graph.size();

        for (int i = 0; i < n; i++) {
            for (auto &it : graph[i]) {
                mp[i].push_back(it);
            }
        }

        vector<vector<int>> ans;
        vector<int> temp;

        dfs(mp, 0, temp, ans, n - 1);

        return ans;
    }
};