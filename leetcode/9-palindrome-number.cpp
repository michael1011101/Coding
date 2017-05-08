#include <iostream>

using namespace std;

/**
 * Title: 9. Palindrome Number
    Determine whether an integer is a palindrome. Do this without extra space.
 */

/** solution
    负数不是回文
    那么倒序排列下x 然后与x比较下
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int tmp = x;
        int y = 0;
        while(tmp!=0){
            y = y*10 + tmp%10;
            tmp /= 10;
        }
        if(x == y) return true;
        return false;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x;
    while(cin >> x){
        Solution solution;
        cout << solution.isPalindrome(x) << endl;
    }
    return 0;
}
