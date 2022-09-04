#include "bits/stdc++.h"
#define ll long long
using namespace std;
struct Moon{
	int id;
	int cnt;
} moons[10001];
bool cmp(struct Moon a,struct Moon b){
	if(a.cnt!=b.cnt)
		return a.cnt>b.cnt;
	return a.id<b.id;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,maxcnt=0;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			int t;
			cin>>t;
			moons[j].id=j;
			moons[j].cnt+=t;
			maxcnt=max(maxcnt,moons[j].cnt);
		}
	}
	sort(moons+1,moons+1+n,cmp);
	cout<<maxcnt<<endl;
	cout<<moons[1].id;
	for(int i=2;i<=n;i++)
		if(moons[i].cnt==moons[i-1].cnt)
			cout<<' '<<moons[i].id;
		else
			break;
	cout<<endl;
	return 0;
}
