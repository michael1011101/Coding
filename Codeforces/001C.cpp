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

#define PI acos(-1.0)
#define eps (1e-4)

struct NODE{
    double x,y;
};
NODE pillar[3];

//两点间距离
double dis(NODE a, NODE b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

//海伦公式
double Heron(double a, double b, double c){
    double p = (a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

/*
    用途：求外接圆半径

    实力分析：
    正弦定理：a = 2*R*sin(A) ············(1)
    面积公式: S = b*c*sin(A)/2 ··········(2)
    (1)式两边同乘以b*c:
    a*b*c = 2*b*c*R*sin(A) ··············(3)
    由(2)式知:
    b*c*sin(A) = 2*S ····················(4)
    将(4)式带入(3):
    a*b*c = 4*S*R
    因此:
    S = a*b*c/(4*S);
*/
double Radius(double a, double b, double c){
    double S = Heron(a,b,c);    //首先用海伦公式，求面积
    return a*b*c/(4*S);         
}

/*
    用途：double类型辗转相除求公约数

    不知道谁想到的黑科技，反正我第一次用TAT
    还用到fmod 貌似和取模差不多吧
*/
double fgcd(double a, double b)
{
    if(fabs(b-0)<=eps) return a;
    if(fabs(a-0)<=eps) return b;
    return fgcd(b,fmod(a,b));
}

void gao(){
    double a,b,c;
    double p,S,R,A,B,C;
    double ansS;
    a = dis(pillar[0], pillar[1]);
    b = dis(pillar[1], pillar[2]);
    c = dis(pillar[2], pillar[0]);

    /*
        好吧,稍微说下：
        之前在这里用的是先求S，然后求R，用了两个函数
        S = Heron(a,b,c)
        R = Radius(S,a,b,c)
        貌似这样传值可能会出现啥问题，导致fgcd这种黑科技用不了，会TLE
        然后就用了现在的方法，不要问我原因，我也很confused T.T
        所以如果谁知道请告诉我 thx
    */
    //求外接圆半径
    R = Radius(a,b,c);

    //求各个圆心角的大小
    A = acos(1- a*a / (2*R*R));
    B = acos(1- b*b / (2*R*R));
    C = 2*PI-A-B;                   //千万不要用C=acos(1-c*c/(2*R*R)), double类型运算有精度误差，不能保证A+B+C=2*PI

    //求圆心角的公约数
    //黑科技，看CF第47组数据，直接拿下来在电脑上跑会直接TLE了，但是提交还是能过的，很是无奈╮(╯▽╰)╭
    double angle_fgcd = fgcd(A, fgcd(B, C));

    /*
        最后别忘了求多边形面积
        多边形个数：num = 2*PI/angle_fgcd
        单个小三角形面积 s = R*R*sin(angle_fgcd)/2
        ans = num*s =(消去2)= PI/angle_fgcd*R*R*sin(angle_fgcd)
    */
    ansS = PI/angle_fgcd*R*R*sin(angle_fgcd);
    printf("%.8lf\n", ansS);
}

void READ(){
    int i;
    for(i=0; i<3; ++i){
        scanf("%lf%lf", &pillar[i].x, &pillar[i].y);
    }
    gao();
}

int main(){
    READ();
    return 0;
}
