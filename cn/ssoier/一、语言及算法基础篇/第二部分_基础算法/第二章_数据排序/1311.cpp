#include "bits/stdc++.h"
using namespace std;
int n,a[100009];
long long ans;
void msort(int l,int r){
	if(l>=r)return;
	int m=(l+r)/2;
	msort(l,m);
	msort(m+1,r);
	int b[r-l+1];
	for(int i=0;i<=r-l;i++)
		b[i]=a[l+i];
	int i=l,j=m+1;
	for(int k=l;k<=r;k++){
		if(i>m)a[k]=b[(j++)-l];
		else if(j>r)a[k]=b[(i++)-l];
		else if(b[i-l]<=b[j-l])a[k]=b[(i++)-l];
		else {ans+=m-i+1;a[k]=b[(j++)-l];}
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	msort(0,n-1);
	cout<<ans<<endl;
	return 0;
}
