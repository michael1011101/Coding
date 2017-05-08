#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Title: 15. 3Sum
    Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
    Find all unique triplets in the array which gives the sum of zero.

    Note: The solution set must not contain duplicate triplets.

    For example, given array S = [-1, 0, 1, 2, -1, -4],

    A solution set is:
    [
      [-1, 0, 1],
      [-1, -1, 2]
    ]
 */

/** solution
    注意去重
    首先选择一个数字作为目标，然后类似求2Sum的方法来求出解
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        int i,j,k;
        int _size = nums.size();
        int target, sum;
        for(i=0; i<_size-2; ++i){
            j = i+1;
            k = _size-1;
            target = -nums[i];
            while(j<k){
                sum = nums[j]+nums[k];
                if(sum == target){
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[k]);
                    ans.push_back(tmp);
                    while(nums[j] == nums[j+1]) ++j;
                    while(nums[k] == nums[k-1]) --k;
                    ++j, --k;
                }
                else if(sum < target) ++j;
                else if(sum > target) --k;
           }
           while(nums[i] == nums[i+1]) ++i;
        }
        return ans;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x;
    vector<int> nums;
    while(cin >> x) nums.push_back(x);
    Solution solution;
    vector<vector<int> > ans = solution.threeSum(nums);
    int _size = ans.size();
    for(int i=0; i<_size; ++i){
        cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << ' ' << endl;
    }
    return 0;
}

