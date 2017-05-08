#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Title: 441. Arranging Coins
    You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.

    Given n, find the total number of full staircase rows that can be formed.

    n is a non-negative integer and fits within the range of a 32-bit signed integer.

    Example 1:

    n = 5

    The coins can form the following rows:
    ¤
    ¤ ¤
    ¤ ¤

    Because the 3rd row is incomplete, we return 2.
    Example 2:

    n = 8

    The coins can form the following rows:
    ¤
    ¤ ¤
    ¤ ¤ ¤
    ¤ ¤

    Because the 4th row is incomplete, we return 3.
 */

/** solution
    方法1、解方程 max(x| x*(x+1)/2 < n} 由于求整，即求x*(x+1)/2 = n的整数解，时间复杂度O(1)
    方法2、O(logn) 二分法
    方法3、O(n) 线性法
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    int arrangeCoins(int n) {
        long long left = 0;
        long long right = n;
        long long target = n;
        while(left <= right){
            long long mid = (left+right)/2;
            long long tmp = mid*(mid+1)/2;
            if(tmp == n){
                return mid;
            }
            else if(tmp < n){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return right;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x;
    while(cin >> x){
        Solution solution;
        cout << solution.arrangeCoins(x) << endl;
    }
    return 0;
}
