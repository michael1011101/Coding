#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
using namespace std;

#define LL long long

const int MAXN = 1000010;
char str[MAXN];
int row, col;
char ccol[MAXN];

void gao1(){
    memset(ccol, '\0', sizeof(ccol));
    int tmp;
    int i=0;

    /*
        实力分(zhuang)析(bi):
        由于它的值是从'A'-'Z'排列，我们可以当做是1-26。
        但是对26取模后会出现1,2,3……25,0  这样就得对整除做出特殊判断
        因此，我们可以将值n-1，就真正成为了26进制(A-Z：0-25)，那么取模也不会出现问题了
        最后取余逆序，不要忘了
    */
    while(col>0){
        col--;
        tmp = col%26;
        ccol[i++] = tmp + 'A';
        col /= 26;
    }

    reverse(ccol, ccol+i);
    printf("%s%d\n", ccol, row);
}

void gao2(){
    int i;
    //不得不承认这些黑科技的可怕，就是那么easy
    //分离出col的编码值和row
    sscanf(str, "%[A-Z]%d", ccol, &row);
    int len = strlen(ccol);
    col = 0;
    for(i=0; i<len; ++i){
        col = col*26+(ccol[i]-'A'+1);
    }
    printf("R%dC%d\n", row, col);
}

void READ(){
    int n;
    bool flag;
    scanf("%d", &n);
    while(n--){
        scanf("%s", str);

        //用sscanf的返回值做判断更快更方便
        if(sscanf(str, "R%dC%d", &row, &col)==2)
            gao1();
        else
            gao2();
    }
}

int main(){
    READ();
    return 0;
}
