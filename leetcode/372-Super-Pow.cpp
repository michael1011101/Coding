#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Title: 372. Super Pow
    Your task is to calculate ab mod 1337
    where a is a positive integer
    and b is an extremely large positive integer given in the form of an array.

    Example1:

    a = 2
    b = [3]

    Result: 8
    Example2:

    a = 2
    b = [1,0]

    Result: 1024
 */

/** solution
    用快速幂 同时模拟十进制快速幂的方法
    注意a可以很大，所以对a取模
 */


/*************************** Submit Part *****************************/
class Solution {
private:
    const int MOD = 1337;
    long long fast_Pow(int x, int n){
        int ans = 1;
        while(n>0){
            if(n&1) ans = ans*x%MOD;
            x = x*x%MOD;
            n >>= 1;
        }
        return ans;
    }
public:
    int superPow(int a, vector<int>& b) {
        int _size = b.size();
        int ans = 1;
        a %= MOD;
        for(int i=0; i<_size; ++i){
            ans = (fast_Pow(ans, 10) * fast_Pow(a, b[i])) % MOD;
        }
        return ans;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int a, x;
    vector<int> b;
    cin >> a;
    while(cin >> x) b.push_back(x);
    Solution solution;
    cout << solution.superPow(a, b) << endl;
    return 0;
}
