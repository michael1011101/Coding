#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <unordered_set>
#include <algorithm>
using namespace std;

/**
 * Title:415. Add Strings
    Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

    Note:

    The length of both num1 and num2 is < 5100.
    Both num1 and num2 contains only digits 0-9.
    Both num1 and num2 does not contain any leading zero.
    You must not use any built-in BigInteger library or convert the inputs to integer directly.

 */

/** solution
    整数字符相加，模拟整数的加法
 */



/*************************** Submit Part *****************************/
class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        string ans = "";
        int carry = 0;
        int i,j;
        int tmp;
        i = j = 0;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        while(i<len1 && i<len2){
            tmp = num1[i]-'0' + num2[i]-'0' + carry;
            ans += tmp%10 + '0';
            carry = tmp/10;
            i++;
        }
        while(i<len1){
            tmp = num1[i]-'0'  + carry;
            ans += tmp%10 + '0';
            carry = tmp/10;
            i++;
        }
        while(i<len2){
            tmp = num2[i]-'0' + carry;
            ans += tmp%10 + '0';
            carry = tmp/10;
            i++;
        }
        if(carry != 0)
            ans += carry + '0';

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    string num1, num2;
    while(cin >> num1 >> num2){
        Solution solution;
        cout << solution.addStrings(num1, num2) << endl;
    }
    return 0;
}
