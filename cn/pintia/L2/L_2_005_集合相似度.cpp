#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
    vector<set<int>> vs(n+1);
    for(int i=1;i<=n;i++){
        int nn;cin>>nn;
        for(int j=0;j<nn;j++){
            int t;cin>>t;
            vs[i].insert(t);
        }
    }
    int q;cin>>q;
    while(q--){
        int a,b;cin>>a>>b;
        int cnt=0;
        for(auto i:vs[a]){
            if(vs[b].find(i)!=vs[b].end()) cnt++;
        }
        double ans=cnt*1.0/(vs[a].size()+vs[b].size()-cnt);
        printf("%.2f%%\n",ans*100);
    }
	return 0;
}