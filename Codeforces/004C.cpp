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
    仅仅判断名字是否第一次出现，如果是的输出'OK'
    否则之后的数字依次从1开始向后加
    所以用map<string,int>来维护
*/
int N;
map<string, int> mp;

void READ(){
    cin >> N;
    int i;
    string name;
    int num;
    for(i=0; i<N; ++i){
        cin >> name;
        //不是第一次出现
        if(mp.find(name) != mp.end()){
            num = mp[name]++;
            cout << name << num << endl;
        }
        //第一次出现
        else{
            cout << "OK" << endl;
            mp[name] = 1;
        }
    }
}

int main(){
    READ();
    return 0;
}