#include "bits/stdc++.h"
#define ll long long
#define N 100009
using namespace std;
int m[N];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,m,x,y,d;
		cin>>n>>m>>x>>y>>d;
		if((x-d>1&&y+d<m)||(x+d<n&&y-d>1)){
			cout<<m+n-2<<endl;
		}else{
			cout<<-1<<endl;
		}
	}
	return 0;
}
