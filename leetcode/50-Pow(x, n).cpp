#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Title: 50. Pow(x, n)
    Implement pow(x, n).
 */

/** solution
    1. n�����Ǹ��� �߽�ֵ-2147483648 ���Բ���ֱ��ȡ-n
    2. while(tmp>0) ��Ҫ�� while(tmp)
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    double myPow(double x, int n) {
        //������
        double ans = 1;
        bool flag = true;
        long long tmp = n;
        if(tmp<0){
            tmp = -tmp;
            x = 1/x;
            flag = false;
        }
        while(tmp>0){
            if(tmp&1) ans*=x;
            x *= x;
            tmp >>= 1;
        }
        return ans;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    double x;
    int n;
    cin >> x >> n;
    Solution solution;
    cout << solution.myPow(x, n);
    return 0;
}
