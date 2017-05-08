#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Title: 16. 3Sum Closest
    Given an array S of n integers,
    find three integers in S such that the sum is closest to a given number, target.
    Return the sum of the three integers.
    You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

/** solution
    类似3Sum问题，依然是固定左边，然后两个哨兵从两端向中间扫描。
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest;
        int tmp, sum;
        int _size = nums.size();
        sort(nums.begin(), nums.end());
        int i,j,k;
        closest = nums[0]+nums[1]+nums[2];
        for(i=0; i<_size-2; ++i){
            j = i+1;
            k = _size-1;
            while(j<k){
                tmp = target - nums[i];
                if(abs(tmp - nums[j] - nums[k]) < abs(target-closest)){
                    closest = nums[i]+nums[j]+nums[k];
                }

                if(nums[j] + nums[k] == tmp) return closest;
                else if(nums[j] + nums[k] < tmp) j++;
                else --k;
            }
        }
        return closest;
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
    cout << solution.threeSumClosest(nums, target) << endl;
    return 0;
}

