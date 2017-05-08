#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <unordered_set>
#include <algorithm>
using namespace std;

/**
 * Title:551. Student Attendance Record I
    You are given a string representing an attendance record for a student.
    The record only contains the following three characters:

    'A' : Absent.
    'L' : Late.
    'P' : Present.
    A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent)
    or more than two continuous 'L' (late).

    You need to return whether the student could be rewarded according to his attendance record.

    Example 1:
    Input: "PPALLP"
    Output: True

    Example 2:
    Input: "PPALLL"
    Output: False
 */

/** solution

 */



/*************************** Submit Part *****************************/
class Solution {
public:
    bool checkRecord(string s) {
        bool flag = true;
        int Anum, max_continue_L;
        Anum = max_continue_L = 0;
        int tmp;
        int len = s.length();
        int i;
        for(i=0; i<len; ++i){
            if(s[i]=='A') Anum++;
            if(s[i]=='L'){
                if(i-1<0){
                    tmp = 1;
                }
                else if(s[i-1]=='L'){
                    tmp ++;
                }
                else{
                    tmp = 1;
                }
                max_continue_L = max(max_continue_L, tmp);
            }
        }
        if(Anum>1||max_continue_L>2) flag = false;

        return flag;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    string str;
    while(cin >> str){
        Solution solution;
        cout << solution.checkRecord(str) << endl;
    }
    return 0;
}
