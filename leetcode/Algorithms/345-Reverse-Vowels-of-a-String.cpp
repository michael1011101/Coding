#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <unordered_set>
#include <algorithm>
using namespace std;

/**
 * Title:345. Reverse Vowels of a String
    Write a function that takes a string as input and reverse only the vowels of a string.

    Example 1:
    Given s = "hello", return "holle".

    Example 2:
    Given s = "leetcode", return "leotcede".

    Note:
    The vowels does not include the letter "y".
 */

/** solution
    将字符串中的元音字符反转
 */



/*************************** Submit Part *****************************/
class Solution {
public:
    string reverseVowels(string s) {
        vector<char> vec;
        int len = s.length();
        for(int i=0; i<len; ++i){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||
               s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                vec.push_back(s[i]);
            }
        }
        reverse(vec.begin(), vec.end());
        for(int i=0, j=0; i<len; ++i){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||
               s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                s[i] = vec[j++];
            }
        }
        return s;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    string str;
    while(cin >> str){
        Solution solution;
        cout << solution.reverseVowels(str) << endl;
    }
    return 0;
}
