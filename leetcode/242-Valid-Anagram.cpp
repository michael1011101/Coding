#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

/**
 * Title:242. Valid Anagram
    Given two strings s and t, write a function to determine if t is an anagram of s.

    For example,
    s = "anagram", t = "nagaram", return true.
    s = "rat", t = "car", return false.

    Note:
    You may assume the string contains only lowercase alphabets.
 */

/** solution
    判断两个字符串是否由相同字母构成的
    那么就将字母存储下，然后比较是否相同
 */



/*************************** Submit Part *****************************/
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> vecs(26,0), vect(26,0);
        int len = s.length();
        for(int i=0; i<len; ++i) vecs[s[i]-'a']++;
        len = t.length();
        for(int i=0; i<len; ++i) vect[t[i]-'a']++;

        return vecs == vect;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    string s, t;
    while(cin >> s >> t){
        Solution solution;
        cout << solution.isAnagram(s, t) << endl;
    }
    return 0;
}
