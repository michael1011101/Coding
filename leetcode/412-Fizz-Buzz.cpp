#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Title: 412. Fizz Buzz
    Write a program that outputs the string representation of numbers from 1 to n.

    But for multiples of three it should output “Fizz” instead of the number
    and for the multiples of five output “Buzz”.
    For numbers which are multiples of both three and five output “FizzBuzz”.
 */

/** solution

 */


/*************************** Submit Part *****************************/
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        int i;
        for(i=1; i<=n; ++i){
            if(i%3==0 && i%5==0){
                ans.push_back("FizzBuzz");
            }
            else if(i%3==0){
                ans.push_back("Fizz");
            }
            else if(i%5==0){
                ans.push_back("Buzz");
            }
            else{
                ans.push_back(int2str(i));
            }
        }
        return ans;
    }
private:
    string int2str(int x){
        string str="";
        stack<char> st;
        while(x){
            st.push(x%10+'0');
            x /= 10;
        }
        while(!st.empty()){
            str += st.top();
            st.pop();
        }
        return str;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x;
    cin >> x;
    Solution solution;
    vector<string> ans = solution.fizzBuzz(x);
    for(vector<string>::iterator it=ans.begin(); it!=ans.end(); ++it){
        cout << *it << endl;
    }
    return 0;
}
