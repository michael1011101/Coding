#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Title: 268. Missing Number
    Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

    For example,
    Given nums = [0, 1, 3] return 2.
 */

/** solution
    方法1：
    ans = sum(0,n) - sum(nums)
    防止溢出的话 可以使用循环的方法 ans = ans+i-nums[i] [0,_size) ans初始化为_size
    方法2：XOR
    i^i = 0
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int _size = nums.size();
        int ans = 0;
        for(int i=0; i<_size; ++i){
            ans ^= i;
            ans ^= nums[i];
        }
        ans ^= _size;
        return ans;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x;
    vector<int> num;
    while(cin >> x) num.push_back(x);

    Solution solution;
    cout << solution.missingNumber(num) << endl;
    return 0;
}
