class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(row == 0)    return false;
        int col = matrix[0].size();
        if(col == 0)    return false;
        
        bool flag = false;
        
        for(int i=0, j=col-1; i<row && j>=0; ){
            if(target == matrix[i][j]){
                flag = true;
                break;
            }
            else if(matrix[i][j] > target) --j;
            else ++i;
        }
        
        return flag;
    }
};

