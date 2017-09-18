#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Title:455. Assign Cookies
    Assume you are an awesome parent and want to give your children some cookies.
    But, you should give each child at most one cookie.
    Each child i has a greed factor gi,
    which is the minimum size of a cookie that the child will be content with;
    and each cookie j has a size sj. If sj >= gi, we can assign the cookie j to the child i,
    and the child i will be content.
    Your goal is to maximize the number of your content children and output the maximum number.

    Note:
    You may assume the greed factor is always positive.
    You cannot assign more than one cookie to one child.

    Example 1:
    Input: [1,2,3], [1,1]

    Output: 1

    Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3.
    And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
    You need to output 1.

    Example 2:
    Input: [1,2], [1,2,3]

    Output: 2

    Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2.
    You have 3 cookies and their sizes are big enough to gratify all of the children,
    You need to output 2.
 */

/** solution
    贪心，首先对g,s排序
    然后，s从小到大选择出一个数s[j]满足g[i]，i和j同时向后移，
    否则，j向后移动
 */



/*************************** Submit Part *****************************/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cnt = 0;
        int i,j;
        int sizeg, sizes;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        sizeg = g.size();
        sizes = s.size();

        i = j = 0;
        while(i<sizeg && j<sizes){
            if(g[i] <= s[j]){
                cnt++;
                i++;
            }
            j++;
        }
        return cnt;
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

    Solution solution;
    cout << solution.findContentChildren(vec1, vec2) << endl;
    return 0;
}
