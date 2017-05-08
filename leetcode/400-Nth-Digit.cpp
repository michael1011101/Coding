#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Title: 400. Nth Digit
    Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

    Note:
    n is positive and will fit within the range of a 32-bit signed integer (n < 231).

    Example 1:

    Input:
    3

    Output:
    3
    Example 2:

    Input:
    11

    Output:
    0

    Explanation:
    The 11th digit of the sequence
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
 */

/** solution
    一位数有 9 位
    二位数有 90*2 位
    三位数有 900*3 位
    ……
    然后就是计算做减法
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    int findNthDigit(int n) {
        int digit = 1;
        long long num = 9;
        int tmp = 0;
        while(n>num*digit){
            n -= num*digit;
            tmp += num;
            num *= 10;
            digit++;
        }
        tmp += n/digit;
        n = n%digit;
        if(n==0) return tmp%10;
        else{
            vector<int> ans;
            tmp++;
            while(tmp){
                ans.push_back(tmp%10);
                tmp /= 10;
            }
            reverse(ans.begin(), ans.end());
            return ans[n-1];
        }
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x;
    cin >> x;
    Solution solution;
    cout << solution.findNthDigit(x) << endl;
    return 0;
}
