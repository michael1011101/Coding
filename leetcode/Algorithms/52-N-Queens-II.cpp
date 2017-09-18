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
 * Title:52. N-Queens II
    Follow up for N-Queens problem.

    Now, instead outputting board configurations, return the total number of distinct solutions.
 */

/** solution
    dfs backtracking
 */


/*************************** Submit Part *****************************/
class Solution {
private:
    int ans;

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
            ans++;
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
    int totalNQueens(int n) {
        vector<int> pos(n+1);
        vector<bool> visit(n+1);
        ans = 0;
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
    cout << solution.totalNQueens(x) << endl;
    return 0;
}
