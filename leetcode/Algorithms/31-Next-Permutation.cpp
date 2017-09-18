#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Title: 31. Next Permutation
    Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

    If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

    The replacement must be in-place, do not allocate extra memory.

    Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
    1,2,3 → 1,3,2
    3,2,1 → 1,2,3
    1,1,5 → 1,5,1
 */

/** solution
    字典序法
    设P是1~n的一个全排列:
        p=p1 p2......pn = p1 p2......pj-1 pj pj+1......pk-1 pk pk+1......pn
    1、从排列的右端开始，找出第一个比右边字符小的字符的序号j（j从左端开始计算），即 j=max{i|p[i]<p[i+1]}
    2、在pj的右边的字符中，找出所有比pj大的字符中最小的字符pk，即
        k=max{i|pi>pj}（右边的字符从右至左是递增的，因此k是所有大于pj的字符中序号最大者）
    3、对换pj，pk
    4、再将pj+1......pk-1 pk pk+1 pn倒转得到排列p''=(p1p2.....pj-1 pj) pn.....pk+1 pk pk-1.....pj+1，这就是排列p的下一个下一个排列。
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int _size = nums.size();
        int i;
        int pos = -1;
        //找到最后一个升序的位置
        for(i=_size-1; i>0; --i){
            if(nums[i-1] < nums[i]){
                pos = i-1;
                break;
            }
        }

        //如果不存在，即到了排序的最后一种，
        if(pos < 0) reverse(nums.begin(), nums.end());
        else{//存在升序，那么找到pos之后最后一个比它大的位置，并交换
            for(i=_size-1; i>pos; --i){
                if(nums[i] > nums[pos]){
                    swap(nums[i], nums[pos]);
                    break;
                }
            }
            //反转pos之后的数
            reverse(nums.begin()+pos+1, nums.end());
        }
    }
};
/*************************** Submit Part *****************************/

int main()
{
    vector<int> nums;
    int x;
    while(cin >> x) nums.push_back(x);
    Solution solution;
    solution.nextPermutation(nums);
    for(vector<int>::iterator it = nums.begin(); it!=nums.end(); ++it){
        cout << *it << ' ';
    }
    return 0;
}
