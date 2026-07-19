class Solution {
private:
    bool solve(vector<int>& arr, int sum, int i, vector<vector<int>> &v) {
        if (sum == 0) return true;
        if (sum < 0) return false;
        if (i == arr.size()) return false;

        if (v[sum][i] != -1)
            return v[sum][i];

        return v[sum][i] =
               solve(arr, sum - arr[i], i + 1, v) ||
               solve(arr, sum, i + 1, v);
    }

public:
    bool equalPartition(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }

        if (sum % 2 != 0) return false;

        sum /= 2;

        vector<vector<int>> v(sum + 1, vector<int>(n + 1, -1));

        return solve(arr, sum, 0, v);
    }
};