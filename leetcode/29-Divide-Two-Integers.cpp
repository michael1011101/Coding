#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

/**
 * Title: 29. Divide Two Integers
    Divide two integers without using multiplication, division and mod operator.

    If it is overflow, return MAX_INT.
 */

/** solution
    首先几个边界条件
    1. divisor=0 返回INT_MAX
    2. dividend=INT_MIN, divisor=1; return INT_MIN
    3. dividend=INT_MIN, divisor=-1; answer is overflow, return INT_MAX
    方法：首先判断正负号
    取正数之后，采用正数的二进制除法
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(!divisor || (dividend==INT_MIN && divisor==-1)) return INT_MAX;

        int sign = isNegative(dividend)^isNegative(divisor) ? -1 : 1;
        long long divd = getPositive(dividend);
        long long divs = getPositive(divisor);
        int ans = 0;
        while(divd >= divs){
            long long tmp = divs;
            long long cnt = 1;
            while(divd >= (tmp<<1)){
                tmp <<= 1;
                cnt <<= 1;
            }
            divd -= tmp;
            ans += cnt;
        }
        return isNegative(sign) ? ~ans+1 : ans;
    }
private:
    bool isNegative(int num){
        return num < 0;
    }

    long long getPositive(int num){
        long long ans = num;
        if(isNegative(ans)) return ~ans + 1;
        else return ans;
    }

    long long getNegative(int num){
        long long ans = num;
        if(isNegative(ans)) return ans;
        else return ~ans+1;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int dividend, divisor;
    while(cin >> dividend >> divisor){
        Solution solution;
        cout << solution.divide(dividend, divisor) << endl;
    }
    return 0;
}
