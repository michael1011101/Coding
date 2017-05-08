#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Title: 278. First Bad Version
    You are a product manager and currently leading a team to develop a new product.
    Unfortunately, the latest version of your product fails the quality check.
    Since each version is developed based on the previous version,
    all the versions after a bad version are also bad.

    Suppose you have n versions [1, 2, ..., n]
    and you want to find out the first bad one,
    which causes all the following ones to be bad.

    You are given an API bool isBadVersion(version)
    which will return whether version is bad.
    Implement a function to find the first bad version.
    You should minimize the number of calls to the API.
 */

/** solution
    从第一个坏的版本之后都是坏的，
    所以就是找到坏版本范围的最左端
    注意int加法时候会溢出
 */


/*************************** Submit Part *****************************/
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long left = 1;
        long long right = n;
        while(left <= right){
            int mid = (left+right)/2;
            if(isBadVersion(mid)){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return left;
    }
};
/*************************** Submit Part *****************************/

int target;
bool isBadVersion(int version){
    if(version>=target) return true;
    return false;
}

int main()
{
    int x;
    cin >> x;
    cin >> target;
    Solution solution;
    cout << solution.firstBadVersion(x) << endl;
    return 0;
}
