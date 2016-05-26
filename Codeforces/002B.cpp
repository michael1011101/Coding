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

const int INF = 1e8;
const int maxn = 1010;
/*
从左上角到右下角，经历数字的乘积，尾部最少的0的个数，就是最佳路径
末尾的0是由2、5产生的，N = (2^k)*(5^m)*(other primes)，N末尾0的个数 = min(k,m)
所以，我们要找最小的k和最小的m，那么min(k,m)走的就是最佳路径了
以dp计算，一个使走的数含因子2的数目最少(k)，一个使含因子5的数目少(m)
理解：
    使含因子2个数最少的路径中含因子5的个数: M >= m
    同样，使含因子5个数最少的路径中含因子2的个数: K >= k
那么min(k,m)就是末尾0的个数

注意点！！！：
    矩阵中存在0，那么最后的乘积是0，末尾个数就是1。
    因此，如果矩阵中有0,最后计算的min(k,m) 如果大于1，那么走的路径就是穿过0的路径

dp[i][j][k]: 走过(i,j)时，k=0:因子2的个数；k=1:因子5的个数
num[i][j][k]：矩阵(i,j)处，k=0:因子2的个数；k=1:因子5的个数
dir[i][j][k]：走到(i,j)点的前一步的走法，k=0:因子2的走法；k=1:因子5的走法
*/

int dp[maxn][maxn][2];
char dir[maxn][maxn][2];
int num[maxn][maxn][2];
int N;
int icnt;
bool have_zero;


/*
//递归输出
void print(int x, int y, int k){
    if(x==0&&y==0)  return;
    if(dir[x][y][k]=='D'){
        print(x-1,y,k);
    }
    else if(dir[x][y][k]=='R'){
        print(x,y-1,k);
    }
    printf("%c", dir[x][y][k]);
}
*/

//防止递归堆栈层数过多，所以记录之后反转输出
void print(int x, int y, int k){
    vector<char> ans;
    while(!(x==0&&y==0)){
        ans.push_back(dir[x][y][k]);
        if(dir[x][y][k]=='D') x--;
        else if(dir[x][y][k]=='R') y--;
    }
    reverse(ans.begin(), ans.end());
    int _size = ans.size();
    for(int i=0; i<_size; ++i){
        printf("%c", ans[i]);
    }
}

void gao(){
    int i,j,k;

    //(0,0)点必过，所以直接记录
    dp[0][0][0] = num[0][0][0];
    dp[0][0][1] = num[0][0][1];
    for(i=0; i<N; ++i){
        for(j=0; j<N; ++j){
            if(i){      //如果不是第一行，那么就可以从上一行向下走
                //因子2的计算
                if(dp[i][j][0] > dp[i-1][j][0]+num[i][j][0]){
                    dp[i][j][0] = dp[i-1][j][0]+num[i][j][0];
                    dir[i][j][0] = 'D';
                }
                //因子5的计算
                if(dp[i][j][1] > dp[i-1][j][1]+num[i][j][1]){
                    dp[i][j][1] = dp[i-1][j][1]+num[i][j][1];
                    dir[i][j][1] = 'D';
                }
            }
            if(j){      //如果不是第一列，那么可以从左向右走
                if(dp[i][j][0] > dp[i][j-1][0]+num[i][j][0]){
                    dp[i][j][0] = dp[i][j-1][0]+num[i][j][0];
                    dir[i][j][0] = 'R';
                }
                if(dp[i][j][1] > dp[i][j-1][1]+num[i][j][1]){
                    dp[i][j][1] = dp[i][j-1][1]+num[i][j][1];
                    dir[i][j][1] = 'R';
                }
            }
        }
    }

    //最后判断用因子2还是因子5的方法
    k = dp[N-1][N-1][0] < dp[N-1][N-1][1] ? 0: 1;

    //如果有0，并且末尾0的个数大于等于1，那么直接输出穿过0的路径
    if(have_zero && dp[N-1][N-1][k]>0){
        printf("1\n");
        //穿过0的路径，直接D到0所在层，然后一直向右，最后D到出口
        for(i=0; i<icnt; ++i){
            printf("D");
        }
        for(i=1; i<N; ++i){
            printf("R");
        }
        for(i=icnt+1; i<N; ++i){
            printf("D");
        }
        printf("\n");
    }
    else{
        printf("%d\n", dp[N-1][N-1][k]);
        print(N-1, N-1, k);
        printf("\n");
    }
}

void READ(){
    scanf("%d", &N);
    int i,j;
    int n;
    have_zero = false;
    memset(num, 0, sizeof(num));
    for(i=0; i<N; ++i){
        for(j=0; j<N; ++j){
            scanf("%d", &n);
            if(n == 0){             //如果矩阵中有0，标志位true，记录所在层数，方便之后输出穿过0的路径
                have_zero = true;
                icnt = i;
            }
            else{                   //如果不是0，那么计算一下因子中2和5的个数
                while(n%2==0){
                    num[i][j][0]++;
                    n /= 2;
                }
                while(n%5==0){
                    num[i][j][1]++;
                    n /= 5;
                }
            }

            //初始化每个点(i,j)dp值无穷大（因为之后要dp求最小值）
            dp[i][j][0] = INF;
            dp[i][j][1] = INF;
        }
    }
    gao();
}

int main(){
    READ();
    return 0;
}
