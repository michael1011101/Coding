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
    1,2,3 �� 1,3,2
    3,2,1 �� 1,2,3
    1,1,5 �� 1,5,1
 */

/** solution
    �ֵ���
    ��P��1~n��һ��ȫ����:
        p=p1 p2......pn = p1 p2......pj-1 pj pj+1......pk-1 pk pk+1......pn
    1�������е��Ҷ˿�ʼ���ҳ���һ�����ұ��ַ�С���ַ������j��j����˿�ʼ���㣩���� j=max{i|p[i]<p[i+1]}
    2����pj���ұߵ��ַ��У��ҳ����б�pj����ַ�����С���ַ�pk����
        k=max{i|pi>pj}���ұߵ��ַ����������ǵ����ģ����k�����д���pj���ַ����������ߣ�
    3���Ի�pj��pk
    4���ٽ�pj+1......pk-1 pk pk+1 pn��ת�õ�����p''=(p1p2.....pj-1 pj) pn.....pk+1 pk pk-1.....pj+1�����������p����һ����һ�����С�
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int _size = nums.size();
        int i;
        int pos = -1;
        //�ҵ����һ�������λ��
        for(i=_size-1; i>0; --i){
            if(nums[i-1] < nums[i]){
                pos = i-1;
                break;
            }
        }

        //��������ڣ���������������һ�֣�
        if(pos < 0) reverse(nums.begin(), nums.end());
        else{//����������ô�ҵ�pos֮�����һ���������λ�ã�������
            for(i=_size-1; i>pos; --i){
                if(nums[i] > nums[pos]){
                    swap(nums[i], nums[pos]);
                    break;
                }
            }
            //��תpos֮�����
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
