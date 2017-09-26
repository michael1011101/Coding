class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        if(row == 0)    return false;
        int col = board[0].size();
        if(col == 0)    return false;
        
        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                if(exist(board, i, j, word, 0)) return true;
            }
        }
        return false;
    }
private:
    bool exist(vector<vector<char>>& board, int x, int y, string word, int index){
        if(index >= word.length())  return true;
        if(x<0 || x>=board.size() || y<0 || y>= board[0].size())    return false;
        if(board[x][y] == word[index]){
            char c = board[x][y];
            board[x][y] = '#';
            bool ans = exist(board, x+1, y, word, index+1) || exist(board, x, y+1, word, index+1) ||
                exist(board, x-1, y, word, index+1) || exist(board, x, y-1, word, index+1);
            board[x][y] = c;
            return ans;
        }
        return false;
    }
};

