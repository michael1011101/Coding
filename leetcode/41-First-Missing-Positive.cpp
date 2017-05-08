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
 * Title: 41. First Missing Positive
    Given an unsorted integer array, find the first missing positive integer.

    For example,
    Given [1,2,0] return 3,
    and [3,4,-1,1] return 2.

    Your algorithm should run in O(n) time and uses constant space.
 */

/** solution
    首先找到最大的正数max，至少1
    然后开一个max数组
    通过hash找到第一个不存在的正数
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int _size = nums.size();
        int i, _max = 1;
        for(i=0; i<_size; ++i){
            _max = max(_max, nums[i]);
        }

        vector<bool> visit(_max+1, false);
        for(i=0; i<_size; ++i){
            if(nums[i] > 0){
                visit[nums[i]] = true;
            }
        }
        for(i=1; i<=_max; ++i){
            if(!visit[i]){
                break;
            }
        }
        return i;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x;
    vector<int> num;
    while(cin >> x) num.push_back(x);

    Solution solution;
    cout << solution.firstMissingPositive(num) << endl;
    return 0;
}
