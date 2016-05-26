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

const int INF=1e9;

/*
题目主要是要找出最后得分最高的那位
如果出现同分现象，就要看这几位中在过去谁先达到这个最高分(虽然之后可能还会跌下上升balabala的，就不用去多想了)
因此，我们要记录每轮的变化量，就可以回顾计算了
*/

struct NODE{
    char name[50];
    int score;
};

int N;
int cnt;
NODE people[1010];
NODE situation[1010];
vector<NODE> vec;


//寻找之前是否已经存在这个人，返回其下标
int _find(char name[]){
    int i;
    int index=cnt;
    for(i=0; i<cnt; ++i){
        if(strcmp(people[i].name, name)==0){
            index = i;
            break;
        }
    }
    return index;
}



void gao(){
    int i, j;
    int score;

    //找出最大的分数score
    score = people[0].score;
    for(i=1; i<cnt; ++i){
        if(people[i].score > score){
            score = people[i].score;
        }
    }

    //记录拥有该分数的人
    for(i=0; i<cnt; ++i){
        if(people[i].score == score)
            vec.push_back(people[i]);
    }

    //判断在过去这些人中，谁先到达score的分数
    int ians;
    bool flag = false;      //标记是否找到这个人，没找到是false
    int _size = vec.size();
    for(i=1; i<=N&&!flag; ++i){
        if(situation[i].score >= score){        //找到一个分数>score
            for(j=0; j<_size&&!flag; ++j){      //判断是否在这些人中
                if(strcmp(situation[i].name, vec[j].name)==0){
                    flag = true;                //找到此人
                    ians = j;
                }
            }
        }
    }
    printf("%s\n", vec[ians].name);
}



void READ(){
    char name[50];
    int score;
    cnt = 0;
    int now;
    scanf("%d", &N);
    for(int i=1; i<=N; ++i){
        scanf("%s%d", name, &score);
        now = _find(name);  
        if(now<cnt){
            people[now].score += score;
        }
        else{ //此时，now==cnt
            strcpy(people[now].name, name); 
            people[now].score = score;
            ++cnt;
        }

        //记录每一轮的变化的量
        strcpy(situation[i].name, name);
        situation[i].score = people[now].score;
    }
    gao();
}

int main(){
    READ();
    return 0;
}