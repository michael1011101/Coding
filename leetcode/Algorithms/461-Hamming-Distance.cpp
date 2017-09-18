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
 * Title: 461. Hamming Distance
    The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

    Given two integers x and y, calculate the Hamming distance.

    Note:
    0 ≤ x, y < 231.

    Example:

    Input: x = 1, y = 4

    Output: 2

    Explanation:
    1   (0 0 0 1)
    4   (0 1 0 0)
           ↑   ↑

    The above arrows point to positions where the corresponding bits are different.
 */

/** solution
    显示x = a^b
    然后数一下x中1的个数
    x&(x-1) 消去最后一个1
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x^y;
        int cnt = 0;
        while(n){
            cnt++;
            n &= (n-1);
        }
        return cnt;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x, y;
    cin >> x >> y;
    Solution solution;
    cout << solution.hammingDistance(x, y) << endl;
    return 0;
}
