class Solution {
private:
    void markRow(vector<vector<int>>& matrix, int row, int col, int i) {
        for (int k = 0; k < col; k++) {
            if (matrix[i][k] != 0) {
                matrix[i][k] = -999;
            }
        }
    }
    void markCol(vector<vector<int>>& matrix, int row, int col, int j) {
        for (int k = 0; k < row; k++) {
            if (matrix[k][j] != 0) {
                matrix[k][j] = -999;
            }
        }
    }

public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 0) {
                    markRow(matrix, row, col, i);
                    markCol(matrix, row, col, j);
                }
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == -999) {
                    matrix[i][j] = 0;
                }
            }
        }
        
    }
};