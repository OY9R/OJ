#include "bits/stdc++.h"
#define ll long long
using namespace std;
int num[500][500];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m,n,a,b,t;
	cin>>m>>n>>a>>b>>t;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++){
			int tmp;
			cin>>tmp;
			if(tmp<a||tmp>b)
				printf("%03d",tmp);
			else
				printf("%03d",t);
			if(j!=n-1)
				printf(" ");
			else
				printf("\n");
		}
	return 0;
 } 