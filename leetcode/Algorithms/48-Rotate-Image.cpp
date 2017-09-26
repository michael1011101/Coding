class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int _size = matrix.size();
        if(_size <= 1)  return ;
        for(int i=0; i<_size/2; ++i){
            for(int j=i; j<_size-i-1; ++j){
                swap(matrix[i][j], matrix[_size-i-1-(j-i)][i]);
                swap(matrix[_size-i-1-(j-i)][i], matrix[_size-i-1][_size-i-1-(j-i)]);
                swap(matrix[_size-i-1][_size-i-1-(j-i)], matrix[j][_size-i-1]);
            }
        }
    }
};

