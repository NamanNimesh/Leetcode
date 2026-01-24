class Solution {
private:
    void dfs(int i, int j, vector<vector<char>>& vis,
             vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        // FIRST: boundary + stop checks
        if (i < 0 || j < 0 || i >= row || j >= col || grid[i][j] == '0' ||
            vis[i][j] == '1') {
            return;
        }

        vis[i][j] = '1'; // mark visited AFTER checks

        dfs(i - 1, j, vis, grid); // up
        dfs(i + 1, j, vis, grid); // down
        dfs(i, j - 1, vis, grid); // left
        dfs(i, j + 1, vis, grid); // right
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<char>> vis(row, vector<char>(col, '0'));
        int islands = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1' && vis[i][j] == '0') {
                    islands++;
                    dfs(i, j, vis, grid);
                }
            }
        }
        return islands;
    }
};