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
    hashһ�£�ż������ͬ���ַ�һ��������ɻ��ģ���������ȡ{max(n)|n<m} m�Ǹ��ַ����ֵĴ���
    ������λ���� (m>>1)<<1
    ���������ַ���sum ���� ��(max(n)|n<m[i])����ô���������м��һ���ַ����γ��������Ȼ���
    ���� ֱ�ӷ��ء�(max(n)|n<m[i])
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
