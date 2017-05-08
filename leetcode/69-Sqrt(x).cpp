#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Title: 69. Sqrt(x)
    Implement int sqrt(int x).

    Compute and return the square root of x.
 */

/** solution
    二分法查找的时候，注意边界条件，使用long long
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        return binarySearch(0,x,x);
    }
private:
    int binarySearch(int left, int right, int target){
        if(left>right) return right;
        long long mid = (left+right)/2;

        if(mid*mid == target) return mid;
        else if(mid*mid < target){
            return binarySearch(mid+1, right, target);
        }
        else{
            return binarySearch(left, mid-1, target);
        }
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x;
    cin >> x;
    Solution solution;
    cout << solution.mySqrt(x) << endl;
    return 0;
}
