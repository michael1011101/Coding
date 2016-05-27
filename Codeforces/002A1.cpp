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
    之前用结构体写的，所以这次用STL来简洁的写一次
*/
const int INF = 1e9;
map<string, int> game;                  //表示每个人的比赛得分
vector< pair<string, int> > process;    //记录比赛过程的，得分变化
int N;

void gao(){
    int i;
    int _max = -INF;
    //找到最后最高的分数
    map<string, int>::iterator it;
    for(it=game.begin(); it!=game.end(); ++it){
        if(_max < it->second)
            _max = it->second;
    }

    //在过程中，找到最后得分最高并且率先得分超过_max的人
    int score;
    string name;
    for(i=0; i<N; ++i){
        name = process[i].first;
        score = process[i].second;
        if(score>=_max&&game[name]==_max){
            break;
        }
    }

    cout << name << endl;
}

void READ(){
    int i;
    cin >> N;
    string name;
    int score;
    for(i=0; i<N; ++i){
        cin >> name >> score;
        game[name] += score;
        process.push_back(make_pair(name,game[name]));
    }
    gao();
}

int main(){
    READ();
    return 0;
}
