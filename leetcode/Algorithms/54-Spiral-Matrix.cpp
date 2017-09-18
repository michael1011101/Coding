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
 * Title:54. Spiral Matrix
    Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

    For example,
    Given the following matrix:

    [
     [ 1, 2, 3 ],
     [ 4, 5, 6 ],
     [ 7, 8, 9 ]
    ]
    You should return [1,2,3,6,9,8,7,4,5].
 */

/** solution
    Ä£Äâ
 */


/*************************** Submit Part *****************************/
class Solution {
private:
    int tx[4]={0,1,0,-1};
    int ty[4]={1,0,-1,0};

    bool judge(int i, int j, int dir, int m, int n, vector<vector<bool> > visit){
        int x = i+tx[dir];
        int y = j+ty[dir];
        if(x>=0&&x<m&&y>=0&&y<n&&!visit[x][y]) return true;
        return false;
    }
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        int m = matrix.size();
        if(m==0) return vector<int>();

        int n = matrix[0].size();

        vector<int> ans;
        vector<vector<bool> > visit(m, vector<bool>(n, false));
        int i,j;
        int cnt;
        int direction;
        i = j = cnt = 0;
        direction = 0;

        ans.push_back(matrix[i][j]);
        visit[i][j] = true;
        cnt ++;
        while(cnt < m*n){
            while(judge(i,j,direction, m, n, visit)){
                i += tx[direction];
                j += ty[direction];
                ans.push_back(matrix[i][j]);
                visit[i][j] = true;
                cnt++;
            }
            direction = (direction+1)%4;
        }
        return ans;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    vector<vector<int> > matrix;
    int m,n;
    int x;
    cin >> m >> n;
    for(int i=0; i<m; ++i){
        vector<int> tmp;
        for(int j=0; j<n; ++j){
            cin >> x;
            tmp.push_back(x);
        }
        matrix.push_back(tmp);
    }

    Solution solution;
    vector<int> ans = solution.spiralOrder(matrix);
    for(vector<int>::iterator it=ans.begin(); it!=ans.end(); ++it){
        cout << *it << ' ';
    }
    return 0;
}
