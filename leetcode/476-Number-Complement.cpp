#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Title:476. Number Complement
    Given a positive integer, output its complement number.
    The complement strategy is to flip the bits of its binary representation.

    Note:
    The given integer is guaranteed to fit within the range of a 32-bit signed integer.
    You could assume no leading zero bit in the integer¡¯s binary representation.

    Example 1:
    Input: 5
    Output: 2
    Explanation: The binary representation of 5 is 101 (no leading zero bits),
    and its complement is 010. So you need to output 2.

    Example 2:
    Input: 1
    Output: 0
    Explanation: The binary representation of 1 is 1 (no leading zero bits),
    and its complement is 0. So you need to output 0.
 */

/** solution
    better answer
    int findComplement(int num) {
        unsigned mask = ~0;
        while (num & mask) mask <<= 1;
        return ~mask & ~num;
    }
 */



/*************************** Submit Part *****************************/
class Solution {
public:
    int findComplement(int num) {
        if(num == 0)    return 1;
        if(num < 0)     return (-1) ^ num;
        int cnt = 0;
        int n = num;
        while(n!=0){
            cnt++;
            n>>=1;
        }
        return num^((1<<cnt)-1);
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x;
    while(cin >> x){
        Solution solution;
        cout << solution.findComplement(x) << endl;
    }
    return 0;
}
