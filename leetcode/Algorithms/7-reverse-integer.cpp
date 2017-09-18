#include <iostream>
#include <vector>
using namespace std;

/**
 * Title: 7. Reverse Integer

    Reverse digits of an integer.

    Example1: x = 123, return 321
    Example2: x = -123, return -321

    Have you thought about this?
    Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

    If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

    Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

    For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

    Note:
    The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.
 */

/** solution
    32-bit首先确定上下限，由于会int溢出，所以我们用long long 来存储
    如果不在[Low, High]内的话就return 0
 */


/***************************提交部分*****************************/
class Solution {
private:
    const int Low = -(1<<31);
    const int High = (1<<31) - 1;
public:
    int reverse(int x) {
        int sign = 1;
        if(x < 0){
            sign = -1;
            x = -x;
        }
        long long y = 0;

        while(x){
            y = y*10 + x%10;
            x /= 10;
        }
        y *= sign;
        if(y > High || y < Low) return 0;
        return y;
    }
};
/***************************提交部分*****************************/

int main()
{
    int x;
    while(cin >> x){
        Solution solution;
        cout << solution.reverse(x) << endl;
    }
    return 0;
}
