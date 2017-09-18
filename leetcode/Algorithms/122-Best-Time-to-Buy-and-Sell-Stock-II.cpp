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
    ���������ǿ��Բ������������ֻΪ���������棬
    ���Ҷ���һ�����������У�
    ���磺[5, 1, 2, 3, 4]�е�1, 2, 3, 4������˵���������ֲ���������
    1 ��1���룬4����
    2 ��1���룬2����ͬʱ���룬3����ͬʱ���룬4����
    �����ֲ����£�������һ���ġ�

    ���Կ��Դ�ͷ��βɨ��prices�����price[i] �C price[i-1]��������������������С���̰�ķ�
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
