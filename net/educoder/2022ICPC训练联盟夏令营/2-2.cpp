#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 10004
int m[MAXN];
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d,",m+i);
	}
	scanf("%d",m+n);
	sort(m+1,m+n+1);
	int p=m[2]-m[1];
	for(int i=3;i<=n;i++){
		p=gcd(p,m[i]-m[i-1]);
	}
	cout<<(m[n]-m[1])/p+1<<endl;
}
