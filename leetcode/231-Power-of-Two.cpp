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
 * Title: 231. Power of Two
    Given an integer, write a function to determine if it is a power of two.
 */

/** solution
    位运算 2的倍数 说明只有一位是1
    注意：小于等于0的都返回false
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int cnt = 0;
        if(n<=0) return false;
        while(n){
            cnt++;
            if(cnt > 1) return false;
            n &= (n-1);
        }
        return true;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x;
    cin >> x;
    Solution solution;
    cout << solution.isPowerOfTwo(x) << endl;
    return 0;
}
