#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

/**
 * Title:349. Intersection of Two Arrays
    Given two arrays, write a function to compute their intersection.

    Example:
    Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

    Note:
    Each element in the result must be unique.
    The result can be in any order.
 */

/** solution
    排序之后
    每个数组向后找
    如果 nums1[i] == nums2[j]，再判断是否加入最后的结果（当然也可以用个set存储，不过由于已经有序了所以与存储的最后一位判断是否重复就可以了）
    如果 nums1[i] > nums2[j]， 说明 nums2[j]肯定不会重复
    如果 nums1[i] < nums2[j]， 说明 nums1[i]不会重复
 */



/*************************** Submit Part *****************************/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int size1, size2;
        int i, j;
        size1 = nums1.size();
        size2 = nums2.size();
        i = j = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int cnt = 0;
        while(i<size1 && j<size2){
            if(nums1[i]==nums2[j]){
                if(cnt==0){
                    ans.push_back(nums2[j]);
                    cnt++;
                }
                else if(ans[cnt-1]!=nums2[j]){
                    ans.push_back(nums2[j]);
                    cnt++;
                }
                i++, j++;
            }
            else if(nums1[i]>nums2[j]){
                j++;
            }
            else if(nums1[i]<nums2[j]){
                i++;
            }
        }

        return ans;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x,m,n;
    vector<int> vec1, vec2;
    cin >> m >> n;
    for(int i=0; i<m; ++i){
        cin >> x;
        vec1.push_back(x);
    }
    for(int i=0; i<n; ++i){
        cin >> x;
        vec2.push_back(x);
    }

    vector<int> ans;
    Solution solution;
    ans = solution.intersection(vec1, vec2);
    for(int i=0; i<ans.size(); ++i){
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}
