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
    将类型1和2分开，然后根据值排序
    计算各自的前缀和
    然后，对类型1 从0到size枚举，加入类型2的最大数量，然后判断是否是最大容量。
    最后记录需要的类型1和类型2的下标，重新排序输出。
*/

const int maxn = 1e5+10;
int n,v;
vector<pair<int,int> > v1, v2;
int sum1[maxn], sum2[maxn];

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.first > b.first;
}

void RUN(){
    sort(v1.begin(),v1.end(), cmp);
    sort(v2.begin(),v2.end(),cmp);

    int size1,size2;
    int i,j;
    size1 = v1.size();
    size2 = v2.size();
    sum1[0] = 0;
    for(i=1; i<=size1; ++i){
        sum1[i] = sum1[i-1]+v1[i-1].first;
    }
    sum2[0] = 0;
    for(i=1; i<=size2; ++i){
        sum2[i] = sum2[i-1]+v2[i-1].first;
    }

    int tmp;
    int imax,jmax,_max;
    _max = -1;
    for(i=0; i<=size1; ++i){
        tmp = v-i;
        if(tmp >= 0){
            tmp /= 2;
            tmp = min(tmp, size2);
            if(_max < sum1[i]+sum2[tmp]){
                _max = sum1[i]+sum2[tmp];
                imax = i;
                jmax = tmp;
            }
        }
    }
    printf("%d\n", _max);

    vector<int> ans;
    for(i=0; i<imax; ++i){
        ans.push_back(v1[i].second);
    }
    for(i=0; i<jmax; ++i){
        ans.push_back(v2[i].second);
    }
    sort(ans.begin(), ans.end());
    int _size = ans.size();
    for(i=0; i<_size; ++i){
        if(i) printf(" ");
        printf("%d", ans[i]);
    }
}

void READ(){
    scanf("%d%d", &n, &v);
    int i;
    int t,p;
    for(i=1; i<=n; ++i){
        scanf("%d%d", &t, &p);
        if(t==1)
            v1.push_back(make_pair(p,i));
        else
            v2.push_back(make_pair(p,i));
    }
}

int main(){
    READ();
    RUN();
    return 0;
}