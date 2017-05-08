#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/**
 * Title: 17. Letter Combinations of a Phone Number
    Given a digit string, return all possible letter combinations that the number could represent.

    A mapping of digit to letters (just like on the telephone buttons) is given below.



    Input:Digit string "23"
    Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 */

/** solution
    模拟打字符串，注意空串的时候，返回空的vector<string>()
 */


/*************************** Submit Part *****************************/
class Solution {
private:
    string phone[10] = {"", "abc", "def",
                    "ghi", "jkl", "mno",
                    "pqrs", "tuv", "wxyz"};
    int num[10]={0,3,3,3,3,3,4,3,4};
public:
    vector<string> letterCombinations(string digits) {
        queue<string> que;
        int _size = digits.size();
        int digit;
        vector<string> ans;
        string str="";
        que.push(str);

        if(_size==0) return vector<string>();

        for(int i=0; i<_size; ++i){
            digit = digits[i]-'1';
            while(!que.empty()){
                str = que.front();
                if(str.size()>i) break;
                que.pop();
                for(int j=0; j<num[digit]; ++j){
                    que.push(str+phone[digit][j]);
                }
            }
        }

        while(!que.empty()){
            ans.push_back(que.front());
            que.pop();
        }
        return ans;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    string digits;
    cin >> digits;
    Solution solution;
    vector<string> ans = solution.letterCombinations(digits);
    int _size = ans.size();
    for(int i=0; i<_size; ++i){
        cout << ans[i] << endl;
    }
    return 0;
}

