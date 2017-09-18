#include <iostream>
#include <map>
#include <cstring>
using namespace std;

/**
 * Title: 3. Longest Substring Without Repeating Characters

    Given a string, find the length of the longest substring without repeating characters.

    Examples:

    Given "abcabcbb", the answer is "abc", which the length is 3.

    Given "bbbbb", the answer is "b", with the length of 1.

    Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

    Subscribe to see which companies asked this question.
 */

/** solution
    设置st,ed两个哨兵，
    [st, ed)之间是没有重复访问的字符，
    每次st向后移一位，ed向后移动一直到发现重复访问(或者到字符串最后)
 */


/***************************提交部分*****************************/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool visit[255];
        memset(visit, false, sizeof(visit));

        int _max = 0;
        int _size = s.size();
        int st, ed;
        st = ed = 0;
        for(; st<_size; ++st){
            while(ed < _size && !visit[s[ed]]){
                visit[s[ed]] = true;
                ed++;
            }
            _max = max(_max, ed-st);
            visit[s[st]] = false;
        }
        return _max;
    }
};
/***************************提交部分*****************************/

int main()
{
    Solution solution;
    string s;
    while(cin >> s){
        cout << solution.lengthOfLongestSubstring(s) << endl;
    }
    return 0;
}
