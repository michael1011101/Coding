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
    主要意思在002B中已经讲过了，这里稍微说一下
    就是算走过的数中因子含2和5最少，那么我们就计算因子2的路线一次，因子5的路线一次，最后比较一下，谁小走谁。
    另外要注意数字0的出现，会使末尾0的个数为1。因此，要上面的路线值作比较，如果小，输出穿过0的路径，否则输出上面的路径。
    本题为了输出方便，可以反过来想，从右下角向左上角走
    
dp[i][j][k]: 走过(i,j)时，k=0:因子2的个数；k=1:因子5的个数
num[i][j][k]：矩阵(i,j)处，k=0:因子2的个数；k=1:因子5的个数
dir[i][j][k]：在(，k=0:因子2的走法；k=1:因子5的走法
*/
const int INF = 1e8;
const int maxn = 1010;
int N;
int dp[maxn][maxn][2];
char dir[maxn][maxn][2];
int num[maxn][maxn][2];
bool have_zero;
int izero;

void RUN(){
    int i,j,k;
    dp[N][N][0] = num[N][N][0];
    dp[N][N][1] = num[N][N][1];
    for(i=N; i>0; i--){
        for(j=N; j>0; j--){
            if(i!=N){
                if(dp[i][j][0] > dp[i+1][j][0]+num[i][j][0]){
                    dp[i][j][0] = dp[i+1][j][0]+num[i][j][0];
                    dir[i][j][0] = 'D';
                }
                if(dp[i][j][1] > dp[i+1][j][1]+num[i][j][1]){
                    dp[i][j][1] = dp[i+1][j][1]+num[i][j][1];
                    dir[i][j][1] = 'D';
                }
            }
            if(j!=N){
                if(dp[i][j][0] > dp[i][j+1][0]+num[i][j][0]){
                    dp[i][j][0] = dp[i][j+1][0]+num[i][j][0];
                    dir[i][j][0] = 'R';
                }
                if(dp[i][j][1] > dp[i][j+1][1]+num[i][j][1]){
                    dp[i][j][1] = dp[i][j+1][1]+num[i][j][1];
                    dir[i][j][1] = 'R';
                }
            }
        }
    }

    k = dp[1][1][0] < dp[1][1][1] ?0:1;
    if(have_zero&&dp[1][1][k]>0){
        printf("1\n");
        for(i=1; i<izero; ++i){
            printf("D");
        }
        for(i=1; i<N; ++i){
            printf("R");
        }
        for(i=izero; i<N; ++i){
            printf("D");
        }
        printf("\n");
    }
    else{
        printf("%d\n", dp[1][1][k]);
        //从左上到右下，正向输出路线
        int x,y;
        x=y=1;
        while(!(x==N&&y==N)){
            printf("%c", dir[x][y][k]);
            if(dir[x][y][k]=='D') x++;
            else if(dir[x][y][k]=='R') y++;
        }
        printf("\n");
    }
}

void READ(){
    int i,j;
    int n;
    have_zero = false;
    scanf("%d", &N);
    memset(num,0,sizeof(num));
    for(i=1; i<=N; ++i){
        for(j=1; j<=N; ++j){
            scanf("%d", &n);
            if(n==0){
                have_zero=true;
                izero = i;
            }
            else{
                while(n%2==0) ++num[i][j][0], n/=2;
                while(n%5==0) ++num[i][j][1], n/=5;
            }
            dp[i][j][0] = INF;
            dp[i][j][1] = INF;
        }
    }
}

int main(){
    READ();
    RUN();
    return 0;
}
