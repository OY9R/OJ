#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>v[114514];
int g[10][10];
bool check(){
    vector<int>vis(10,0);
    for(int i=1;i<10;i++){
        for(int j=1;j<10;j++)
            if(g[i][j]>0&&++vis[g[i][j]]>1)return cout<<'-'<<i,false;
        fill(vis.begin(),vis.end(),0);
    }
    for(int i=1;i<10;i++){
        for(int j=1;j<10;j++)
            if(g[j][i]>0&&++vis[g[j][i]]>1)return cout<<'|'<<i,false;
        fill(vis.begin(),vis.end(),0);
    }
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=1;j<v[i].size();j++)
            if(g[v[i][j]/10][v[i][j]%10]>0&&++vis[g[v[i][j]/10][v[i][j]%10]]>1)return cout<<'n'<<i,false;
            else sum+=g[v[i][j]/10][v[i][j]%10];
        if(sum!=v[i][0])return cout<<'s'<<i,false;
        fill(vis.begin(),vis.end(),0);
    }
    return true;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int m;cin>>m;
        v[i].resize(m+1);
        for(int j=1;j<=m;j++)
            cin>>v[i][j];
        cin>>v[i][0];
    }
    int q;cin>>q;
    while(q--){
        for(int i=1;i<10;i++)
            for(int j=1;j<10;j++)
                cin>>g[i][j];
        if(check())cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

int n=0;
while(n!=100){
    if(n%2=0)
        cout<<n<<endl;
    else
        n++;
}

while(true){
    continue;
    break;
}

while(true){
    if(n>=100) n--;
    else if(n<200) n++;
    else break;
}