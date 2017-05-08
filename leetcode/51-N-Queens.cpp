#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Title:51. N-Queens
    The n-queens puzzle is the problem of placing n queens on an n¡Án chessboard such that no two queens attack each other.

    Given an integer n, return all distinct solutions to the n-queens puzzle.

    Each solution contains a distinct board configuration of the n-queens' placement,
    where 'Q' and '.' both indicate a queen and an empty space respectively.

    For example,
    There exist two distinct solutions to the 4-queens puzzle:

    [
     [".Q..",  // Solution 1
      "...Q",
      "Q...",
      "..Q."],

     ["..Q.",  // Solution 2
      "Q...",
      "...Q",
      ".Q.."]
    ]
 */

/** solution
    dfs backtracking
 */


/*************************** Submit Part *****************************/
class Solution {
private:
    vector<vector<string> > ans;

    vector<string> toVector(int n,  vector<int> tmp){
        string str(n, '.');
        vector<string> result;
        for(int i=0; i<n; ++i){
            str[tmp[i]] = 'Q';
            result.push_back(str);
            str[tmp[i]] = '.';
        }
        return result;
    }

    bool judge(int now, int index, vector<int> pos){
        int i;
        for(i=0; i<now; ++i){
            if(((i-pos[i])==(now-index)) || ((i+pos[i])==(now+index))){
                return false;
            }
        }
        return true;
    }

    void dfs(int n, int now, vector<int> pos, vector<bool> visit){
        if(now >= n){
            ans.push_back(toVector(n, pos));
            return ;
        }

        int i;
        for(i=0; i<n; ++i){
            if(!visit[i] && judge(now, i, pos)){
                pos[now] = i;
                visit[i] = true;
                dfs(n, now+1, pos, visit);
                visit[i] = false;
            }
        }
    }
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<int> pos(n+1);
        vector<bool> visit(n+1);

        dfs(n,0,pos,visit);
        return ans;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x;
    cin >> x;
    Solution solution;
    vector<vector<string> > ans = solution.solveNQueens(x);
    for(vector<vector<string> >::iterator it = ans.begin(); it!=ans.end(); ++it){
        vector<string> tmp = *it;
        for(vector<string>::iterator iit = tmp.begin(); iit!=tmp.end(); ++iit){
            cout << *iit << endl;
        }
    }
    return 0;
}
