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
 * Title:55. Jump Game
    Given an array of non-negative integers,
    you are initially positioned at the first index of the array.

    Each element in the array represents your maximum jump length at that position.

    Determine if you are able to reach the last index.

    For example:
    A = [2,3,1,1,4], return true.

    A = [3,2,1,0,4], return false.
 */

/** solution
    贪心
    记录可以访问到的最远的距离
    如果能够到达最后的index那么返回true
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int m = nums.size();
        int i,j;
        int tmp = 0;
        for(i=0; i<m; ++i){
            if(i<=tmp) tmp = max(tmp, i+nums[i]);
        }
        return tmp >= m-1;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    vector<int> nums;
    int x;
    while(cin>> x) nums.push_back(x);

    Solution solution;
    cout << solution.canJump(nums) << endl;
    return 0;
}
