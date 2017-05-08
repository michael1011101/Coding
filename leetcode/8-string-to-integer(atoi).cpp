#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

/**
 * Title: 8. String to Integer (atoi)

    Implement atoi to convert a string to an integer.
 */

/** solution
    ����ȥ��ǰ�ÿո�
    ȷ��������
    ������ַ����֣�ֱ�������������Ѿ����������
    �ڼ����ʱ����Ϊ�ַ������Գ���long long�ĳ��ȣ��������int�ķ�Χ��ֱ������
    ������С��INT_MIN������INT_MIN������INT_MAX������INT_MAX
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
