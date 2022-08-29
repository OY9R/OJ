#include "bits/stdc++.h"
#define ll long long
using namespace std;

int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n1,m1,n2,m2,m,n=1;
	scanf("%d/%d %d/%d %d",&n1,&m1,&n2,&m2,&m);
	if(n1*m2>n2*m1){
		swap(n1,n2);
		swap(m1,m2);
	}
	bool f=false;
	while(n*m1<=m*n1)n++;
	while(n*m2<m*n2){
		if(gcd(n,m)==1){
			if(f)cout<<' ';
			cout<<n<<'/'<<m;
			f=true;
		}
		n++;
	}
	return 0;
}
