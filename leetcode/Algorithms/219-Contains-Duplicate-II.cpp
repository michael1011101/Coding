#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

/**
 * Title:  219. Contains Duplicate II
    Given an array of integers and an integer k,
    find out whether there are two distinct indices i and j in the array
    such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
 */

/** solution
    用set来维护连续k+1个数，如果新的数字进来，先将与新数字距离为k+1位的数去除
    在判断新数字是否在集合中，如果在，返回true。
    否则，将新数字放入到set中。
    判断完所有的数字，最后返回false。
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k<=0) return false;
        unordered_set<int> uset;
        int numsSize = nums.size();
        for(int i=0; i<numsSize; ++i){
            if(i>k) uset.erase(nums[i-k-1]);
            if(uset.find(nums[i])!=uset.end()) return true;
            uset.insert(nums[i]);
        }
        return false;
    }
};
/*************************** Submit Part *****************************/

int main()
{

    return 0;
}

