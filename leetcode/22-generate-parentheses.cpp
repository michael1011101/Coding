#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

/**
 * Title: 22. Generate Parentheses
    Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

    For example, given n = 3, a solution set is:

    [
      "((()))",
      "(()())",
      "(())()",
      "()(())",
      "()()()"
    ]
 */

/** solution
    非递归式解答
    用队列BFS解答，注意()是现有左括号，再有右括号
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        queue<pair<string, pair<int, int> > > que;
        pair<string, pair<int,int> > model;
        pair<int, int> tmp;
        string str;
        int len, left, cnt;

        left = cnt = 0;
        len = 2*n;
        que.push(make_pair("", make_pair(left, cnt)));

        while(que.front().first.size() < len){
            model = que.front();
            que.pop();

            str = model.first;
            tmp = model.second;
            left = tmp.first;
            cnt = tmp.second;

            if(cnt > 0){
                if(left < n){
                    que.push(make_pair(str+'(', make_pair(left+1, cnt+1)));
                }
                que.push(make_pair(str+')', make_pair(left, cnt-1)));
            }
            else if(cnt == 0){
                que.push(make_pair(str+'(', make_pair(left+1, cnt+1)));
            }
        }

        while(!que.empty()){
            ans.push_back(que.front().first);
            que.pop();
        }
        return ans;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x;
    cin >> x;
    Solution solution;
    vector<string> ans = solution.generateParenthesis(x);
    int _size = ans.size();
    for(int i=0; i<_size; ++i){
        cout << ans[i] << endl;
    }
    return 0;
}
