#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Title:172. Factorial Trailing Zeroes
    Given an integer n, return the number of trailing zeroes in n!.

    Note: Your solution should be in logarithmic time complexity.
 */

/** solution
    ����0һ��������2*5=10�γɵ�
    ����2�ĸ�����5�࣬�������Ǽ�������5�ĸ���
 */



/*************************** Submit Part *****************************/
class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0;
        while(n){
            n /= 5;
            cnt += n;
        }
        return cnt;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x;
    while(cin >> x){
        Solution solution;
        cout << solution.trailingZeroes(x) << endl;
    }
    return 0;
}
