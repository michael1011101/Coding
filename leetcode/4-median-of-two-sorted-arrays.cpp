#include <iostream>
#include <vector>
using namespace std;

/**
 * Title: 4. Median of Two Sorted Arrays

    There are two sorted arrays nums1 and nums2 of size m and n respectively.

    Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

    Example 1:
    nums1 = [1, 3]
    nums2 = [2]

    The median is 2.0

    Example 2:
    nums1 = [1, 2]
    nums2 = [3, 4]

    The median is (2 + 3)/2 = 2.5
 */

/** solution
在两个排序的数组中找总体排序的中位数
先是找到size/2位置的数字，然后判断如果是偶数个，找到size/2+1位置的数字
 */


/***************************提交部分*****************************/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int _size = size1 + size2;
        int i,j;
        int position;
        double ans = 0;
        int middle = (_size+1)/2;
        int num;

        position = 0;
        i = j = 0;
        while(position < middle && i<size1 && j<size2){
            if(nums1[i] < nums2[j]){
                num = nums1[i];
                ++i;
            }
            else{
                num = nums2[j];
                ++j;
            }
            position++;
        }
        while(position < middle && i<size1){
            num = nums1[i];
            ++i;
            position++;
        }
        while(position < middle && j<size2){
            num = nums2[j];
            ++j;
            position++;
        }
        ans = num;

        if(_size%2 == 0){
            if(i<size1 && j<size2){
                if(nums1[i] < nums2[j]){
                    num = nums1[i];
                }
                else{
                    num = nums2[j];
                }
            }
            else if(i<size1){
                num = nums1[i];
            }
            else{
                num = nums2[j];
            }
            ans = (ans+num)/2;
        }
        return ans;
    }
};
/***************************提交部分*****************************/

int main()
{
    vector<int> n1, n2;
    int x;
    while(cin >> x, x){
        n1.push_back(x);
    }
    while(cin >> x, x){
        n2.push_back(x);
    }
    Solution solution;
    cout << solution.findMedianSortedArrays(n1, n2);
     return 0;
}
