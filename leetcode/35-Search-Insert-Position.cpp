#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Title: 35. Search Insert Position
    Given a sorted array and a target value,
    return the index if the target is found.
    If not, return the index where it would be if it were inserted in order.

    You may assume no duplicates in the array.

    Here are few examples.
    [1,3,5,6], 5 → 2
    [1,3,5,6], 2 → 1
    [1,3,5,6], 7 → 4
    [1,3,5,6], 0 → 0
 */

/** solution
    二分查找，如果有相同的数字，找到最左边相同数字的位置
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size()-1, target);
    }
private:
    int binarySearch(vector<int> nums, int left, int right, int target){
        if(left > right) return left;

        int mid = (left+right)/2;

        if(nums[mid] < target){
            return binarySearch(nums, mid+1, right, target);
        }
        else{
            return binarySearch(nums, left, mid-1, target);
        }
    }
};

/* 非递归方法
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left, right, mid;
        left = 0;
        right = nums.size()-1;
        while(left <= right){
            mid = (left+right)/2;
            if(nums[mid] < target){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return left;
    }
};
*/
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
    cout << solution.searchInsert(nums, target) << endl;
    return 0;
}
