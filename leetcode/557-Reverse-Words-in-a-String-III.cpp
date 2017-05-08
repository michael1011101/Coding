#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <unordered_set>
#include <algorithm>
using namespace std;

/**
 * Title:557. Reverse Words in a String III
    Given a string, you need to reverse the order of characters
    in each word within a sentence while still preserving whitespace and initial word order.

    Example 1:
    Input: "Let's take LeetCode contest"
    Output: "s'teL ekat edoCteeL tsetnoc"

 */

/** solution

 */



/*************************** Submit Part *****************************/
class Solution {
public:
    string reverseWords(string s) {
        int len = s.length();
        int i,j;
        for(i=j=0; i<len; ++i){
            while(i<len&&s[i]==' ') ++i;
            j = i;
            while(j<len&&s[j]!=' ') ++j;
            reverse(s.begin()+i, s.begin()+j);
            i = j;
        }
        if(i<j) reverse(s.begin()+i, s.begin()+j);
        return s;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    string str;
    while(getline(cin, str)){
        Solution solution;
        cout << solution.reverseWords(str) << endl;
    }
    return 0;
}
