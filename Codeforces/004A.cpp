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
	希望数字可以分为两个偶数
	因此一定是大于2的偶数 YES
*/

void READ(){
    int n;
    scanf("%d", &n);
    if(n>2&&n%2==0) printf("YES");
    else    printf("NO");
}

int main(){
    READ();
    return 0;
}