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
 * Title:58. Length of Last Word
    Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
    return the length of last word in the string.

    If the last word does not exist, return 0.

    Note: A word is defined as a character sequence consists of non-space characters only.

    For example,
    Given s = "Hello World",
    return 5.
 */

/** solution
    反转字符串，求反转后的第一个单词长度，注意空格
 */



/*************************** Submit Part *****************************/
class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(), s.end());
        int i;
        int len = s.length();
        i = 0;
        while(i<len&&s[i]==' ') i++;
        int cnt = 0;
        while(i<len&&s[i]!=' '){
            i++;
            cnt++;
        }
        return cnt;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    string str;
    getline(cin, str);
    Solution solution;
    cout << solution.lengthOfLastWord(str) << endl;
    return 0;
}
