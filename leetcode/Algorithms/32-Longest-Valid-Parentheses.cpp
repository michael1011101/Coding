#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Title: 32. Longest Valid Parentheses
    Given a string containing just the characters '(' and ')',
    find the length of the longest valid (well-formed) parentheses substring.

    For "(()", the longest valid parentheses substring is "()", which has length = 2.

    Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 */

/** solution
    维护一个栈，栈底值为上次匹配失败的位置

    首先初始放一个-1入栈代表上次匹配失败的地方为-1

    依次扫描字符

    若为'('，将位置放入栈中

    若为')',若栈中元素大于1个，则代表有'('可匹配，更新最优值，否则更新栈底

    显然，对于任意一个部分最长子串，其最后一个字符更新时取的是上一次匹配失败的位置，故所有部分最长子串取得最优结果
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        stack<int> stck;
        int i, ans = 0;
        stck.push(-1);
        for(i=0; i<len; ++i){
            if(s[i] == '('){
                stck.push(i);
            }
            else{
                if(stck.size()>1){
                    stck.pop();
                    int tmp = stck.top();
                    ans = max(ans, i-tmp);
                }
                else{
                    stck.pop();
                    stck.push(i);
                }
            }
        }
        return ans;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    string str;
    cin >> str;
    Solution solution;
    cout << solution.longestValidParentheses(str) << endl;
    return 0;
}
