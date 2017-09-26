class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // the number should not be repeated in each row, col and block.
        // number(i, j) is in the i row, and in the j col, and in the i/3*+j/3 block.
        vector<unordered_set<char> > row(9);
        vector<unordered_set<char> > col(9);
        vector<unordered_set<char> > block(9);
        
        char c;
        int _size = board.size();
        for(int i=0; i<_size; ++i){
            for(int j=0; j<_size; ++j){
                c = board[i][j];
                if(c != '.'){
                    if(row[i].count(c) > 0 || col[j].count(c) > 0 || block[i/3*3 + j/3].count(c) > 0){
                        return false;
                    }
                    else{
                        row[i].insert(c);
                        col[j].insert(c);
                        block[i/3*3 + j/3].insert(c);
                    }
                }
            }
        }
        return true;
    }
};

