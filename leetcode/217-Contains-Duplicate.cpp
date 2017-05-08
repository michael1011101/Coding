#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

/**
 * Title:217. Contains Duplicate
    Given an array of integers, find if the array contains any duplicates.
    Your function should return true if any value appears at least twice in the array,
    and it should return false if every element is distinct.
 */

/** solution
    判断数组中是否存在重复的数字，用set来收集判断
 */



/*************************** Submit Part *****************************/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> nums_set;
        int _size = nums.size();
        bool flag = false;
        for(int i=0; i<_size; ++i){
            if(nums_set.count(nums[i])>0){
                flag = true;
                break;
            }
            nums_set.insert(nums[i]);
        }
        return flag;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x;
    vector<int> nums;
    while(cin >> x) nums.push_back(x);
    Solution solution;
    cout << solution.containsDuplicate(nums) << endl;
    return 0;
}
