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
 * Title:53. Maximum Subarray
    Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

    For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
    the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 */

/** solution
    st�ǿ�ʼ�� ed�ǽ����� cnt�������ݴ�ĺ�

    ��Ϊ������������ӣ�����˵һֱ��ӵ�ʱ��С��0���п��ܼ��Ϻ����ֵ�������ֵ

    ���cnt+nums[i]<0 ��ô��cnt����Ϊnums[i], st,edΪi
    ���cnt+nums[i}>=0 ��ôcnt=cnt+nums[i], ed=i

    Ȼ���ж����cnt>ans����ô����ans,left,right��ֵ

    ������cnt<0,��ô��ʼ��cnt=0

    ��Ϊ��ֹ���鶼�Ǹ��������Բ�����һ��ʼ��ans����Ϊ0��
    �����ڳ�ʼ����ʱ��������ĵ�һλ������ʼ����
    left = right = 0, ans = nums[0]
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int left, right, ans;
        int st, ed, cnt;
        int _size = nums.size();
        left = right = 0, ans = nums[0];
        cnt = 0;
        for(int i=0; i<_size; ++i){
            if(cnt+nums[i] < 0){
                cnt = nums[i];
                st = ed = i;
            }
            else{
                cnt += nums[i];
                ed = i;
            }

            if(cnt > ans){
                ans = cnt;
                left = st;
                right = ed;
            }

            if(cnt < 0){
                cnt = 0;
                st = ed = i+1;
            }
        }
        return ans;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    vector<int> nums;
    int x;
    while(cin >> x){
        nums.push_back(x);
    }

    Solution solution;
    cout << solution.maxSubArray(nums) << endl;
    return 0;
}
