#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

/**
 * Title:342. Power of Four
    Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

    Example:
    Given num = 16, return true. Given num = 5, return false.
 */

/** solution

 */



/*************************** Submit Part *****************************/
class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && int(log10(num)/log10(4)) - log10(num)/log10(4) == 0;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int n;
    while(cin >> n){
        Solution solution;
        cout << solution.isPowerOfFour(n) << endl;
    }
    return 0;
}
