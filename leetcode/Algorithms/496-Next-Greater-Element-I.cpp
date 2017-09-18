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
 * Title:496. Next Greater Element I
    You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2.
    Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

    The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2.
    If it does not exist, output -1 for this number.

    Example 1:
    Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
    Output: [-1,3,-1]
    Explanation:
        For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
        For number 1 in the first array, the next greater number for it in the second array is 3.
        For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
    Example 2:
    Input: nums1 = [2,4], nums2 = [1,2,3,4].
    Output: [3,-1]
    Explanation:
        For number 2 in the first array, the next greater number for it in the second array is 3.
        For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
    Note:
    All elements in nums1 and nums2 are unique.
    The length of both nums1 and nums2 would not exceed 1000.
 */

/** solution
    对于findNums中的每个数字，从nums中找到该数字右边第一个大的数，如果没有返回-1
    首先先找到findNums[i]在nums中的下标index，
    然后在(index+1, nums.size())间找到第一个大于findNums[i]的数字
 */



/*************************** Submit Part *****************************/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> ans;
        int i, j;
        int size1, size2;
        int tmp, index, number;
        size1 = findNums.size();
        size2 = nums.size();

        for(i=0; i<size1; ++i){
            tmp = findNums[i];
            index = size2;
            for(j=0; j<size2; ++j){
                if(nums[j] == tmp){
                    index = j;
                    break;
                }
            }

            number = -1;
            for(j=index+1; j<size2; ++j){
                if(nums[j] > tmp){
                    number = nums[j];
                    break;
                }
            }
            ans.push_back(number);
        }

        return ans;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x, m, n;
    vector<int> num1, num2;
    cin >> m;
    for(int i=0; i<m; ++i){
        cin >> x;
        num1.push_back(x);
    }

    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> x;
        num2.push_back(x);
    }

    Solution solution;
    vector<int> ans = solution.nextGreaterElement(num1, num2);
    for(int i=0; i<m; ++i){
        cout << ans[i] << ' ';
    }
    return 0;
}
