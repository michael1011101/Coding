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
 * Title:53. Maximum Subarray
    Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

    For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
    the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 */

/** solution
    st是开始， ed是结束， cnt是现在暂存的和

    因为连续的正数相加，或者说一直相加的时候不小于0就有可能加上后面的值超过最大值

    如果cnt+nums[i]<0 那么将cnt设置为nums[i], st,ed为i
    如果cnt+nums[i}>=0 那么cnt=cnt+nums[i], ed=i

    然后判断如果cnt>ans，那么更新ans,left,right的值

    最后如果cnt<0,那么初始化cnt=0

    因为防止数组都是负数，所以不能在一开始将ans设置为0，
    所以在初始化的时候，用数组的第一位的来初始化：
    left = right = 0, ans = nums[0]
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int left, right, ans;
        int st, ed, cnt;
        int _size = nums.size();
        left = right = 0, ans = nums[0];
        cnt = 0;
        for(int i=0; i<_size; ++i){
            if(cnt+nums[i] < 0){
                cnt = nums[i];
                st = ed = i;
            }
            else{
                cnt += nums[i];
                ed = i;
            }

            if(cnt > ans){
                ans = cnt;
                left = st;
                right = ed;
            }

            if(cnt < 0){
                cnt = 0;
                st = ed = i+1;
            }
        }
        return ans;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    vector<int> nums;
    int x;
    while(cin >> x){
        nums.push_back(x);
    }

    Solution solution;
    cout << solution.maxSubArray(nums) << endl;
    return 0;
}
