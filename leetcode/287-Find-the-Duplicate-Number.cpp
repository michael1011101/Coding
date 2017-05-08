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
 * Title: 287. Find the Duplicate Number
    Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive),
    prove that at least one duplicate number must exist.
    Assume that there is only one duplicate number, find the duplicate one.
 */

/** solution
    抽屉原理(又叫鸽巢原理), 即如果有十个苹果放到九个抽屉里，
    如果苹果全在抽屉里，则至少有一个抽屉里有两个苹果

    二分搜索法
    在区间[1, n]中搜索，
    首先求出中点mid，然后遍历整个数组，
    统计所有小于等于mid的数的个数，
    如果个数大于mid，则说明重复值在[mid+1, n]之间，
    反之，重复值应在[1, mid-1]之间，
    然后依次类推，直到搜索完成，
    此时的low就是我们要求的重复值
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left, right, mid;
        int cnt;
        int _size = nums.size();
        left = 1, right = _size-1;
        while(left<=right){
            mid = (left+right)/2;
            cnt = 0;
            for(int i=0; i<_size; ++i){
                if(nums[i] <= mid)
                    cnt++;
            }
            if(cnt <= mid) left = mid+1;
            else right = mid-1;
        }
        return left;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x;
    vector<int> num;
    while(cin >> x) num.push_back(x);

    Solution solution;
    cout << solution.findDuplicate(num) << endl;
    return 0;
}
