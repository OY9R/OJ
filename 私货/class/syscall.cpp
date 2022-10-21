#include<bits/stdc++.h>
using namespace std;
struct Process {
    char id;
    int arrive;
    int time;
};
bool cmp(Process a, Process b){
    return a.arrive<b.arrive;
}
int maxn=0;
void FCFS(vector<Process> ps){
    vector<int> list;
    vector<int> time(ps.size());
    vector<bool> busy(10000001);
    fill(busy.begin(),busy.end(),false);
    for(int i=0;i<ps.size();i++){
        for(int t=0,r=0;r<ps[i].time;t++){
            if(!busy[t+ps[i].arrive]){
                list.push_back(i);
                busy[t+ps[i].arrive]=true;
                r++;
            }
        }
    }
    for(int i=0;i<ps.size();i++){
        time[i]=ps[i].time;
    }
    cout<<"FCFS ";
    for(int i=0;i<list.size();i++)
        cout<<ps[list[i]].id;
    cout<<endl;
    for(int i=0;i<ps.size();i++){
        cout<<ps[i].id<<' ';
        for(int j=0;j<list.size();j++){
            if(j<ps[i].arrive)cout<<' ';
            else if(i==list[j]) cout<<'R',time[i]--;
            else cout<<'.';
            if(time[i]==0)break;
        }
        cout<<endl;
    }
}
void RR(vector<Process> ps){
    vector<int> list;
    vector<int> time(ps.size());
    queue<int> run;
    fill(time.begin(),time.end(),0);
    for(int t=0,i=0;i<ps.size()||!run.empty();t++){
        if(ps[i].arrive==t)run.push(i++);
		if(run.empty())continue;
        list.push_back(run.front());
        time[run.front()]++;
        if(time[run.front()]<ps[run.front()].time)
            run.push(run.front());
        run.pop();
    }
    cout<<"RR   ";
    for(int i=0;i<list.size();i++)
        cout<<ps[list[i]].id;
    cout<<endl;
    for(int i=0;i<ps.size();i++){
        cout<<ps[i].id<<' ';
        for(int j=0;j<list.size();j++){
            if(j<ps[i].arrive)cout<<' ';
            else if(i==list[j]) cout<<'R',time[i]--;
            else cout<<'.';
            if(time[i]==0)break;
        }
        cout<<endl;
    }
}
void SPN(vector<Process> ps){
    vector<int> list;
    vector<int> time(ps.size());
    fill(time.begin(),time.end(),0);
    int t=0;
    while(t<maxn){
        int run=-1,mintime=INT_MAX;
        for(int i=0;i<ps.size();i++)
            if(time[i]==0&&ps[i].arrive<=t&&ps[i].time<mintime)
                run=i,mintime=ps[i].time;
        if(run==-1){
            t++;
            continue;
        }
        time[run]=ps[run].time;
        for(int i=0;i<ps[run].time;i++)
            list.push_back(run),t++;
    }
    cout<<"SPN  ";
    for(int i=0;i<list.size();i++)
        cout<<ps[list[i]].id;
    cout<<endl;
    for(int i=0;i<ps.size();i++){
        cout<<ps[i].id<<' ';
        for(int j=0;j<list.size();j++){
            if(j<ps[i].arrive)cout<<' ';
            else if(i==list[j]) cout<<'R',time[i]--;
            else cout<<'.';
            if(time[i]==0)break;
        }
        cout<<endl;
    }
}
void SRTN(vector<Process> ps){
    vector<int> list;
    vector<int> time(ps.size());
    fill(time.begin(),time.end(),0);
    int t=0;
    while(t<maxn){
        int run=-1,mintime=INT_MAX;
        for(int i=0;i<ps.size();i++)
            if(time[i]<ps[i].time&&ps[i].arrive<=t&&ps[i].time<mintime)
                run=i,mintime=ps[i].time;
        if(run==-1){
            t++;
            continue;
        }
        time[run]++;
        list.push_back(run);
        t++;
    }
    cout<<"SRTN ";
    for(int i=0;i<list.size();i++)
        cout<<ps[list[i]].id;
    cout<<endl;
    for(int i=0;i<ps.size();i++){
        cout<<ps[i].id<<' ';
        for(int j=0;j<list.size();j++){
            if(j<ps[i].arrive)cout<<' ';
            else if(i==list[j]) cout<<'R',time[i]--;
            else cout<<'.';
            if(time[i]==0)break;
        }
        cout<<endl;
    }
}
void HRRN(vector<Process> ps){
    vector<int> list;
    vector<int> time(ps.size());
    fill(time.begin(),time.end(),0);
    int t=0;
    while(t<maxn){
        int run=-1;
        double maxxyb=-1;
        for(int i=0;i<ps.size();i++)
            if(time[i]==0&&ps[i].arrive<=t&&(t-ps[i].arrive)/(double)ps[i].time>maxxyb)
                run=i,maxxyb=(t-ps[i].arrive)/(double)ps[i].time;
        if(run==-1){
            t++;
            continue;
        }
        time[run]=ps[run].time;
        for(int i=0;i<ps[run].time;i++)
            list.push_back(run),t++;
    }
    cout<<"HRRN ";
    for(int i=0;i<list.size();i++)
        cout<<ps[list[i]].id;
    cout<<endl;
    for(int i=0;i<ps.size();i++){
        cout<<ps[i].id<<' ';
        for(int j=0;j<list.size();j++){
            if(j<ps[i].arrive)cout<<' ';
            else if(i==list[j]) cout<<'R',time[i]--;
            else cout<<'.';
            if(time[i]==0)break;
        }
        cout<<endl;
    }
}
void FB(vector<Process> ps){
    queue<int> run[3];
    vector<int> list;
    vector<int> time(ps.size());
    fill(time.begin(),time.end(),0);
    int t=0,tt[3]={0,0,0};
    while(t<maxn){
        for(int i=0;i<ps.size();i++)
            if(time[i]==0&&ps[i].arrive<=t)
                run[0].push(i);
        for(int i=0;i<3;i++){
            if(run[i].empty())continue;
            int r=run[i].front();
            for (int j=i+1;j<3;j++)
                if(tt[j]!=0){
                    tt[j]=0;
                    run[j].push(run[j].front());
                    run[j].pop();
                }
            list.push_back(r);
            time[r]++;
            if(time[r]<ps[r].time){
                tt[i]++;
                if(tt[i]>=(1<<i)){
                    tt[i]=0;
                    run[i].pop();
                    run[min(i+1,2)].push(r);
                }
            }else{
                tt[i]=0;
                run[i].pop();
            }
            break;
        }
        t++;
    }
    cout<<"FB   ";
    for(int i=0;i<list.size();i++)
        cout<<ps[list[i]].id;
    cout<<endl;
    for(int i=0;i<ps.size();i++){
        cout<<ps[i].id<<' ';
        for(int j=0;j<list.size();j++){
            if(j<ps[i].arrive)cout<<' ';
            else if(i==list[j]) cout<<'R',time[i]--;
            else cout<<'.';
            if(time[i]==0)break;
        }
        cout<<endl;
    }
}
int main() {
    int n;
    cin>>n;
    vector<Process> ps(n);
    for(int i=0;i<n;i++){
        cin>>ps[i].id>>ps[i].arrive>>ps[i].time;
        maxn+=ps[i].time;
    }
    sort(ps.begin(),ps.end(),cmp);
    FCFS(ps);
    RR(ps);
    SPN(ps);
    SRTN(ps);
    HRRN(ps);
    FB(ps);
    return 0;
}
