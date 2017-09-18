#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

/**
 * Title:  633. Sum of Square Numbers
    Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.

    Example 1:
    Input: 5
    Output: True
    Explanation: 1 * 1 + 2 * 2 = 5
    Example 2:
    Input: 3
    Output: False
 */

/** solution
    ����ͷβ�ڱ���������ָ���ֵ���빫ʽ�������c����ô������һ�������cС����ôС����һ��
    �����ȣ�����true��
    ���û�ҵ�������false��
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    bool judgeSquareSum(int c) {
        int right, left;
        left = 0;
        right = sqrt(c);
        int tmp;
        while(left <= right){
            tmp = left*left + right*right;
            if(tmp < c){
                left++;
            }
            else if(tmp > c){
                right--;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
/*************************** Submit Part *****************************/

int main()
{

    return 0;
}

