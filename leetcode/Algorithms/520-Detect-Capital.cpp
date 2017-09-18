#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Title:520. Detect Capital
    Given a word, you need to judge whether the usage of capitals in it is right or not.

    We define the usage of capitals in a word to be right when one of the following cases holds:
    {
    All letters in this word are capitals, like "USA".
    All letters in this word are not capitals, like "leetcode".
    Only the first letter in this word is capital if it has more than one letter, like "Google".
    }

    Otherwise, we define that this word doesn't use capitals in a right way.

    Example 1:
    Input: "USA"
    Output: True

    Example 2:
    Input: "FlaG"
    Output: False
 */

/** solution
    将3种情况都考虑一遍 如果符合某一种情况就返回true，全部符合返回false
 */



/*************************** Submit Part *****************************/
class Solution {
public:
    bool detectCapitalUse(string word) {
        int len = word.length();
        bool flag = false;
        for(int i=1; i<=3; ++i){
            flag = flag || judgeMode(word, i);
        }

        return flag;
    }
private:
    bool judgeMode(string word, int way){
        int len = word.length();
        switch(way){
        case 1:
            for(int i=0; i<len; ++i){
                if(!(word[i]>='A'&&word[i]<='Z'))   return false;
            }
            break;
        case 2:
            for(int i=0; i<len; ++i){
                if(!(word[i]>='a'&&word[i]<='z'))   return false;
            }
            break;
        case 3:
            if(!(word[0]>='A'&&word[0]<='Z')) return false;
            for(int i=1; i<len; ++i){
                if(!(word[i]>='a'&&word[i]<='z'))   return false;
            }
            break;
        }
        return true;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    string str;
    while(cin >> str){
        Solution solution;
        cout << solution.detectCapitalUse(str) << endl;
    }
    return 0;
}
