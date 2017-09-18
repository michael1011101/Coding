#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Title: 34. Search for a Range
    Given an array of integers sorted in ascending order,
    find the starting and ending position of a given target value.

    Your algorithm's runtime complexity must be in the order of O(log n).

    If the target is not found in the array, return [-1, -1].

    For example,
    Given [5, 7, 7, 8, 8, 10] and target value 8,
    return [3, 4].
 */

/** solution
    二分法找最左端，然后找最右端
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = binarySearchLeft(nums, 0, nums.size()-1, target, true);
        int right = binarySearchLeft(nums, 0, nums.size()-1, target, false);
        vector<int> ans;
        ans.push_back(left);
        ans.push_back(right);
        return ans;
    }
private:
    int binarySearchLeft(vector<int> nums, int st, int ed, int target, bool left){
        if(st > ed) return -1;

        int mid = (st + ed)/2;
        if(nums[mid] == target){
            //递归方法
            int pos = left ? binarySearchLeft(nums, st, mid-1, target, left)
            : binarySearchLeft(nums, mid+1, ed, target, left);
            return pos==-1? mid: pos;

            /* 循环方法
            int i;
            if(left)
                for(i=mid; i>st; --i){
                    if(nums[i-1] < target) break;
                }
            else
                for(i=mid; i<ed; ++i){
                    if(nums[i+1] > target) break;
                }
            return i;
            */
        }
        else if(nums[mid] < target){
            return binarySearchLeft(nums, mid+1, ed, target, left);
        }
        else{
            return binarySearchLeft(nums, st, mid-1, target, left);
        }
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x;
    vector<int> nums;
    int target;
    cin >> target;
    while(cin >> x){
        nums.push_back(x);
    }
    Solution solution;
    vector<int> ans = solution.searchRange(nums, target);
    cout << ans[0] << ' ' << ans[1] << endl;
    return 0;
}
