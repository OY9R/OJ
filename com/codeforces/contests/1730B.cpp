#include<bits/stdc++.h>
using namespace std;
const int N=100100;
const double eps=1e-8;
int a[N],t[N];
double check(double n){
	double ret=0;
	for(int i=0;i<n;i++){
		ret=max(ret,abs(a[i]-n)+t[i]);
	}
	return ret;
}
void solve(){
	int n;
	cin>>n;
	int mmax=0,mmin=INT_MAX;
	for(int i=0;i<n;i++){
		cin>>a[i];
		mmax=max(mmax,a[i]);
		mmin=min(mmin,a[i]);
	}
	for(int i=0;i<n;i++)
		cin>>t[i];
	double ll=mmin,rr=mmax;
	double cll=check(ll);
	double crr=check(rr);
	double l=ll+(rr-ll)*0.4;
	double r=ll+(rr-ll)*0.6;
	double cl=check(l);
	double cr=check(r);
	while(rr-ll>eps){
		if(cl<cr){
			rr=r;crr=cr;
			r=l;cr=cl;
			l=ll+(rr-ll)*0.4;
			cl=check(l);
		}else{
			ll=l;cll=cl;
			l=r;cl=cr;
			r=ll+(rr-ll)*0.6;
			cr=check(r);
		}
	}
	cout<<ll<<endl;
}
int main() {
	int _;
	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}