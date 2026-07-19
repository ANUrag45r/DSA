class Solution {
private:
    bool sol(vector<int>& arr, int sum, int i, vector<vector<int>> &v) {
        if (sum == 0)
            return true;

        if (i == arr.size())
            return false;

        if (sum < 0)
            return false;

        if (v[sum][i] != -1)
            return v[sum][i];

        return v[sum][i] = sol(arr, sum - arr[i], i + 1, v) ||
                           sol(arr, sum, i + 1, v);
    }

public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> v(sum + 1, vector<int>(n + 1, -1));

        return sol(arr, sum, 0, v);
    }
};