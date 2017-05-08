#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

/**
 * Title:405. Convert a Number to Hexadecimal
    Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.

    Note:

    All letters in hexadecimal (a-f) must be in lowercase.
    The hexadecimal string must not contain extra leading 0s. If the number is zero,
    it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
    The given number is guaranteed to fit within the range of a 32-bit signed integer.
    You must not use any method provided by the library which converts/formats the number to hex directly.
    Example 1:

    Input:
    26

    Output:
    "1a"
    Example 2:

    Input:
    -1

    Output:
    "ffffffff"
 */

/** solution
    整数每次取4位2进制，将其转为16进制
    由于是32位，所以最多转换8次
 */



/*************************** Submit Part *****************************/
class Solution {
private:
    string str_to_hex="0123456789abcdef";
public:
    string toHex(int num) {
        if(0 == num) return "0";
        string ans = "";
        int cnt = 0;
        while(num&&cnt<8){
            ans = str_to_hex[num&0xf] + ans;
            num >>= 4;
            cnt ++;
        }
        return ans;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int n;
    while(cin >> n){
        Solution solution;
        cout << solution.toHex(n) << endl;
    }
    return 0;
}
