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

void gao1(){
    int row, col;
    char ccol[MAXN];
    memset(ccol, '\0', sizeof(ccol));
    sscanf(str, "R%dC%d", &row, &col);

    int tmp;
    int i=0;

    //注意'Z' 和整除的现象
    while(col>0){
        tmp = col%26?col%26:26; //对于Z要注意
        if(col%26==0){          //对于整除的值要减一
            col--;
        }
        ccol[i++] = tmp-1 + 'A';
        if(col%26==0 && col/26==1) break;
        col /= 26;
    }
    reverse(ccol, ccol+i);      //取余逆序，才能获得col的编码值

    printf("%s%d\n", ccol, row);
}

void gao2(){
    int i;
    int row, col;
    int len = strlen(str);
    //获取col的值
    col=0;
    for(i=0; i<len; ++i){
        if(str[i]>='A'&&str[i]<='Z')
            col = col*26+(str[i]-'A'+1);
        else
            break;

    }
    //获取row的值
    row=0;
    for( ; i<len; ++i){
        row = row*10+(str[i]-'0');
    }

    printf("R%dC%d\n", row, col);
}

void READ(){
    int n;
    bool flag;
    scanf("%d", &n);
    while(n--){
        scanf("%s", str);

        //注意输入是R11，RC11...形式 
        int R = strchr(str, 'R')-str;
        int C = strchr(str, 'C')-str;
        flag = true;
        if(C<R||R!=0){
            flag = false;
        }
        else{
            if(str[R+1]>='A'&&str[R+1]<='Z')
                flag = false;
        }
        
        if(flag)
            gao1();
        else
            gao2();
    }
}

int main(){
    READ();
    return 0;
}