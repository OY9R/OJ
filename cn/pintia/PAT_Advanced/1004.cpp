#include<bits/stdc++.h>
using namespace std;
int mm[100][100];
int cnt[100];
int n,m;
void dfs(int id,int deep){
    int i=0;
    if(!mm[id][i])cnt[deep]++;
    else
        while(mm[id][i])
            dfs(mm[id][i++],deep+1);
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int id,k;
        cin>>id>>k;
        for(int j=0;j<k;j++)
            cin>>mm[id][j];
    }
    dfs(1,0);
    int l=100;
    while(!cnt[--l]);
    cout<<cnt[0];
    for(int i=1;i<=l;i++)
        cout<<' '<<cnt[i];
    return 0;
}