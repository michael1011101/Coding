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
 * Title: 231. Power of Two
    Given an integer, write a function to determine if it is a power of two.
 */

/** solution
    λ���� 2�ı��� ˵��ֻ��һλ��1
    ע�⣺С�ڵ���0�Ķ�����false
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int cnt = 0;
        if(n<=0) return false;
        while(n){
            cnt++;
            if(cnt > 1) return false;
            n &= (n-1);
        }
        return true;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x;
    cin >> x;
    Solution solution;
    cout << solution.isPowerOfTwo(x) << endl;
    return 0;
}
