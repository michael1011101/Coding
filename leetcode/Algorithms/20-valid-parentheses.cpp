#include <iostream>
#include <stack>
using namespace std;

/**
 * Title: 20. Valid Parentheses
    Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
    determine if the input string is valid.

    The brackets must close in the correct order,
    "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */

/** solution
    ����ƥ����ջ
    ����Ǻ����ţ�ע���ж���ջ�Ƿ�Ϊ�ա�
    �����ջ����Ҫ�ǿյ�
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    bool isValid(string s) {
        int length = s.length();
        int i;
        stack<char> stringStack;
        if(length%2) return false;
        for(i=0; i<length; ++i){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                stringStack.push(s[i]);
            }
            else{
                if(stringStack.empty()) return false;
                switch(s[i]){
                    case ')':
                        if(stringStack.top()=='(')
                            stringStack.pop();
                        else
                            return false;
                        break;
                    case ']':
                        if(stringStack.top()=='[')
                            stringStack.pop();
                        else
                            return false;
                        break;
                    case '}':
                        if(stringStack.top()=='{')
                            stringStack.pop();
                        else
                            return false;
                        break;
                }
            }
        }
        return stringStack.empty();
    }
};
/*************************** Submit Part *****************************/

int main()
{
    string s;
    while(cin >> s){
        Solution solution;
        cout << solution.isValid(s) << endl;
    }
    return 0;
}

