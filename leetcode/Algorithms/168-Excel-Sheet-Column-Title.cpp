#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Title: 168. Excel Sheet Column Title
    Given a positive integer,
    return its corresponding column title as appear in an Excel sheet.

    For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB
 */

/** solution
    由于不是从0开始，所以注意减去1再取模，
    这样就可以0-A，1-B，2-C……
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    string convertToTitle(int n) {
        string str = "";
        while(n>0){
            n--;
            int tmp = n%26;
            n /= 26;
            str += 'A'+tmp;
        }
        reverse(str.begin(), str.end());
        return str;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int n;
    while(cin >> n){
        Solution solution;
        cout << solution.convertToTitle(n) << endl;
    }
    return 0;
}
