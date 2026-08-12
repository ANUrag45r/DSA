class Solution {
private:

    void dfs(vector<vector<int>>& image, int sr, int sc,
             int originalColor, int color) {

        if (sr < 0 || sr >= image.size() ||
            sc < 0 || sc >= image[0].size() ||
            image[sr][sc] != originalColor) {
            return;
        }

        image[sr][sc] = color;

        dfs(image, sr + 1, sc, originalColor, color);
        dfs(image, sr, sc + 1, originalColor, color);
        dfs(image, sr - 1, sc, originalColor, color);
        dfs(image, sr, sc - 1, originalColor, color);
    }

public:

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                   int sr, int sc, int color) {

        int n = image.size();
        int m = image[0].size();

        if (sr < 0 || sr >= n || sc < 0 || sc >= m)
            return image;

        int originalColor = image[sr][sc];

        
        if (originalColor == color)
            return image;

        dfs(image, sr, sc, originalColor, color);

        return image;
    }
};