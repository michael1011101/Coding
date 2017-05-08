#include <iostream>
#include <string>
using namespace std;

/**
 * Title: 12. Integer to Roman
    Given an integer, convert it to a roman numeral.

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
    string intToRoman(int num) {
        return intToRoman(num, 0);
    }
private:
    string roman[5][10] = {
        {"","I","II","III","IV","V","VI","VII","VIII","IX"},
        {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
        {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
        {"","M","MM","MMM"}
    };
    string intToRoman(int num, int bit){
        if(num != 0){
            return intToRoman(num/10, bit+1) + roman[bit][num%10];
        }
        return "";
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x;
    while(cin >> x){
        Solution solution;
        cout << solution.intToRoman(x) << endl;
    }
    return 0;
}
