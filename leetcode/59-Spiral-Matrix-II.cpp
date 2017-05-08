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
 * Title:59. Spiral Matrix II
    Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

    For example,
    Given n = 3,

    You should return the following matrix:
    [
     [ 1, 2, 3 ],
     [ 8, 9, 4 ],
     [ 7, 6, 5 ]
    ]
 */

/** solution
    Ä£Äâ
 */



/*************************** Submit Part *****************************/
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > ans(n,vector<int>(n));
        int i,j;
        int index = 0;
        int left, right, top, bottom;

        i = j = 0;
        left = top = 0;
        right = bottom = n-1;
        while(true){
            for(j=left; j<=right; ++j) ans[top][j] = ++index;
            if(++top > bottom) break;

            for(i=top; i<=bottom; ++i) ans[i][right] = ++index;
            if(--right < left) break;

            for(j=right; j>=left; --j) ans[bottom][j] = ++index;
            if(--bottom < top) break;

            for(i=bottom; i>=top; --i) ans[i][left] = ++index;
            if(++left > right) break;
        }
        return ans;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x;
    cin >> x;
    Solution solution;
    vector<vector<int> > result;
    result = solution.generateMatrix(x);
    for(vector<vector<int> >::iterator it=result.begin(); it!=result.end(); ++it){
        vector<int> tmp = *it;
        for(vector<int>::iterator iit=tmp.begin(); iit!=tmp.end(); ++iit){
            cout << *iit << ' ';
        }
        cout << endl;
    }
    return 0;
}
