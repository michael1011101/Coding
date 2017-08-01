#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

/**
 * Title: 119. Pascal's Triangle II
    Given an index k, return the kth row of the Pascal's triangle.

    For example, given k = 3,
    Return [1,3,3,1].

    Note:
    Could you optimize your algorithm to use only O(k) extra space?
 */

/** solution

 */


/*************************** Submit Part *****************************/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex+1);
        row[0] = 1;
        int i,j;
        for(i=1; i<=rowIndex; ++i){
            for(j=i; j>0; --j){
                row[j] = row[j] + row[j-1];
            }
        }
        return row;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int n;
    while(cin >> n){
        Solution solution;
        vector<int> ans = solution.getRow(n);
        for(int i=0; i<ans.size(); ++i){
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}

