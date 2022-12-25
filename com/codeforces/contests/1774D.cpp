#include<bits/stdc++.h>
using namespace std;
vector<set<int>> g;
vector<int> n1;
int sum=0;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
        g.resize(n);
        n1.resize(n);
        sum=0;
        for(int i=0;i<n;i++){
            n1[i]=0;
            g[i].clear();
            for(int j=0;j<m;j++){
                int in;cin>>in;
                if(in){
                    g[i].insert(j);
                    n1[i]++;
                }
            }
            sum+=n1[i];
        }
        //cout<<sum;
        if(sum%n){
            cout<<"-1\n";
            continue;
        }
        vector<int> b(n);
        for(int i=0;i<n;i++)b[i]=i;
        sort(b.begin(),b.end(),[](int a,int b){return n1[a]<n1[b];});
        //for(int i=0;i<n;i++)cout<<b[i]<<' ';
        //cout<<endl;
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=max(0,n1[i]-sum/n);
        }
        cout<<cnt<<'\n';
        int l=0,ccnt=0;
        for(int r=n-1;r>l;r--){
            for(int i : g[b[r]]){
                if(l<r&&!g[b[l]].count(i)){
                    cout<<b[l]+1<<' '<<b[r]+1<<' '<<i+1<<'\n';
                    ccnt++;
                    n1[b[l]]++;
                    n1[b[r]]--;
                    g[b[l]].insert(i);
                    if(n1[b[l]]==sum/n)l++;
                    if(n1[b[r]]==sum/n)break;
                }
            }
        }
        while(ccnt<cnt);
	}
	return 0;
}