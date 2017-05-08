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
 * Title: 409. Longest Palindrome
    Given a string which consists of lowercase or uppercase letters,
    find the length of the longest palindromes that can be built with those letters.

    This is case sensitive, for example "Aa" is not considered a palindrome here.

    Note:
    Assume the length of given string will not exceed 1,010.

    Example:

    Input:
    "abccccdd"

    Output:
    7

    Explanation:
    One longest palindrome that can be built is "dccaccd", whose length is 7.
 */

/** solution
    hash一下，偶数个相同的字符一定可以组成回文，所以我们取{max(n)|n<m} m是该字符出现的次数
    可以用位运算 (m>>1)<<1
    最后，如果总字符数sum 大于 ∑(max(n)|n<m[i])，那么可以再最中间放一个字符，形成奇数长度回文
    否则 直接返回∑(max(n)|n<m[i])
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    int longestPalindrome(string s) {
        int visit[255];
        memset(visit, 0, sizeof(visit));
        int len = s.length();
        for(int i=0; i<len; ++i){
            visit[s[i]]++;
        }
        int sum;
        int ans;
        ans = sum = 0;
        for(int i=0; i<255; ++i){
            sum += visit[i];
            ans += (visit[i]>>1)<<1;
        }
        if(ans < sum) ans++;
        return ans;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    string str;
    cin >> str;
    Solution solution;
    cout << solution.longestPalindrome(str) << endl;
    return 0;
}
