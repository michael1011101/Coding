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

void READ(){
    LL m,n,a;
    while(cin >> n >> m >> a){
    	//对长、宽除以a之后，向上取余，求乘积
        LL ans = (LL)ceil(1.0*n/a) * (LL)ceil(1.0*m/a);
        cout << ans << endl;
    }
}

int main(){
    READ();
    return 0;
}