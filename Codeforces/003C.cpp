
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
    模拟井字棋赢棋规则
    横竖对角线满足3个就算胜利
    'X'先走 '0'后走
    所以'X'的个数-'0'的个数<=1
*/

char grid[5][5];

bool judge(char c){
    int i,j;
    bool flag = false;
    for(i=0; i<3; ++i){
        if(grid[i][0]==c&&grid[i][0]==grid[i][1]&&grid[i][1]==grid[i][2])
            flag = true;
        if(grid[0][i]==c&&grid[0][i]==grid[1][i]&&grid[1][i]==grid[2][i])
            flag = true;
    }
    if(grid[0][0]==c&&grid[0][0]==grid[1][1]&&grid[1][1]==grid[2][2])
        flag = true;
    if(grid[2][0]==c&&grid[2][0]==grid[1][1]&&grid[1][1]==grid[0][2])
        flag = true;

    return flag;
}

void RUN(){
    bool firstWin, secondWin;
    firstWin = judge('X');
    secondWin = judge('0');
    int i,j;
    int first,second;
    first = second = 0;
    for(i=0; i<3; ++i){
        for(j=0; j<3; ++j){
            if(grid[i][j]=='X')
                first++;
            if(grid[i][j]=='0')
                second++;
        }
    }
    if(firstWin&&secondWin){    //两者都应肯定是错误的
        printf("illegal\n");
    }
    else{
        if(first-second==0){    //后者下完
            if(firstWin) printf("illegal\n");   //后者下完是，前者赢，那么后者肯定不可以下，因此是错误
            else if(secondWin) printf("the second player won\n");   //后者下完，后者赢 成立
            else printf("first\n");             //后者下完，都没赢，那么前者下
        }
        else if(first-second==1){   //前者下完
            if(firstWin) printf("the first player won");    //前者赢，成立
            else if(secondWin) printf("illegal\n");         //后者赢，不成立
            else if(first+second==9) printf("draw\n");      //如果都没赢，并且下满所有格子，重新下
            else printf("second\n");                        //否则，后者下
        }
        else{
            printf("illegal\n");
        }
    }

}

void READ(){
    int i;
    for(i=0; i<3; ++i){
        gets(grid[i]);
    }
}

int main(){
    READ();
    RUN();
    return 0;
}