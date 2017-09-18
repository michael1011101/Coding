#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/**
 * Title: 18. 4Sum
    Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
    Find all unique quadruplets in the array which gives the sum of target.

    Note: The solution set must not contain duplicate quadruplets.

    For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

    A solution set is:
    [
      [-1,  0, 0, 1],
      [-2, -1, 1, 2],
      [-2,  0, 0, 2]
    ]

 */

/** solution
    先用first和second固定两个数字，然后类似3Sum求解。
    注意去重问题。
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        int _size = nums.size();
        int first, second, left, right;
        int tmp, sum;
        vector<vector<int> > ans;
        sort(nums.begin(), nums.end());
        bool flag;
        for(first=0; first<_size-3; ++first){
            flag = false;
            for(second=first+1; second<_size-2; ++second){
                left=second+1;
                right=_size-1;
                tmp = nums[first]+nums[second];
                while(left<right){
                    sum = nums[left]+nums[right]+tmp;
                    if(sum == target){
                        vector<int> vec;
                        vec.push_back(nums[first]);
                        vec.push_back(nums[second]);
                        vec.push_back(nums[left]);
                        vec.push_back(nums[right]);
                        ans.push_back(vec);
                        while(nums[left]==nums[left+1]) ++left;
                        while(nums[right]==nums[right-1]) --right;
                        ++left, --right;
                        flag = true;
                    }
                    else if(sum > target){
                        --right;
                    }
                    else{
                        ++left;
                    }
                }
                while(nums[second]==nums[second+1]) ++second;
            }
            if(flag){
                while(nums[first]==nums[first+1]) ++first;
            }
        }
        return ans;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x;
    int target;
    vector<int> nums;
    cin >> target;
    while(cin >> x) nums.push_back(x);

    Solution solution;
    vector<vector<int> > ans = solution.fourSum(nums, target);
    int _size = ans.size();
    for(int i=0; i<_size; ++i){
        cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << ' ' << ans[i][3] << ' ' << endl;
    }
    return 0;
}

