#include "bits/stdc++.h"
using namespace std;
int main(){
	int n,a,b;
	cin>>n;
	int t,m,mi;
	if(n/1000==n/100%10&&n/1000==n/10%10&&n/1000==n%10){
		printf("%04d - %04d = %04d\n",n,n,0);
		return 0;
	}
	do{
		a=0;
		b=0;
		t=n;
		for(int k=0;k<4;k++){
			m=t%10;
			mi=1;
			for(int i=10;i<=1000;i*=10)
				if(t/i%10>m){
				m=t/i%10;
				mi=i;
			}
			a+=m;
			a*=10;
			t-=m*mi;
		}
		a/=10;
		t=n;
		for(int k=0;k<4;k++){
			m=t%10;
			mi=1;
			for(int i=10;i<=1000;i*=10)
				if(t/i%10<m){
				m=t/i%10;
				mi=i;
			}
			b+=m;
			b*=10;
			t=t-m*mi+9*mi;
		}
		b/=10;
		n=a-b;
		printf("%04d - %04d = %04d\n",a,b,n);
	}while(n!=6174);
	return 0;
}
