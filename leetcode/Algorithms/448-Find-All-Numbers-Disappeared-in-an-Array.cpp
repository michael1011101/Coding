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
 * Title: 448. Find All Numbers Disappeared in an Array
    Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

    Find all the elements of [1, n] inclusive that do not appear in this array.

    Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

    Example:

    Input:
    [4,3,2,7,8,2,3,1]

    Output:
    [5,6]
 */

/** solution
    由于数组中最大值<=数组长度
    由于都是正数，所以我们用正负号来表示是否访问
    访问为负数
    然后遍历一遍，将所有的正数的index+1存起来，就是没有出现的数字
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int _size = nums.size();
        for(int i=0; i<_size; ++i){
            int tmp = abs(nums[i]);
            nums[tmp-1] = nums[tmp-1]<0? nums[tmp-1]: -nums[tmp-1];
        }
        vector<int> ans;
        for(int i=0; i<_size; ++i){
            if(nums[i] > 0){
                ans.push_back(i+1);
            }
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
    vector<int> ans;
    ans = solution.findDisappearedNumbers(num);
    for(vector<int>::iterator it=ans.begin(); it!=ans.end(); ++it){
        cout << *it << ' ';
    }
    return 0;
}
