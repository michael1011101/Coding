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
    纯粹的模拟上下左右。
    最大步数是上下差值和左右差值中的最大值，注意取绝对值。
*/
char st[5],ed[5];

void RUN(){
    int row, col;
    col = ed[0] - st[0];
    row = ed[1] - st[1];
    int Max = max(abs(col), abs(row));
    int i;
    printf("%d\n", Max);
    for(i=0; i<Max; ++i){
        if(col){
            if(col>0){
                printf("R");
                col--;
            }
            if(col<0){
                printf("L");
                col++;
            }
        }
        if(row){
            if(row>0){
                printf("U");
                row--;
            }
            if(row<0){
                printf("D");
                row++;
            }
        }
        printf("\n");
    }
}

void READ(){
    gets(st);
    gets(ed);
}

int main(){
    READ();
    RUN();
    return 0;
}