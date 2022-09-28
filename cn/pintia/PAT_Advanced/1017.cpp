#include <bits/stdc++.h>
using namespace std;
struct time {
    int h;
    int m;
    int s;
};
struct custom {
    struct time arrive;
    int process;
};
bool cmp(struct custom c1,struct custom c2) {
    if(c1.arrive.h<c2.arrive.h)return true;
    else if(c1.arrive.h==c2.arrive.h) {
        if(c1.arrive.m<c2.arrive.m)return true;
        else if(c1.arrive.m==c2.arrive.m) {
            if(c1.arrive.s<c2.arrive.s)return true;
        }
    }
    return false;
}
bool cmp_time(struct time t1,struct time t2) {
    if(t1.h<t2.h)return true;
    else if(t1.h==t2.h) {
        if(t1.m<t2.m)return true;
        else if(t1.m==t2.m) {
            if(t1.s<t2.s)return true;
        }
    }
    return false;
}
int sub(struct time t1,struct time t2) {
    return (t1.h-t2.h)*60*60+(t1.m-t2.m)*60+(t1.s-t2.s);
}
int main() {
    vector<custom> customs;
    struct time wait[105];
    custom c;
    int m,n;
    cin>>m>>n;
    int wait_seconds=0,people;
    for(int i=0; i<m; i++) {
        scanf("%d:%d:%d %d",&c.arrive.h,&c.arrive.m,&c.arrive.s,&c.process);
        customs.push_back(c);
    }
    sort(customs.begin(),customs.end(),cmp);
    for(people=0; people<m; people++) {
        if(people<n) {
            if(cmp_time(customs[people].arrive, {8,0,0})) {
                wait_seconds+=sub({8,0,0},customs[people].arrive);
                wait[people]= {8+customs[people].process/60,customs[people].process%60,0};
            }
            else if(cmp_time({17,0,0},customs[people].arrive))break;
            else wait[people]= {customs[people].arrive.h+(customs[people].arrive.m+customs[people].process)/60,(customs[people].arrive.m+customs[people].process)%60,customs[people].arrive.s};
        } else {
            int tag=0;
            for(int i=0; i<n; i++)if(cmp_time(wait[i],wait[tag]))tag=i;
            if(cmp_time({17,0,0},customs[people].arrive))break;
            else {
                if(cmp_time(wait[tag],customs[people].arrive)) {
                    wait[tag]= {customs[people].arrive.h+(customs[people].arrive.m+customs[people].process)/60,(customs[people].arrive.m+customs[people].process)%60,customs[people].arrive.s};
                } else {
                    wait_seconds+=sub(wait[tag],customs[people].arrive);
                    wait[tag]= {wait[tag].h+(wait[tag].m+customs[people].process)/60,(wait[tag].m+customs[people].process)%60,wait[tag].s};
                }
            }
        }
    }
    printf("%.1f",wait_seconds/people/60.0);
    return 0;
}