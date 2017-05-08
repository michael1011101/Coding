#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Title:172. Factorial Trailing Zeroes
    Given an integer n, return the number of trailing zeroes in n!.

    Note: Your solution should be in logarithmic time complexity.
 */

/** solution
    后置0一定是由于2*5=10形成的
    由于2的个数比5多，所以我们计算因子5的个数
 */



/*************************** Submit Part *****************************/
class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0;
        while(n){
            n /= 5;
            cnt += n;
        }
        return cnt;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x;
    while(cin >> x){
        Solution solution;
        cout << solution.trailingZeroes(x) << endl;
    }
    return 0;
}
