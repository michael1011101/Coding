#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

/**
 * Title: 28. Implement strStr()
    Implement strStr().

    Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 */

/** solution
    "", "", return 0
    "a", "", return 0
    "", "a", return -1
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    int strStr(string haystack, string needle) {
        int lenHeystack = haystack.length();
        int lenNeedle = needle.length();

        if(lenHeystack < lenNeedle) return -1;
        if(lenNeedle==0) return 0;
        for(int i=0; i<lenHeystack-lenNeedle+1; ++i){
            if(haystack[i] == needle[0]){
                if(isPrefix(haystack.substr(i, lenNeedle), needle))
                    return i;
            }
        }
        return -1;
    }
private:
    bool isPrefix(string str, string prefix){
        int len = prefix.length();
        for(int i=0; i<len; ++i){
            if(str[i]!=prefix[i]) return false;
        }
        return true;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    string haystack, needle;
    getline(cin, haystack);
    getline(cin, needle);
    Solution solution;
    cout << solution.strStr(haystack, needle) << endl;
    return 0;
}
