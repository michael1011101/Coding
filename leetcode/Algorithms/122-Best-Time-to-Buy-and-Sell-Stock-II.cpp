#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

/**
 * Title:122. Best Time to Buy and Sell Stock II
    Say you have an array for which the ith element is the price of a given stock on day i.

    Design an algorithm to find the maximum profit.
    You may complete as many transactions as you like
    (ie, buy one and sell one share of the stock multiple times).
    However, you may not engage in multiple transactions at the same time
    (ie, you must sell the stock before you buy again).
 */

/** solution
    本题由于是可以操作任意次数，只为获得最大收益，
    而且对于一个上升子序列，
    比如：[5, 1, 2, 3, 4]中的1, 2, 3, 4序列来说，对于两种操作方案：
    1 在1买入，4卖出
    2 在1买入，2卖出同时买入，3卖出同时买入，4卖出
    这两种操作下，收益是一样的。

    所以可以从头到尾扫描prices，如果price[i] – price[i-1]大于零则计入最后的收益中。即贪心法
 */



/*************************** Submit Part *****************************/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int _size = prices.size();
        int i;
        for(int i=1; i<_size; ++i){
            if(prices[i] > prices[i-1]){
                ans += prices[i]-prices[i-1];
            }
        }

        return ans;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x;
    vector<int> nums;
    while(cin >> x){
        nums.push_back(x);
    }

    Solution solution;
    cout << solution.maxProfit(nums) << endl;
    return 0;
}
