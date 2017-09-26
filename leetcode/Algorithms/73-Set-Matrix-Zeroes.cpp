class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int mSize = matrix.size();
        if(mSize == 0)  return;
        int nSize = matrix[0].size();
        
        bool firstRow, firstCol;
        
        firstRow = firstCol = false;
        for(int i=0; i<nSize; ++i){
            if(matrix[0][i] == 0)   firstRow = true;
        }
        for(int i=0; i<mSize; ++i){
            if(matrix[i][0] == 0)   firstCol = true;
        }
        
        for(int i=1; i<mSize; ++i){
            for(int j=1; j<nSize; ++j){
                if(matrix[i][j] == 0){
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }
        
        for(int i=1; i<mSize; ++i){
            for(int j=1; j<nSize; ++j){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(firstRow){
            for(int i=0; i<nSize; ++i){
                matrix[0][i] = 0;
            }
        }
        
        if(firstCol){
            for(int i=0; i<mSize; ++i){
                matrix[i][0] = 0;
            }
        }
    }
};

