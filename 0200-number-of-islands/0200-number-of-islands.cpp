class Solution {
private:
    void dfs(int i, int j, vector<vector<char>>& vis, vector<vector<char>>& grid){
        int row = grid.size();
        int col = grid[0].size();
        if(i<0 || j<0 || i>=row || j>=col || grid[i][j] == '0' || vis[i][j] == '1'){
            return;
        }        
        vis[i][j] = '1';
        dfs(i-1,j,vis,grid);
        dfs(i+1,j,vis,grid);
        dfs(i,j-1,vis,grid);
        dfs(i,j+1,vis,grid);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int islands = 0;
        vector<vector<char>> vis(row, vector<char>(col, '0'));
        for(int i = 0; i< row; i++){
            for(int j = 0; j<col; j++){
                if(grid[i][j] == '1' && vis[i][j] == '0'){
                    islands++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return islands;
        
    }
};