#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <unordered_set>
#include <algorithm>
using namespace std;

/**
 * Title:118. Pascal's Triangle
    Given numRows, generate the first numRows of Pascal's triangle.

    For example, given numRows = 5,
    Return

    [
         [1],
        [1,1],
       [1,2,1],
      [1,3,3,1],
     [1,4,6,4,1]
    ]

 */

/** solution

 */



/*************************** Submit Part *****************************/
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ans;
        int i, j;

        for(i=0; i<numRows; ++i){
            vector<int> tmp;
            for(j=0; j<=i; ++j){
                if(j==0 || j==i) tmp.push_back(1);
                else tmp.push_back(ans[i-1][j-1]+ans[i-1][j]);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x;
    vector<vector<int> > ans;
    while(cin >> x){
        Solution solution;
        ans = solution.generate(x);
        for(int i=0; i<x; ++i){
            for(int j=0; j<=i; ++j){
                cout << ans[i][j] << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}
