#include <iostream>
#include <vector>
using namespace std;

/**
 * Title: 414. Third Maximum Number

    Given a non-empty array of integers, return the third maximum number in this array.
    If it does not exist, return the maximum number. The time complexity must be in O(n).

    Example 1:
    Input: [3, 2, 1]

    Output: 1

    Explanation: The third maximum is 1.
    Example 2:
    Input: [1, 2]

    Output: 2

    Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
    Example 3:
    Input: [2, 2, 3, 1]

    Output: 1

    Explanation: Note that the third maximum here means the third maximum distinct number.
    Both numbers with value 2 are both considered as second maximum.
 */

/** solution
    初步想到一个simple的模拟方法，构建一个3大小的Max数组
    遍历给定的数字，如果Max数组没有加满或者最新的数字比Max中最小的数字大，并且它在Max数组中没有存在，则添加进去。
 */


/***************************提交部分*****************************/
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int Max[3];
        int number = 0;
        int _size = nums.size();
        int imin;
        int x;

        for(int i=0; i<_size; ++i){
            imin = findMinIndexInArray(Max, number);

            x = nums[i];
            if(number == 0 || imin == -1){
                insertInArray(Max, number, x);
            }
            else if(number < 3 || Max[imin] < x){
                if(!findInArray(Max, number, x)){
                    insertInArray(Max, number, x);
                }
            }
        }

        if(number == 3){
            imin = findMinIndexInArray(Max, number);
            return Max[imin];
        }
        else{
            int imax = findMaxIndexInArray(Max, number);
            return Max[imax];
        }
    }
private:
    bool findInArray(int num[], int _size, int x){
        for(int i=0; i<_size; ++i){
            if(num[i] == x) return true;
        }
        return false;
    }

    int findMinIndexInArray(int num[], int _size){
        int imin = -1;
        for(int i=0; i<_size; ++i){
            if(imin == -1 || num[imin] > num[i]){
                imin = i;
            }
        }
        return imin;
    }

    int findMaxIndexInArray(int num[], int _size){
        int imax = -1;
        for(int i=0; i<_size; ++i){
            if(imax == -1 || num[imax] < num[i]){
                imax = i;
            }
        }
        return imax;
    }

    void insertInArray(int num[], int &_size, int x){
        if(_size != 3){
            num[_size] = x;
            _size++;
        }
        else{
            int imin = findMinIndexInArray(num, _size);
            num[imin] = x;
        }

    }
};
/***************************提交部分*****************************/

int main()
{
    vector<int> n1, n2;
    int x;
    while(cin >> x){
        n1.push_back(x);
    }
    Solution solution;
    cout << solution.thirdMax(n1);
     return 0;
}
