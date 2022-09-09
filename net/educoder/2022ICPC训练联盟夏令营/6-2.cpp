#include<bits/stdc++.h>
using namespace std;
#define maxn 100015
#define LL long long
LL  ll[maxn],rr[maxn];
stack<LL >s,t;
LL  sum[maxn];
LL  a[maxn];
int main() {
	LL  n;
	cin>>n;
	memset(sum,0,sizeof(sum));
	for(LL  j=1; j<=n; j++) {
		cin>>a[j];
		sum[j]=a[j]+sum[j-1];
	}
	for(LL  j=1; j<=n; j++) {
		while(s.size()&&a[j]<=a[s.top()])
			s.pop();
		if(!s.size()) ll[j]=1;
		else ll[j]=s.top()+1;
		s.push(j);
	}

	for(LL  j=n; j>=1; j--) {
		while(t.size()&&a[j]<=a[t.top()])
			t.pop();
		if(!t.size()) rr[j]=n;
		else rr[j]=t.top()-1;
		t.push(j);
		//cout<<rr[j]<<endl;
	}
	LL mx=-1,l,r;
	for(LL  j=1; j<=n; j++) {
		LL ans=1LL*a[j]*(sum[rr[j]]-sum[ll[j]-1]);
		if(ans>mx) {
			mx=ans;
			l=ll[j];
			r=rr[j];
		}
	}
	cout<<mx<<endl;
	cout<<l<<" "<<r<<endl;
}

