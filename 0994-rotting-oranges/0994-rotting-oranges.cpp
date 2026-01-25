class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int,int>> q;
        int cnt = 0;
        for(int i = 0; i<row;i++){
            for(int j = 0; j<col; j++){
                if(grid[i][j] == 1){
                    cnt++;
                }
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        if(cnt == 0) return 0;
        if(q.empty()) return -1;

        int minute = -1;

        //cover all four direction 
        vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [x, y] = q.front();
                q.pop();
                for(auto [dx,dy]: dirs){
                    int i = x+dx;
                    int j = y+dy;
                    if(i>=0 && i<row && j>=0 && j<col && grid[i][j] == 1){
                        grid[i][j] =2;
                        cnt--;
                        q.push({i,j});
                    }
                }
            }
            minute++;
        }
        if(cnt == 0){
            return minute;
        }
    return -1;

    
        
    }
};