class Solution {
private:
    void dfs(int i, int j, vector<vector<int>>& image, int color,
             int originalColor) {
        int row = image.size();
        int col = image[0].size();
        if (i < 0 || j < 0 || i >= row || j >= col ||
            image[i][j] != originalColor || image[i][j] == color) {
            return;
        }
        image[i][j] = color;
        dfs(i - 1, j, image, color, originalColor);
        dfs(i + 1, j, image, color, originalColor);
        dfs(i, j - 1, image, color, originalColor);
        dfs(i, j + 1, image, color, originalColor);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int originalColor = image[sr][sc];
        dfs(sr, sc, image, color, originalColor);
        return image;
    }
};