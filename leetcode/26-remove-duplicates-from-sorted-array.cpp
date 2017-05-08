#include <iostream>
#include <vector>
using namespace std;

/**
 * Title: 26. Remove Duplicates from Sorted Array
    Given a sorted array, remove the duplicates in place
    such that each element appear only once and return the new length.

    Do not allocate extra space for another array, you must do this in place with constant memory.

    For example,
    Given input array nums = [1,1,2],

    Your function should return length = 2,
    with the first two elements of nums being 1 and 2 respectively.
    It doesn't matter what you leave beyond the new length.
 */

/** solution
    ע����������ԭ������ȥ���ظ��ģ�������Ҫ�����治ͬ�ĸ��ǵ�ǰ��
    ���⣬��һ�����ֿ϶������ظ����������鲻Ϊ�յ�ʱ��������һ������
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int _size = nums.size();
        if(_size<2) return _size;
        int i, id=1;
        for(i=1; i<_size; ++i){
            if(nums[i]!=nums[i-1]) nums[id++] = nums[i];
        }
        return id;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x;
    vector<int> nums;
    while(cin>>x){
        nums.push_back(x);
    }
    Solution solution;
    cout << solution.removeDuplicates(nums);
    return 0;
}
