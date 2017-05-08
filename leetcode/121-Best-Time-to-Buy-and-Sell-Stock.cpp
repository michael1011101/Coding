#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Title:121. Best Time to Buy and Sell Stock
    Say you have an array for which the ith element is the price of a given stock on day i.

    If you were only permitted to complete at most one transaction
    (ie, buy one and sell one share of the stock),
    design an algorithm to find the maximum profit.

    Example 1:
    Input: [7, 1, 5, 3, 6, 4]
    Output: 5

    max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
    Example 2:
    Input: [7, 6, 4, 3, 1]
    Output: 0

    In this case, no transaction is done, i.e. max profit = 0.
 */

/** solution
    first to buy, then to sell
    so we find the latter one to minus the former one and get the maximum.
 */



/*************************** Submit Part *****************************/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price;
        int ans;
        int _size = prices.size();
        if(_size == 0)  return 0;

        min_price = prices[0];
        ans = 0;
        for(int i=1; i<_size; ++i){
            if(min_price > prices[i]) min_price = prices[i];
            ans = max(ans, prices[i] - min_price);
        }
        return ans;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x;
    vector<int> num;
    while(cin >> x) num.push_back(x);

    Solution solution;
    cout << solution.maxProfit(num) << endl;
    return 0;
}
