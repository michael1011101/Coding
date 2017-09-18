#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Title: 367. Valid Perfect Square
    Given a positive integer num,
    write a function which returns True if num is a perfect square else False.

    Note: Do not use any built-in library function such as sqrt.
 */

/** solution
    不可以使用sqrt，如果num=x*x，那么返回true。
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    bool isPerfectSquare(int num){
        long long left = 0, right = num;
        long long mid;
        long long target = num;
        bool flag = false;
        while(left<=right){
            mid = (left+right)/2;
            if(mid*mid == target){
                flag = true;
                break;
            }
            else if(mid*mid < target){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return flag;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x;
    while(cin >> x){
        Solution solution;
        cout << solution.isPerfectSquare(x) << endl;
    }
    return 0;
}
