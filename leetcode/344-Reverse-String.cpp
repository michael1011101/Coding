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
 * Title: 344. Reverse String
    Write a function that takes a string as input and returns the string reversed.

    Example:
    Given s = "hello", return "olleh".
 */

/** solution

 */


/*************************** Submit Part *****************************/
class Solution {
public:
    string reverseString(string s) {
        int left, right;
        left = 0, right = s.length()-1;
        while(left<right){
            char c = s[left];
            s[left] = s[right];
            s[right] = c;
            left++, right--;
        }
        return s;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    string str;
    cin >> str;
    Solution solution;
    cout << solution.reverseString(str) << endl;
    return 0;
}
