#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Title:383. Ransom Note
    Given an arbitrary ransom note string and
    another string containing letters from all the magazines,
    write a function that will return true if the ransom note can be constructed from the magazines ;
    otherwise, it will return false.

    Each letter in the magazine string can only be used once in your ransom note.

    Note:
    You may assume that both strings contain only lowercase letters.

    canConstruct("a", "b") -> false
    canConstruct("aa", "ab") -> false
    canConstruct("aa", "aab") -> true
 */

/** solution

 */



/*************************** Submit Part *****************************/
class Solution {
private:
    int cnt[255];
public:
    bool canConstruct(string ransomNote, string magazine) {
        int len = magazine.length();
        int i;
        bool flag = true;
        memset(cnt, 0, sizeof(cnt));
        for(i=0; i<len; ++i){
            cnt[magazine[i]]++;
        }

        len = ransomNote.length();
        for(i=0; i<len; ++i){
            if(cnt[ransomNote[i]] == 0){
                flag = false;
                break;
            }
            cnt[ransomNote[i]]--;
        }
        return flag;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    string x, y;
    while(cin >> x >> y){
        Solution solution;
        cout << solution.canConstruct(x,y) << endl;
    }
    return 0;
}
