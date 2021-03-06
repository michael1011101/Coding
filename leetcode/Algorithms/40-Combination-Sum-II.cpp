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
 * Title: 40. Combination Sum II
    Given a collection of candidate numbers (C) and a target number (T),
    find all unique combinations in C where the candidate numbers sums to T.

    Each number in C may only be used once in the combination.

    Note:
    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.
    For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
    A solution set is:
    [
      [1, 7],
      [1, 2, 5],
      [2, 6],
      [1, 1, 6]
    ]
 */

/** solution
    每次数字只能用一次，所以需要使用访问标记位
    同时为了防止TLE 对于访问过的点之前的点，我们也不在访问
    注意去重
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        stack<int> tmp;
        vector<bool> flag(candidates.size(), false);
        dfs(candidates, flag, tmp, 0, 0, target);
        return ans;
    }
private:
    vector<vector<int> > ans;
    set<vector<int> > dup;
    void dfs(vector<int> num, vector<bool> flag, stack<int> now, int index, int sum, int target){
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
        for(int i=index; i<_size; ++i){
            if(!flag[i]){
                sum += num[i];
                now.push(num[i]);
                flag[i] = true;
                dfs(num, flag, now, i+1, sum, target);
                flag[i] = false;
                now.pop();
                sum -= num[i];
            }
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
    ans = solution.combinationSum2(num, target);
    for(int i=0; i<ans.size(); ++i){
        for(int j=0; j<ans[i].size(); ++j){
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
