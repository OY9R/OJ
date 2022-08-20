#include "bits/stdc++.h"
#define ll long long
#define ull unsigned long long

const int MAXN=1010;
const int MAXM=1010;

inline int solve(double a[][MAXN],bool l[],double ans[],const int& n) {
	int res=0,r=0;
	for(int i=0;i<n;i++){
		l[i]=false;
	}
	for(int i=0;i<n;i++){
		for(int j=r;j<n;j++){
			if(fabs(a[j][i])>EPS){
				for(int k=i;k<=n;k++){
					swap(a[j][k], a[r][k]);
					break;
				}
			}
		}
		
	}
}
