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
 * Title: 136. Single Number
    Given an array of integers, every element appears twice except for one. Find that single one.

    Note:
    Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */

/** solution
    XOR
    重复的数字异或为0，a^a=0
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        int _size = nums.size();
        for(int i=0; i<_size; ++i){
            ans ^= nums[i];
        }
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
    cout << solution.singleNumber(num) << endl;
    return 0;
}
