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

/*
    括号匹配问题
        ?可以变为'('或者')'，但是需要消耗相应的cost
    首先，我们将所有的 '?' 看做是 ')'
    用优先队列来存储cost的差值和坐标的pair
    num来表示括号匹配的状态
    如果碰到'(',num+1; 否则num-1
    当num<0时候，判断队列中是否有'?' 如果有，就输出最大的差值位，将其改为'(' 并且这里注意num+2
    最后要判断num是否等于0(即括号位是否平衡)
    注意：用long long来定义cost， int肯定是超界的
*/

#define LL long long
const int maxn = 5e4+10;
char str[maxn];
priority_queue<pair<LL,int> > que;

void RUN(){
    int len = strlen(str);
    LL cost = 0;
    int i;
    LL a,b;
    int num = 0;
    bool flag = true;
    for(i=0; i<len; ++i){
        //如果碰到'(',num+1; 否则num-1
        num = num + (str[i]=='(') - (str[i]!='(');
        
        if(str[i]=='?'){
            scanf("%I64d%I64d", &a, &b);
            cost += b;
            str[i] = ')';           //修改 '?' 为 ')'
            que.push(make_pair(b-a, i));
        }

        if(num<0){
            if(que.empty()) break;
            pair<int,int> x = que.top();
            que.pop();
            cost -= x.first;        //减去对应的差值
            str[x.second] = '(';    //修改为'('
            num += 2;
        }
    }

    if(num != 0)    puts("-1");
    else{
        printf("%I64d\n%s\n", cost, str);
    }
}

void READ(){
    gets(str);
}

int main(){
    READ();
    RUN();
    return 0;
}