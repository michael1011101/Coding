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
 * Title:485. Max Consecutive Ones
    Given a binary array, find the maximum number of consecutive 1s in this array.

    Example 1:
    Input: [1,1,0,1,1,1]
    Output: 3
    Explanation: The first two digits or the last three digits are consecutive 1s.
        The maximum number of consecutive 1s is 3.
    Note:

    The input array will only contain 0 and 1.
    The length of input array is a positive integer and will not exceed 10,000
 */

/** solution
    设置首尾两个哨兵，一个标记位flag
    在标记位为true的时候，如果头哨兵是1，继续向后，否则将标记位置为false
    如果标记位为false，头哨兵是1的时候，说明遇到可能的连续1，将flag置为true,头尾哨兵同步；
    否则，继续向后找
    在每一次头哨兵向后找之后，如果标记位仍为true，ans赋值为 max(ans, 当前连续1的长度)
 */



/*************************** Submit Part *****************************/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int st, ed;
        int _size = nums.size();
        int ans = 0;

        bool flag = false;
        st = ed = 0;
        while(st < _size){

            if(flag){
                if(nums[st]==0){
                    flag = false;
                }
            }
            else{
                if(nums[st]==1){
                    flag = true;
                    ed = st;
                }
            }
            st++;
            if(flag)    ans = max(ans, st-ed);
        }
        return ans;
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
    cout << solution.findMaxConsecutiveOnes(nums) << endl;
    return 0;
}
