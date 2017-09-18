#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Title: 374. Guess Number Higher or Lower
    We are playing the Guess Game. The game is as follows:

    I pick a number from 1 to n. You have to guess which number I picked.

    Every time you guess wrong, I'll tell you whether the number is higher or lower.

    You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

    -1 : My number is lower
     1 : My number is higher
     0 : Congrats! You got it!
 */

/** solution

 */


/*************************** Submit Part *****************************/
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long long left = 1;
        long long right = n;
        while(left <= right){
            int mid = (left+right)/2;
            if(guess(mid)==0) return mid;
            else if(guess(mid) < 0){
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

int pick;
int guess(int num){
    if(pick < num) return -1;
    if(pick > num) return 1;
    return 0;
}

int main()
{
    int x;
    cin >> x;
    cin >> pick;
    Solution solution;
    cout << solution.guessNumber(x) << endl;
    return 0;
}
