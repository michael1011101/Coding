#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Title:463. Island Perimeter
     You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.
     Grid cells are connected horizontally/vertically (not diagonally).
     The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
     The island doesn't have "lakes" (water inside that isn't connected to the water around the island).
     One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100.
     Determine the perimeter of the island.

    Example:

    [[0,1,0,0],
     [1,1,1,0],
     [0,1,0,0],
     [1,1,0,0]]

    Answer: 16
 */

/** solution
    判断1的位置，上下左右是不是0或者边界，如果是+1，否则+0
 */



/*************************** Submit Part *****************************/
class Solution {
private:
    int tx[4] = {-1,0,0,1};
    int ty[4] = {0,-1,1,0};
public:
    int islandPerimeter(vector<vector<int> >& grid) {
        int m, n;
        m = grid.size();
        if(0 == m) return 0;
        n = grid[0].size();

        int i,j,k,x,y;
        int ans = 0;
        for(i=0; i<m; ++i){
            for(j=0; j<n; ++j){
                if(grid[i][j] == 1){
                    for(k=0; k<4; ++k){
                        x = tx[k] + i;
                        y = ty[k] + j;
                        if(x<0||y<0||x>=m||y>=n) ans++;
                        else if(0 == grid[x][y]) ans++;
                    }
                }
            }
        }
        return ans;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int m,n,x;
    vector<vector<int> > grids;
    cin >> m >> n;
    for(int i=0; i<m; ++i){
        vector<int> tmp;
        for(int j=0; j<n; ++j){
            cin >> x;
            tmp.push_back(x);
        }
        grids.push_back(tmp);
    }

    Solution solution;
    cout << solution.islandPerimeter(grids) << endl;
    return 0;
}
