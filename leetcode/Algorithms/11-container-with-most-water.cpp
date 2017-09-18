#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

/**
 * Title: 11. Container With Most Water
    Given n non-negative integers a1, a2, ..., an,
    where each represents a point at coordinate (i, ai).
    n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
    Find two lines, which together with x-axis forms a container,
    such that the container contains the most water.

    Note: You may not slant the container and n is at least 2.
 */

/** solution
    贪心
    先对数组排序，然后从两边向里进行判断，由于宽度减少，
    所以之后当height比之前的h大的时候才进行判断。
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int _size = height.size();
        int left=0, right=_size-1;
        int area, h;
        area = 0;
        while(left < right){
            h = min(height[left], height[right]);
            area = max(area, (right-left)*h);
            while(left<right && height[left]<=h) left++;
            while(left<right && height[right]<=h) right--;
        }
        return area;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x;
    vector<int> height;
    while(cin >> x) height.push_back(x);
    Solution solution;
    cout << solution.maxArea(height) << endl;
    return 0;
}

