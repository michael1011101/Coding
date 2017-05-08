#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <unordered_set>
#include <algorithm>
using namespace std;

/**
 * Title:326. Power of Three
    Given an integer, write a function to determine if it is a power of three.

    Follow up:
    Could you do it without using any loop / recursion?
 */

/** solution
    log(3,n)是否是整数
    换底公式
    log(3,n) = log(10,n) / log(10,3)
    不能用e或者2为底数，因为会出现精度问题
    C++判断整数: res-int(res) == 0  （建议还是使用精度，判断是否相等）
 */



/*************************** Submit Part *****************************/
class Solution {
public:
    bool isPowerOfThree(int n) {
        double res = log10(n) / log10(3);
        return (res - int(res)) == 0;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x;
    while(cin >> x){
        Solution solution;
        cout << solution.isPowerOfThree(x) << endl;
    }
    return 0;
}
