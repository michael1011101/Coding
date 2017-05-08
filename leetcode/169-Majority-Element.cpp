#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

/**
 * Title:169. Majority Element
    Given an array of size n, find the majority element.
    The majority element is the element that appears more than n/2 times.

    You may assume that the array is non-empty and the majority element always exist in the array.
 */

/** solution

 */



/*************************** Submit Part *****************************/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int i, j, tmp;
        int _size = nums.size();
        i = j = 0;
        while(i<_size){
            if(j == 0)    tmp = nums[i], j++;
            else if(nums[i] == tmp) j++;
            else if(nums[i] != tmp) j--;
            i++;
        }
        return tmp;
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
    cout << solution.majorityElement(nums) << endl;
    return 0;
}
