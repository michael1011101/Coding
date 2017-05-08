#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Title:283. Move Zeroes
    Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

    For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

    Note:
    You must do this in-place without making a copy of the array.
    Minimize the total number of operations.
 */

/** solution
    some cases:
    1 0
    1 0 0
    1 0 1
 */



/*************************** Submit Part *****************************/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int fast, slow;
        int _size = nums.size();
        fast = slow = 0;
        while(fast<_size){
            while(slow<_size&&nums[slow]!=0) slow++;
            if(slow>=_size) break;
            fast = slow;
            while(fast<_size&&nums[fast]==0) fast++;
            if(fast>=_size) break;
            swap(nums[slow], nums[fast]);
        }
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
    solution.moveZeroes(nums);
    for(int i=0; i<nums.size(); ++i){
        cout << nums[i] << ' ';
    }
    return 0;
}
