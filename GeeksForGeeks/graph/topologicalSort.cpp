class Solution {
	private:
	void dfs(vector<int>&vis, int u, unordered_map<int, vector<int>> &mp, stack<int> &st)
	{
		vis[u] = 1;
		for (auto &v : mp[u]) {
			if (!vis[v]) {
				dfs(vis, v, mp, st);
			}
		}
		st.push(u);
	}
	public:
	vector<int> topoSort(int V, vector<vector<int>> & edges) {
		// code here
		unordered_map<int, vector<int>> mp;
		for (auto &e : edges) {
			int u = e[0];
			int v = e[1];
			mp[u].push_back(v);
		}
		vector<int> ans;
		stack<int> st;
		vector<int> vis(V, 0);
		for (int i = 0; i<V; i++) {
			if (!vis[i]) {
				dfs(vis, i, mp, st);
			}
		}
		while (!st.empty()) {
			int x = st.top();
			st.pop();
			ans.push_back(x);
		}
		return ans;
	}
};
