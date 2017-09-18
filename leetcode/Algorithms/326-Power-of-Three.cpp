#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <unordered_set>
#include <algorithm>
using namespace std;

/**
 * Title:326. Power of Three
    Given an integer, write a function to determine if it is a power of three.

    Follow up:
    Could you do it without using any loop / recursion?
 */

/** solution
    log(3,n)�Ƿ�������
    ���׹�ʽ
    log(3,n) = log(10,n) / log(10,3)
    ������e����2Ϊ��������Ϊ����־�������
    C++�ж�����: res-int(res) == 0  �����黹��ʹ�þ��ȣ��ж��Ƿ���ȣ�
 */



/*************************** Submit Part *****************************/
class Solution {
public:
    bool isPowerOfThree(int n) {
        double res = log10(n) / log10(3);
        return (res - int(res)) == 0;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    int x;
    while(cin >> x){
        Solution solution;
        cout << solution.isPowerOfThree(x) << endl;
    }
    return 0;
}
