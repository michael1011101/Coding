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
 * Title:371. Sum of Two Integers
    Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

    Example:
    Given a = 1 and b = 2, return 3.
 */

/** solution
    位运算
 */



/*************************** Submit Part *****************************/
/* 递归版本
class Solution {
public:
    int getSum(int a, int b) {
        return b?getSum(a^b, (a&b)<<1):a;
    }
};
*/
// 迭代版本
class Solution {
public:
    int getSum(int a, int b) {
        int carry;
        while(b){
            carry = a&b;
            a ^= b;
            b = carry<<1;
        }
        return a;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int a, b;
    while(cin >> a >> b){
        Solution solution;
        cout << solution.getSum(a,b) << endl;
    }
    return 0;
}
