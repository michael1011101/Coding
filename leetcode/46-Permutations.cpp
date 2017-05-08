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
 * Title: 46. Permutations
    Given a collection of distinct numbers, return all possible permutations.

    For example,
    [1,2,3] have the following permutations:
    [
      [1,2,3],
      [1,3,2],
      [2,1,3],
      [2,3,1],
      [3,1,2],
      [3,2,1]
    ]
 */

/** solution
    排列数
    首先对数组排序
    然后组建下一个排列的方法如下：
    1.找到max{i; num[i]<num[i+1]}, 如果没有就是结束
    2.找到max{j; num[i]<num[j]}
    3.将 num[i] 与 num[j] 交换
    4.将 num[i]之后的数组（不包括num[i]）反转
    即得出下一个排列
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > ans;
        sort(nums.begin(), nums.end());

        int i,j;
        int _size = nums.size();
        for(;;){

            ans.push_back(nums);
            for(i=_size-2; i>=0; --i){
                if(nums[i] < nums[i+1]) break;
            }
            if(i<0) break;
            for(j=_size-1; j>i; --j){
                if(nums[j] > nums[i]) break;
            }

            swap(nums[i], nums[j]);

            reverse(nums.begin()+i+1, nums.end());

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

    vector<vector<int> > ans;
    Solution solution;
    ans = solution.permute(num);
    for(vector<vector<int> >::iterator it = ans.begin(); it != ans.end(); ++it){
        vector<int> tmp = *it;
        for(vector<int>::iterator iit = tmp.begin(); iit != tmp.end(); ++iit){
            cout << *iit << ' ';
        }
        cout << endl;
    }
    return 0;
}
