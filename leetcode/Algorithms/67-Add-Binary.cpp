#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Title: 67. Add Binary
    Given two binary strings, return their sum (also a binary string).

    For example,
    a = "11"
    b = "1"
    Return "100".
 */

/** solution
    类似大整数相加
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int tmp, carry = 0;
        int asize = a.size();
        int bsize = b.size();
        int _size = min(asize, bsize);
        int i;
        string str = "";

        for(i=0; i<_size; ++i){
            int x = a[i] - '0';
            int y = b[i] - '0';
            tmp = (x+y+carry)%2;
            carry = (x+y+carry)/2;
            str += '0'+tmp;
        }

        for(i=_size; i<asize; ++i){
            int x = a[i] - '0';
            tmp = (x+carry) % 2;
            carry = (x+carry) / 2;
            str += '0'+tmp;
        }

        for(i=_size; i<bsize; ++i){
            int x = b[i] - '0';
            tmp = (x+carry) % 2;
            carry = (x+carry) / 2;
            str += '0'+tmp;
        }

        if(carry) str += '1';
        reverse(str.begin(), str.end());
        return str;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    string a, b;
    while(cin >> a >> b){
        Solution solution;
        cout << solution.addBinary(a,b) << endl;
    }
    return 0;
}
