#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

/**
 * Title:504. Base 7
    Given an integer, return its base 7 string representation.

    Example 1:
    Input: 100
    Output: "202"

    Example 2:
    Input: -7
    Output: "-10"
 */

/** solution
    将10进制改为7进制， 取余法
 */



/*************************** Submit Part *****************************/
class Solution {
public:
    string convertToBase7(int num) {
        string ans = "";
        if(num == 0) ans = "0";
        else{
            bool flag = true;
            if(num < 0){
                flag = false;
                num = -num;
            }
            while(num){
                ans += num%7 + '0';
                num /= 7;
            }
            if(!flag) ans += '-';
            reverse(ans.begin(), ans.end());
        }
        return ans;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x;
    while(cin >> x){
        Solution solution;
        cout << solution.convertToBase7(x) << endl;
    }
    return 0;
}
