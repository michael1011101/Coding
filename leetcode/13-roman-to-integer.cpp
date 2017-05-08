#include <iostream>
#include <string>
using namespace std;

/**
 * Title: 13. Roman to Integer
    Given a roman numeral, convert it to an integer.

    Input is guaranteed to be within the range from 1 to 3999.

    Subscribe to see which companies asked this question.
 */

/** solution
    I   1     L   50    M  1000
    V   5     C  100
    X  10     D  500
    1~9:        {"","I","II","III","IV","V","VI","VII","VIII","IX"},
    10~90:      {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
    100~900:    {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
    1000~3000:  {"","M","MM","MMM"}

 */


/*************************** Submit Part *****************************/
class Solution {
public:
    int romanToInt(string s) {
        int _size = s.size();
        int ans = 0;
        for(int i=0; i<_size; ++i){
            switch(s[i]){
                case 'I':
                    if(s[i+1]=='V'||s[i+1]=='X') ans -= 1;
                    else ans += 1;
                    break;
                case 'V':
                    ans += 5;
                    break;
                case 'X':
                    if(s[i+1]=='L'||s[i+1]=='C') ans -= 10;
                    else ans += 10;
                    break;
                case 'L':
                    ans += 50;
                    break;
                case 'C':
                    if(s[i+1]=='D'||s[i+1]=='M') ans -= 100;
                    else ans += 100;
                    break;
                case 'D':
                    ans += 500;
                    break;
                case 'M':
                    ans += 1000;
                    break;
            }
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
        cout << solution.romanToInt(s) << endl;
    }
    return 0;
}
