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
 * Title:63. Unique Paths II
    Follow up for "Unique Paths":

    Now consider if some obstacles are added to the grids. How many unique paths would there be?

    An obstacle and empty space is marked as 1 and 0 respectively in the grid.

    For example,
    There is one obstacle in the middle of a 3x3 grid as illustrated below.

    [
      [0,0,0],
      [0,1,0],
      [0,0,0]
    ]
    The total number of unique paths is 2.
 */

/** solution
    dp
 */



/*************************** Submit Part *****************************/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m==0) return 0;
        int n = obstacleGrid[0].size();
        int i,j;
        vector<vector<int> > dp(m, vector<int>(n));

        dp[0][0] = obstacleGrid[0][0]^1;
        for(i=1; i<n; ++i){
            dp[0][i] = dp[0][i-1];
            if(obstacleGrid[0][i]==1)
                dp[0][i] = 0;
        }

        for(i=1; i<m; ++i){
            dp[i][0] = dp[i-1][0];
            if(obstacleGrid[i][0]==1)
                dp[i][0] = 0;
        }

        for(i=1; i<m; ++i){
            for(j=1; j<n; ++j){
                if(obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
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
    cout << solution.uniquePathsWithObstacles(grids) << endl;
    return 0;
}
