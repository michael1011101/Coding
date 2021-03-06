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
 * Title:70. Climbing Stairs
    You are climbing a stair case. It takes n steps to reach to the top.

    Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

    Note: Given n will be a positive integer.
 */

/** solution
    dp (easy)
    fibonacci
 */



/*************************** Submit Part *****************************/
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        if(n <= 2) return n;
        dp[1] = 1;
        dp[2] = 2;
        int i;
        for(i=3; i<=n; ++i){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x;
    cin >> x;

    Solution solution;
    cout << solution.climbStairs(x) << endl;
    return 0;
}
