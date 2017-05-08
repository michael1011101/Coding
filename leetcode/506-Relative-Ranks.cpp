#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Title:506. Relative Ranks
    Given scores of N athletes, find their relative ranks and the people with the top three highest scores,
    who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

    Example 1:
    Input: [5, 4, 3, 2, 1]
    Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
    Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal".
    For the left two athletes, you just need to output their relative ranks according to their scores.

    Note:
    N is a positive integer and won't exceed 10,000.
    All the scores of athletes are guaranteed to be unique.
 */

/** solution
    注意排名需要以字符串形式返回
 */



/*************************** Submit Part *****************************/
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> ans;
        int _size = nums.size();
        int cnt;
        for(int i=0; i<_size; ++i){
            cnt = 0;
            for(int j=0; j<_size; ++j){
                if(nums[i] < nums[j]){
                    cnt++;
                }
            }
            ans.push_back(ranks(cnt));
        }

        return ans;
    }
private:
    string ranks(int n){
        string s;
        if(n==0) s = "Gold Medal";
        else if(n==1) s = "Silver Medal";
        else if(n==2) s = "Bronze Medal";
        else {
            n++;
            while(n){
                s += n%10+'0';
                n /= 10;
            }
            reverse(s.begin(), s.end());
        }
        return s;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x;
    vector<int> nums;
    while(cin >> x){
        nums.push_back(x);
    }
    Solution solution;
    vector<string> ans = solution.findRelativeRanks(nums);
    for(int i=0; i<ans.size(); ++i){
        cout << ans[i] << ' ';
    }
    return 0;
}
