#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

/**
 * Title:434. Number of Segments in a String
    Count the number of segments in a string,
    where a segment is defined to be a contiguous sequence of non-space characters.

    Please note that the string does not contain any non-printable characters.

    Example:

    Input: "Hello, my name is John"
    Output: 5
 */

/** solution

 */



/*************************** Submit Part *****************************/
class Solution {
public:
    int countSegments(string s) {
        int len = s.length();
        int i;
        bool flag = false;
        int cnt = 0;
        for(i=0; i<len; ++i){
            if(s[i]==' '){
                cnt = flag ? cnt+1 : cnt;
                flag = false;
            }
            else{
                flag = true;
            }
        }
        cnt = flag ? cnt+1 : cnt;
        return cnt;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    string str;
    while(getline(cin, str)){
        Solution solution;
        cout << solution.countSegments(str) << endl;
    }
    return 0;
}
