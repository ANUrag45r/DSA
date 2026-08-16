class Solution {
private:
    void dfs(int i, vector<int>& vis,
             unordered_map<int, vector<int>>& mp) {

        vis[i] = 1;

        for (auto &it : mp[i]) {
            if (!vis[it]) {
                dfs(it, vis, mp);
            }
        }
    }

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        unordered_map<int, vector<int>> mp;
        int n = rooms.size();

        for (int i = 0; i < n; i++) {
            mp[i] = rooms[i];
        }

        vector<int> vis(n, 0);
        int compo = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, vis, mp);
                compo++;
            }
        }

        if (compo > 1)
            return false;

        return true;
    }
};