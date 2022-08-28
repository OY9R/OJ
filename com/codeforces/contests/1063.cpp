#include "bits/stdc++.h"
#define ll long long
using namespace std;

int main(){
	int N;
	double mmax=0,temp;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		double temp=sqrt(x*x+y*y);
		mmax=max(temp,mmax);
	}
	printf("%.2lf\n",mmax);
	return 0;
} 