class NumMatrix {
private:
    vector<vector<int> > sum;
public:
    NumMatrix(vector<vector<int>> matrix) {
        int row = matrix.size();
        if(row > 0){
            int col = matrix[0].size();
            sum.push_back(vector<int>(col+1, 0));
            for(int i=0; i<row; ++i){
                vector<int> tmp(col+1, 0);
                for(int j=0; j<col; ++j){
                    tmp[j+1] = (matrix[i][j] + sum[i][j+1] + tmp[j] - sum[i][j]);
                }
                sum.push_back(tmp);
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2+1][col2+1] - sum[row2+1][col1] - sum[row1][col2+1] + sum[row1][col1];
    }
};
