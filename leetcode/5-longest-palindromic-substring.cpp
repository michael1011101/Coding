#include <iostream>
#include <vector>
using namespace std;

/**
 * Title: 5. Longest Palindromic Substring

    Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

    Example:

    Input: "babad"

    Output: "bab"

    Note: "aba" is also a valid answer.
    Example:

    Input: "cbbd"

    Output: "bb"
 */

/** solution
    中心扩展法
    substr(pos, length) pos起始位置，length是长度
 */


/***************************提交部分*****************************/
class Solution {
public:
    string longestPalindrome(string s) {
        int len;
        int st, ed;
        len = 0;
        st = 0, ed = 1;
        int _size = s.size();
        int i, j, k;
        for(i=0; i<_size; ++i){
            if(_size-i < len/2) break;
            j = k = i;
            while(k<_size && s[j] == s[k]){
                ++k;
            }

            i = --k;  //减少计算相同中心的回文

            while(j>=0 && k<_size && s[j] == s[k]){
                --j, ++k;
            }
            int now = k-j-1;
            if(now > len){
                len = now;
                st = j+1;
                ed = k;
            }
        }
        return s.substr(st,len);
    }
};
/***************************提交部分*****************************/

int main()
{
    string x;
    while(cin >> x){
        Solution solution;
        cout << solution.longestPalindrome(x) << endl;
    }
    return 0;
}
