#include "bits/stdc++.h"
#define ll long long
using namespace std;
int n,d;
double e;
int main(){
	scanf("%d %lf %d",&n,&e,&d);
	int cnt1=0,cnt2=0;
	for(int i=0;i<n;i++){
		int t,cnt=0;
		scanf("%d",&t);
		for(int j=0;j<t;j++){
			double temp;
			scanf("%lf",&temp);
			if(temp<e)
				cnt++;
		}
		if(cnt>t*0.5&&t>d)
			cnt1++;
		else if(cnt>t*0.5)
			cnt2++;
	} 
	printf("%.1lf%% %.1lf%%",100.0*cnt2/n,100.0*cnt1/n);
	return 0;
 } 