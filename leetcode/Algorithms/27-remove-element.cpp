#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

/**
 * Title: 27. Remove Element
    Given an array and a value, remove all instances of that value in place and return the new length.

    Do not allocate extra space for another array, you must do this in place with constant memory.

    The order of elements can be changed. It doesn't matter what you leave beyond the new length.

    Example:
    Given input array nums = [3,2,2,3], val = 3

    Your function should return length = 2, with the first two elements of nums being 2.
 */

/** solution
    将与val值相同的数字去除，
    i从0开始向后面扫描，如果nums[i]!=val 将其放在j处，j++(j从0开始)
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int _size = nums.size();
        int i,j;
        for(i=j=0; i<_size; ++i){
            if(nums[i] != val){
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x;
    int val;
    vector<int> nums;
    cin >> val;
    while(cin>>x) nums.push_back(x);

    Solution solution;
    cout << solution.removeElement(nums,x) << endl;
    return 0;
}
