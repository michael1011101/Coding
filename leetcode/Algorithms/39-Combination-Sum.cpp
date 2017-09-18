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
 * Title: 39. Combination Sum
    Given a set of candidate numbers (C) (without duplicates) and a target number (T),
    find all unique combinations in C where the candidate numbers sums to T.

    The same repeated number may be chosen from C unlimited number of times.

    Note:
    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.
    For example, given candidate set [2, 3, 6, 7] and target 7,
    A solution set is:
    [
      [7],
      [2, 2, 3]
    ]
 */

/** solution
    每次数字可以用多次
    注意去重
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        stack<int> tmp;
        dfs(candidates, tmp, 0, target);
        return ans;
    }
private:
    vector<vector<int> > ans;
    set<vector<int> > dup;
    void dfs(vector<int> num, stack<int> now, int sum, int target){
        if(sum == target){
            vector<int> tmp;
            while(!now.empty()){
                tmp.push_back(now.top());
                now.pop();
            }
            sort(tmp.begin(), tmp.end());
            if(dup.find(tmp) == dup.end()){
                ans.push_back(tmp);
                dup.insert(tmp);
            }
            return;
        }
        else if(sum > target) return;

        int _size = num.size();
        for(int i=0; i<_size; ++i){
            sum += num[i];
            now.push(num[i]);
            dfs(num, now, sum, target);
            now.pop();
            sum -= num[i];
        }
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x;
    int target;
    vector<int> num;
    cin >> target;
    while(cin >> x) num.push_back(x);

    vector<vector<int> > ans;
    Solution solution;
    ans = solution.combinationSum(num, target);
    for(int i=0; i<ans.size(); ++i){
        for(int j=0; j<ans[i].size(); ++j){
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
