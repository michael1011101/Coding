#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

/**
 * Title:  438. Find All Anagrams in a String
    Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

    Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

    The order of output does not matter.

    Example 1:

    Input:
    s: "cbaebabacd" p: "abc"

    Output:
    [0, 6]

    Explanation:
    The substring with start index = 0 is "cba", which is an anagram of "abc".
    The substring with start index = 6 is "bac", which is an anagram of "abc".
    Example 2:

    Input:
    s: "abab" p: "ab"

    Output:
    [0, 1, 2]

    Explanation:
    The substring with start index = 0 is "ab", which is an anagram of "ab".
    The substring with start index = 1 is "ba", which is an anagram of "ab".
    The substring with start index = 2 is "ab", which is an anagram of "ab".
 */

/** solution
    用一个数组来维护连续lenp（p的长度）个字符出现的次数。

 */


/*************************** Submit Part *****************************/
class Solution {
    int appear[255];
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> vec;
        int lens = s.length();
        int lenp = p.length();

        if(lens==0 || lenp==0 || lens < lenp) return vec;

        memset(appear, 0, sizeof(appear));
        for(int i=0; i<lenp; ++i){
            appear[p[i]]++;
        }


        for(int i=0, j=0; i<lens; ++i){
            appear[s[i]]--;
            if(i-j+1 == lenp){
                if(isAnagrams()){
                    vec.push_back(j);
                }
                appear[s[j++]]++;
            }

        }
        return vec;
    }
private:
    bool isAnagrams(){
        for(int i='a'; i<='z'; ++i){
            if(appear[i]>0) return false;
        }
        return true;
    }
};
/*************************** Submit Part *****************************/

int main()
{

    return 0;
}

