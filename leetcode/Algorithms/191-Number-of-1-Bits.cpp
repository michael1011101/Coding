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
 * Title: 191. Number of 1 Bits
    Write a function that takes an unsigned integer
    and returns the number of ’1' bits it has (also known as the Hamming weight).

    For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011,
    so the function should return 3.
 */

/** solution
    x&(x-1) 消去最后一个1
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n){
            cnt++;
            n &= (n-1);
        }
        return cnt;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    uint32_t x;
    cin >> x;
    Solution solution;
    cout << solution.hammingWeight(x) << endl;
    return 0;
}
