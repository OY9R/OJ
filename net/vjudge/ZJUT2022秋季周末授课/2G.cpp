#include<bits/stdc++.h>
using namespace std;
struct pe {
    string name , work;
    int bg , level , id , works;
} p[120];
int n;
int cmp(pe a , pe b) {
    if(a.bg == b.bg) return a.id < b.id;
    return a.bg > b.bg;
}
int cmp1(pe a , pe b) {
    if(a.works == b.works) {
        if(a.level == b.level) return a.id < b.id;
        return a.level > b.level;
    }
    return a.works < b.works;
}
int main() {
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; i++) {cin >> p[i].name >> p[i].work >> p[i].bg >> p[i].level ; p[i].id = i;}
    sort(p + 4 , p + 1 + n , cmp);
    for(int i = 1 ; i <= n ; i++) {
        if(i == 1) p[i].work = "BangZhu" , p[i].works = 1;
        else if(i >= 2 && i <= 3) p[i].work = "FuBangZhu" , p[i].works = 2;
        else if(i >= 4 && i <= 5) p[i].work = "HuFa", p[i].works = 3;
        else if(i >= 6 && i <= 9) p[i].work = "ZhangLao", p[i].works = 4;
        else if(i >= 10 && i <= 16) p[i].work = "TangZhu", p[i].works = 5;
        else if(i >= 17 && i <= 41) p[i].work = "JingYing", p[i].works = 6;
        else p[i].work = "BangZhong", p[i].works = 7;
    }
    sort(p + 1 , p + 1 + n , cmp1);
    for(int i = 1 ; i <= n ; i++) cout << p[i].name << " " << p[i].work << " " << p[i].level << endl ;
    return 0;
}