#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int g[8][8]={
    {0,0,0,0,0,0,0,0},
    {0,0,1,1,2,3,3,4},
    {0,1,0,2,1,2,2,3},
    {0,1,2,0,1,2,2,3},
    {0,2,1,1,0,1,1,2},
    {0,3,2,2,1,0,2,1},
    {0,3,2,2,1,2,0,1},
    {0,4,3,3,2,1,1,0},
};
void solve(){
    int a,b,c,d;cin>>a>>b>>c>>d;
    cout<<min(g[a][c]+g[b][d],g[a][d]+g[b][c])<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}