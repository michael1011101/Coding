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
 * Title: 77. Combinations
    Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

    For example,
    If n = 4 and k = 2, a solution is:

    [
      [2,4],
      [3,4],
      [2,3],
      [1,2],
      [1,3],
      [1,4],
    ]
 */

/** solution
    回溯
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<int> tmp(k,0);
        dfs(tmp, 1, 0, n, k);
        return ans;
    }
private:
    vector<vector<int> > ans;
    void dfs(vector<int> now, int pos, int cnt, int n, int k){
        if(cnt == k){
            ans.push_back(now);
            return;
        }
        for(int i=pos; i<=n; ++i){
            now[cnt] = i;
            dfs(now, i+1, cnt+1, n, k);
        }
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int n, k;
    cin >> n >> k;

    vector<vector<int> > ans;
    Solution solution;
    ans = solution.combine(n,k);
    for(vector<vector<int> >::iterator it = ans.begin(); it != ans.end(); ++it){
        vector<int> tmp = *it;
        for(vector<int>::iterator iit = tmp.begin(); iit != tmp.end(); ++iit){
            cout << *iit << ' ';
        }
        cout << endl;
    }
    return 0;
}
