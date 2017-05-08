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
 * Title:500. Keyboard Row
     Given a List of words,
     return the words that can be typed using letters of alphabet
     on only one row's of American keyboard like the image below.


    Example 1:
    Input: ["Hello", "Alaska", "Dad", "Peace"]
    Output: ["Alaska", "Dad"]
 */

/** solution
    C++11: unordered_set
    大小写 都是属于这个字母 所以我们在判断的时候，把所有的大写都变为小写
    首先判断在哪一行， 然后在判断是不是所有字母都在这一行
 */



/*************************** Submit Part *****************************/
class Solution {
private:
    unordered_set<char> row1 {'q','w','e','r','t','y','u','i','o','p'};
    unordered_set<char> row2 {'a','s','d','f','g','h','j','k','l'};
    unordered_set<char> row3 {'z','x','c','v','b','n','m'};
    vector<unordered_set<char> > rows {row1, row2, row3};

public:
    vector<string> findWords(vector<string>& words) {
        int _size = words.size();
        int i, j, row;
        vector<string> valid_words;

        for(i=0; i<_size; ++i){
            for(j=0; j<3; ++j){
                if(rows[j].count((char)tolower(words[i][0]))>0) row = j;
            }

            valid_words.push_back(words[i]);
            int len = words[i].length();
            for(j=0; j<len; ++j){
                if(rows[row].count((char)tolower(words[i][j]))==0){
                    valid_words.pop_back();
                    break;
                }
            }
        }

        return valid_words;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    string str;
    vector<string> words;
    while(cin >> str){
        words.push_back(str);
    }

    Solution solution;
    vector<string> valids;
    valids = solution.findWords(words);
    for(vector<string>::iterator it=valids.begin(); it!=valids.end(); ++it){
        cout << *it << ' ';
    }
    return 0;
}
