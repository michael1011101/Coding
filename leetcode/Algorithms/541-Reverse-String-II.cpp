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
 * Title: 541. Reverse String II
    Given a string and an integer k,
    you need to reverse the first k characters for every 2k characters counting
    from the start of the string.
    If there are less than k characters left,
    reverse all of them.
    If there are less than 2k but greater than or equal to k characters,
    then reverse the first k characters and left the other as original.

    Example:
    Input: s = "abcdefg", k = 2
    Output: "bacdfeg"
 */

/** solution
    每2k个字符，反转前k个字符
    如果[k,2k),反转前k个
    如果不满k个，直接反转

    写一个循环就好了，标记头和尾
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    string reverseStr(string s, int k) {
        int st, ed;
        int len = s.length();
        for(st=0, ed=k; ed<=len; st+=2*k, ed+=2*k){
            reverse(s.begin()+st, s.begin()+ed);
        }
        if(st<len) reverse(s.begin()+st, s.end());
        return s;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    string str;
    int x;
    cin >> str >> x;
    Solution solution;
    cout << solution.reverseStr(str, x) << endl;
    return 0;
}
