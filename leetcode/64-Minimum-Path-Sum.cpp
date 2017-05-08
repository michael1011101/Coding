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
 * Title:64. Minimum Path Sum
    Given a m x n grid filled with non-negative numbers,
    find a path from top left to bottom right which minimizes the sum of all numbers along its path.

    Note: You can only move either down or right at any point in time.
 */

/** solution
    dp (easy)
 */



/*************************** Submit Part *****************************/
class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        int m = grid.size();
        if(m==0) return 0;
        int n = grid[0].size();
        int i,j;
        vector<vector<int> > dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for(i=1; i<n; ++i) dp[0][i] = dp[0][i-1]+grid[0][i];
        for(i=1; i<m; ++i) dp[i][0] = dp[i-1][0]+grid[i][0];

        for(i=1; i<m; ++i){
            for(j=1; j<n; ++j){
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[m-1][n-1];
    }
};
/*************************** Submit Part *****************************/

int main()
{
    vector<vector<int> > grids;
    int i,j;
    int m,n;
    int x;
    cin >> m >> n;
    for(i=0; i<m; ++i){
        vector<int> tmp;
        for(j=0; j<n; ++j){
            cin >> x;
            tmp.push_back(x);
        }
        grids.push_back(tmp);
    }

    Solution solution;
    cout << solution.minPathSum(grids) << endl;
    return 0;
}
