#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <unordered_set>
#include <algorithm>
using namespace std;

/**
 * Title:263. Ugly Number
    Write a program to check whether a given number is an ugly number.

    Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
    For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

    Note that 1 is typically treated as an ugly number.
 */

/** solution
    Ugly number是因子只为2,3,5的正数数字，1是特殊的Ugly number
    所以我们将2,3,5除完，判断是否等于1
 */



/*************************** Submit Part *****************************/
class Solution {
public:
    bool isUgly(int num) {
        if(num == 1) return true;
        if(num <= 0) return false;
        while(num%2==0) num /= 2;
        while(num%3==0) num /= 3;
        while(num%5==0) num /= 5;
        return num == 1;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x;
    while(cin >> x){
        Solution solution;
        cout << solution.isUgly(x) << endl;
    }
    return 0;
}
