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
    题目大意是，按照每天的时间安排范围，是否最后可以等于sumTime
    因此我们需要计算上下限，如果sumTime在这个闭区间范围里，那么肯定是可以完成的
    所以之后我们用贪心的方法，依次每天减到下限，直到时间相等
*/

int d, sumTime;
int minTime[35], maxTime[35];
int _min, _max;

void RUN(){
    if(sumTime<_min||sumTime>_max){
        printf("NO");
    }
    else{
        printf("YES\n");
        int i;
        if(sumTime==_min){
            for(i=0; i<d; ++i){
                if(i)   printf(" ");
                printf("%d", minTime[i]);
            }
        }
        else{
            int left = _max - sumTime;
            int tmp;
            //当left>0时，需要每天减去一点儿时间
            for(i=0; i<d&&left>0; ++i){
                tmp = maxTime[i] - minTime[i];

                //如果left大于差值，那么今天减为下限，否则减去left的值，就是今天的学习时间
                if(left >= tmp) maxTime[i] -= tmp;
                else maxTime[i] -= left;
                left -= tmp;
            }
            for(i=0; i<d; ++i){
                if(i) printf(" ");
                printf("%d", maxTime[i]);
            }
        }
    }
}

void READ(){
    scanf("%d%d", &d, &sumTime);
    int i;
    _min = _max = 0;
    for(i=0; i<d; ++i){
        scanf("%d%d", &minTime[i], &maxTime[i]);
        _min += minTime[i];
        _max += maxTime[i];
    }
}

int main(){
    READ();
    RUN();
    return 0;
}