#include "bits/stdc++.h"
using namespace std;
#define maxn 2000

int N;
double r,s,w,f,l1,l,d;
int main() {
	cin>>N>>r>>s>>w>>f>>l1>>l;
	while(cin>>d) {
		printf("%.7lf",d);
		for(int n=1; n<=N; n++) {
			double rr=(n==1 ? l1+r : l+r)+w*(n-1);
			double ll=2*(M_PI*rr+s);
			double md=fmod(d,ll);
			double wr=r+w*(n-1);
			if(md-f<s/2) {
				printf(" %.7lf %.7lf",f-md,-wr);
			} else if(md-f-s/2<rr*M_PI) {
				double tmp=(md-f-s/2)/rr;
				printf(" %.7lf %.7lf",-(s/2+sin(tmp)*wr),-cos(tmp)*wr);
			} else if(md-f-s/2-rr*M_PI<s) {
				printf(" %.7lf %.7lf",md-f-s-rr*M_PI,wr);
			} else if(md-f-s/2-rr*M_PI-s<rr*M_PI) {
				double tmp=(md-f-s/2-rr*M_PI-s)/rr;
				printf(" %.7lf %.7lf",s/2+sin(tmp)*wr,cos(tmp)*wr);
			} else {
				printf(" %.7lf %.7lf",ll-md+f,-wr);
			}
		}
		printf("\n");
	}
	return 0;
}
