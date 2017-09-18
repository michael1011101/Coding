#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Title: 33. Search in Rotated Sorted Array
    Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

    (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

    You are given a target value to search. If found in the array return its index, otherwise return -1.

    You may assume no duplicate exists in the array.
 */

/** solution
    由于被搜索的数组，是由有序数组循环形成的，所以有三种搜索情况
    对三种搜索情况进行分析，就可以知道答案
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size()-1, target);
    }
private:
    int binarySearch(vector<int> nums, int left, int right, int target){
        if(left > right) return -1;

        int mid = (left+right)/2;
        if(nums[left] == target)    return left;
        if(nums[mid] == target)     return mid;
        if(nums[right] == target)   return right;

        if(nums[left] < nums[right]){
            if(target < nums[left] || target > nums[right])
                return -1;
            else if(target < nums[mid])
                return binarySearch(nums, left, mid-1, target);
            else
                return binarySearch(nums, mid+1, right, target);
        }
        else if(nums[left] < nums[mid]){
            if(target > nums[left] && target < nums[mid])
                return binarySearch(nums, left, mid-1, target);
            else
                return binarySearch(nums, mid+1, right, target);
        }
        else{
            if(target > nums[mid] && target < nums[right])
                return binarySearch(nums, mid+1, right, target);
            else
                return binarySearch(nums, left, mid-1, target);
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
    cout << solution.search(nums, target) << endl;
    return 0;
}
