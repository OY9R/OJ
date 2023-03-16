#include<bits/stdc++.h>
using namespace std;
int n,k,m;
map<int,vector<int> > g;
int p[6];
int main(){
    cin>>n>>k>>m;
    for(int i=1;i<=k;i++)cin>>p[i];
    for(int i=0;i<m;i++){
        int id,pi,s;cin>>id>>pi>>s;
        id=-id;
        if(g.count(id)){
            if(g[id][pi]<0)
                if(s==-1)g[id][pi]=-2;
                else g[id][pi]=0,g[id][0]=max(g[id][0],0);
            if(s!=-1&&g[id][pi]<s){
                if(g[id][0]<0)g[id][0]=0;
                g[id][0]+=s-g[id][pi];
                g[id][pi]=s;
            }
        }else{
            g[id]=vector<int>(k+1,-1);
            if(s==-1){
                g[id][pi]=-2;
            }else{
                g[id][0]=s;
                g[id][pi]=s;
            }
        }
    }
    vector<pair<int,vector<int> > > rank;
    for(auto a:g){
        if(a.second[0]<0)continue;
        int s=a.second[0]*10;
        for(int i=1;i<=k;i++)
            if(a.second[i]==p[i])s++;
        a.second[0]=a.first;
        rank.push_back({s,a.second});
    }
    sort(rank.begin(),rank.end());
    reverse(rank.begin(),rank.end());
    int bf=-2,no=0,bfno=-1;
    for(auto a:rank){
        no++;
        if(bf!=a.first/10){
            bf=a.first/10;
            bfno=no;
        }
        printf("%d %05d %d",bfno,-a.second[0],a.first/10);
        for(int i=1;i<=k;i++)
            if(a.second[i]==-1)cout<<" -";
            else if(a.second[i]==-2)cout<<" 0";
            else cout<<' '<<a.second[i];
        cout<<endl;
    }
}
