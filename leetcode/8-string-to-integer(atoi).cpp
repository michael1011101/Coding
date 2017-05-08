#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

/**
 * Title: 8. String to Integer (atoi)

    Implement atoi to convert a string to an integer.
 */

/** solution
    首先去除前置空格
    确定正负号
    如果出现非数字，直接跳出，返回已经计算的数字
    在计算的时候，因为字符串可以超过long long的长度，所以溢出int的范围就直接跳出
    最后如果小于INT_MIN，返回INT_MIN；大于INT_MAX，返回INT_MAX
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    int myAtoi(string str) {
        long long ans = 0;
        int _size = str.size();
        int sign = 1;
        int i = 0;

        for(;str[i]==' ';++i);

        if(str[i] == '-'){
            sign = -1;
            ++i;
        }
        else if (str[i] == '+'){
            sign = 1;
            ++i;
        }

        for(; i<_size; ++i){
            if(str[i]>='0' && str[i]<='9'){
                ans = ans * 10 + str[i] - '0';
                if(ans > INT_MAX) break;
            }
            else{
                break;
            }
        }
        ans *= sign;
        if(ans < INT_MIN) return INT_MIN;
        if(ans > INT_MAX) return INT_MAX;
        return ans;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    string s;
    while(getline(cin, s)){  //input string with blank
        Solution solution;
        cout << solution.myAtoi(s) << endl;
    }
    return 0;
}
