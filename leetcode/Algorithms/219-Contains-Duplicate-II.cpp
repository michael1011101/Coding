#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

/**
 * Title:  219. Contains Duplicate II
    Given an array of integers and an integer k,
    find out whether there are two distinct indices i and j in the array
    such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
 */

/** solution
    ��set��ά������k+1����������µ����ֽ������Ƚ��������־���Ϊk+1λ����ȥ��
    ���ж��������Ƿ��ڼ����У�����ڣ�����true��
    ���򣬽������ַ��뵽set�С�
    �ж������е����֣���󷵻�false��
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k<=0) return false;
        unordered_set<int> uset;
        int numsSize = nums.size();
        for(int i=0; i<numsSize; ++i){
            if(i>k) uset.erase(nums[i-k-1]);
            if(uset.find(nums[i])!=uset.end()) return true;
            uset.insert(nums[i]);
        }
        return false;
    }
};
/*************************** Submit Part *****************************/

int main()
{

    return 0;
}

