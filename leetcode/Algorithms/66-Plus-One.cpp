#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Title: 66. Plus One
    Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

    You may assume the integer do not contain any leading zero, except the number 0 itself.

    The digits are stored such that the most significant digit is at the head of the list.
 */

/** solution

 */


/*************************** Submit Part *****************************/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int _size = digits.size();
        int carry = 0;
        digits[0] += 1;
        for(int i=0; i<_size; ++i){
            int tmp = digits[i] + carry;
            digits[i] = tmp % 10;
            carry = tmp / 10;
        }
        if(carry!=0) digits.push_back(carry);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x;
    vector<int> digits;
    while(cin >> x){
        digits.push_back(x);
    }
    Solution solution;
    vector<int> ans = solution.plusOne(digits);
    for(vector<int>::iterator it=ans.begin(); it!=ans.end(); ++it){
        cout << *it << ' ';
    }
    return 0;
}
