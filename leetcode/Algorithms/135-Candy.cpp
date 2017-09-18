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
 * Title: 135. Candy
    There are N children standing in a line. Each child is assigned a rating value.

    You are giving candies to these children subjected to the following requirements:

    Each child must have at least one candy.
    Children with a higher rating get more candies than their neighbors.
    What is the minimum candies you must give?
 */

/** solution
    贪心，如果越来越大，给的糖果就变多
    如果变小，给的糖果就减少
    由大到小的时候(即拐点下一位，a[i-1]<a[i]>a[i+1])，a[i+1]处糖果num[i+1]变为1，
    如果继续减小，a[j](j>i+1)的糖果num[j]变为1，由于a[j-1]>a[j],所以相应的前面num[i+1, j]的糖果都得加1
    当 j-i >= num[i] 说明下降的很多，那么num[i]也得随着加一

    还有一种情况就是a[i] = a[i+1]时候，由于我们需要得到最小的糖果数量，所以a[i+1]处num[i+1]=1

    测试用例：
    4 2 3 4 1
    4 2 3 4 3 2 1
    4 2 3 8 7 6 5 4 3 2 1
    4 3 3
    4 3 3 3 3
    4 3 3 3 2
    4 3 3 3 2 1
    4 8 8 7 6 5 4


    注意：
    变量说明：
    flag 一个标记，表示从上升转向下降的时候，
    peak 记录拐点的大小，
    desc 记录下降的数量
    now  记录当前给的candy数量
    sum  记录总和
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int _size = ratings.size();

        int sum, now, desc;
        int peak;
        bool flag = true;
        sum = now = desc = 0;
        for(int i=0; i<_size; ++i){
            if(i == 0){
                sum = now = 1;
            }
            else if(ratings[i] > ratings[i-1]){
                now++;
                sum += now;
                desc = 0;
                flag = true;
            }
            else if(ratings[i] == ratings[i-1]){
                now = 1;
                sum += now;
                flag = true;
                desc = 0;
            }
            else{
                if(flag){
                    flag = false;
                    peak = now;
                }

                now = 1;
                sum += now+desc;
                desc++;
                if(desc >= peak) sum++;
            }
        }
        return sum;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x;
    vector<int> num;
    while(cin >> x) num.push_back(x);

    Solution solution;
    cout << solution.candy(num) << endl;
    return 0;
}
