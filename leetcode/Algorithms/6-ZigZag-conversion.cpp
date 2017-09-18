#include <iostream>
#include <vector>
using namespace std;

/**
 * Title: 6. ZigZag Conversion

    The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
    (you may want to display this pattern in a fixed font for better legibility)

    P   A   H   N
    A P L S I I G
    Y   I   R
    And then read line by line: "PAHNAPLSIIGYIR"
    Write the code that will take a string and make this conversion given a number of rows:

    string convert(string text, int nRows);
    convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */

/** solution
    曲折图形然后横向输出即可
    1    7
    2   6 8     …
    3 5    9  11
    4       10
 */


/***************************提交部分*****************************/
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;  //special handling

        vector<string> vec;
        for(int i=0; i<numRows; ++i){
            string s = "";
            vec.push_back(s);
        }
        int _size = s.size();
        for(int i=0, j=0, k=1; i<_size; ++i){
            vec[j] += s[i];
            if(j+k<0 || j+k>=numRows){
                k*=-1;
            }
            j += k;
        }
        string ans = "";
        for(int i=0; i<numRows; ++i){
            ans += vec[i];
        }
        return ans;
    }
};
/***************************提交部分*****************************/

int main()
{
    int row;
    string s;
    while(cin >> s >> row){
        Solution solution;
        cout << solution.convert(s, row) << endl;
    }
    return 0;
}
