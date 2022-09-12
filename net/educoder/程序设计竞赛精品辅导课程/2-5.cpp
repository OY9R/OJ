#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	while(cin>>n) {
		double mmax=0,mmin=INT_MAX,sum=0;
		for(int i=0; i<n; i++) {
			double tmp;
			cin>>tmp;
			mmax=max(mmax,tmp);
			mmin=min(mmin,tmp);
			sum+=tmp;
		}
		printf("%.2lf\n",(sum-mmax-mmin)/(n-2));
	}
	return 0;
}