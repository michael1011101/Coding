#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Title: 167. Two Sum II - Input array is sorted
    Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

    The function twoSum should return indices of the two numbers such that they add up to the target,
    where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

    You may assume that each input would have exactly one solution and you may not use the same element twice.

    Input: numbers={2, 7, 11, 15}, target=9
    Output: index1=1, index2=2
 */

/** solution
    二分法 时间复杂度O(nlogn) 空间复杂度O(1)
    线性法 时间复杂度O(n)
 */


/*************************** Submit Part *****************************/
/* time : O(nlogn)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int _size = numbers.size();
        vector<int> ans;
        for(int i=0; ans.empty()&&i<_size; ++i){
            int tmp = target-numbers[i];
            int left = i+1, right = _size-1;
            while(left <= right){
                int mid = (left+right)/2;
                if(numbers[mid] == tmp){
                    ans.push_back(i+1);
                    ans.push_back(mid+1);
                    break;
                }
                else if(numbers[mid] < tmp){
                    left = mid+1;
                }
                else{
                    right = mid-1;
                }
            }
        }
        return ans;
    }
};
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int left = 0, right = numbers.size()-1;
        while(left < right){
            int tmp = numbers[left] + numbers[right];
            if(tmp == target) {
                ans.push_back(left+1);
                ans.push_back(right+1);
                break;
            }
            else if(tmp < target){
                left++;
            }
            else{
                right--;
            }
        }
        return ans;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int target;
    int x;
    vector<int> nums;
    cin >> target;
    while(cin >> x) nums.push_back(x);

    Solution solution;
    vector<int> ans = solution.twoSum(nums, target);
    cout << ans[0] << ' ' << ans[1] << endl;
    return 0;
}
