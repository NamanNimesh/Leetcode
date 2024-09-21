class Solution {
public:
    vector<int> rowList(int i)
    {
        vector<int> rowAns;
        long long res = 1;
        rowAns.push_back(1);
        for(int col = 1; col<i;col++ )
        {
            res = res*(i-col);
            res = res/col;
            rowAns.push_back(res);
            
        }
        return rowAns;
    }
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> ans;
        for(int i = 1; i <= numRows;i++)
        {
             ans.push_back(rowList(i));
        }
        return ans;
        
        
    }
};