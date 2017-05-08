#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

/**
 * Title: 10. Regular Expression Matching
    Implement regular expression matching with support for '.' and '*'.

    '.' Matches any single character.
    '*' Matches zero or more of the preceding element.

    The matching should cover the entire input string (not partial).

    The function prototype should be:
    bool isMatch(const char *s, const char *p)

    Some examples:
    isMatch("aa","a")       false
    isMatch("aa","aa")      true
    isMatch("aaa","aa")     false
    isMatch("aa", "a*")     true
    isMatch("aa", ".*")     true
    isMatch("ab", ".*")     true
    isMatch("aab", "c*a*b") true
 */

/** solution
    P[i][j] = P[i - 1][j - 1], if p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
    P[i][j] = P[i][j - 2], if p[j - 1] == '*' and the pattern repeats for 0 times;
    P[i][j] = P[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'), if p[j - 1] == '*' and the pattern repeats for at least 1 times.
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool> > dp(m+1,vector<bool>(n+1, false));
        dp[0][0] = true;
        int i,j;
        for(i=0; i<=m; ++i){
            for(j=1; j<=n; ++j){
                if(p[j-1]=='*'){
                    dp[i][j] = dp[i][j-2] || (i>0 && (s[i-1]==p[j-2] || p[j-2]=='.') && dp[i-1][j]);
                }
                else{
                    dp[i][j] = i>0 && (p[j-1]=='.' || s[i-1]==p[j-1]) && dp[i-1][j-1];
                }
            }
        }
        return dp[m][n];
    }
};
/*************************** Submit Part *****************************/

int main()
{
    string s, p;
    while(cin >> s >> p){
        Solution solution;
        cout << solution.isMatch(s, p) << endl;
    }
    return 0;
}

