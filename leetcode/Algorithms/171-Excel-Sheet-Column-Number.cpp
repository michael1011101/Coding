#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Title: 171. Excel Sheet Column Number
    Related to question Excel Sheet Column Title

    Given a column title as appear in an Excel sheet,
    return its corresponding column number.

    For example:

        A -> 1
        B -> 2
        C -> 3
        ...
        Z -> 26
        AA -> 27
        AB -> 28
 */

/** solution

 */


/*************************** Submit Part *****************************/
class Solution {
public:
    int titleToNumber(string s) {
        int _size = s.size();
        int ans = 0;
        for(int i=0; i<_size; ++i){
            ans = ans*26 + s[i] - 'A' + 1;
        }
        return ans;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    string s;
    while(cin >> s){
        Solution solution;
        cout << solution.titleToNumber(s) << endl;
    }
    return 0;
}
