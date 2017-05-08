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
    ά��һ��ջ��ջ��ֵΪ�ϴ�ƥ��ʧ�ܵ�λ��

    ���ȳ�ʼ��һ��-1��ջ�����ϴ�ƥ��ʧ�ܵĵط�Ϊ-1

    ����ɨ���ַ�

    ��Ϊ'('����λ�÷���ջ��

    ��Ϊ')',��ջ��Ԫ�ش���1�����������'('��ƥ�䣬��������ֵ���������ջ��

    ��Ȼ����������һ��������Ӵ��������һ���ַ�����ʱȡ������һ��ƥ��ʧ�ܵ�λ�ã������в�����Ӵ�ȡ�����Ž��
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
