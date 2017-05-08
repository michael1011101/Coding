#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <unordered_set>
#include <algorithm>
using namespace std;

/**
 * Title:198. House Robber
    You are a professional robber planning to rob houses along a street.
    Each house has a certain amount of money stashed,
    the only constraint stopping you from robbing each of them is
    that adjacent houses have security system connected and it will automatically
    contact the police if two adjacent houses were broken into on the same night.

    Given a list of non-negative integers representing the amount of money
    of each house, determine the maximum amount of money you can rob tonight without alerting the police.
 */

/** solution
    simple dp
 */



/*************************** Submit Part *****************************/
class Solution {
public:
    int rob(vector<int>& nums) {
        int _size = nums.size();
        if(_size == 0) return 0;
        vector<vector<int> > dp(_size, vector<int>(2));
        int i,j;

        dp[0][0] = 0;
        dp[0][1] = nums[0];
        for(i = 1; i<_size; ++i){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = max(dp[i-1][0]+nums[i], dp[i-1][1]);
        }
        return max(dp[_size-1][0], dp[_size-1][1]);
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x;
    vector<int> nums;
    while(cin >> x){
        nums.push_back(x);
    }

    Solution solution;
    cout << solution.rob(nums) << endl;
    return 0;
}
