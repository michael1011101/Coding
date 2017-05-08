#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Title: 38. Count and Say
    The count-and-say sequence is the sequence of integers beginning as follows:
    1, 11, 21, 1211, 111221, ...

    1 is read off as "one 1" or 11.
    11 is read off as "two 1s" or 21.
    21 is read off as "one 2, then one 1" or 1211.
    Given an integer n, generate the nth sequence.

    Note: The sequence of integers will be represented as a string.
 */

/** solution
    简单的数数练习
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        if(n==1) return ans;
        else{
            for(int i=1; i<n; ++i){
                ans = countAndSay(ans);
            }
            return ans;
        }
    }
private:
    string countAndSay(string x){
        string y = "";
        int _size = x.size();
        int cnt;
        for(int i=0; i<_size; ++i){
            cnt = 1;
            while(i+1<_size&&x[i]==x[i+1]){
                cnt++;
                i++;
            }
            y += cnt+'0';
            y += x[i];
        }
        return y;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x;
    while(cin >> x){
        Solution solution;
        cout << solution.countAndSay(x) << endl;
    }
    return 0;
}
