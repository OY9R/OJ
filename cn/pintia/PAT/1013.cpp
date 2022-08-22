#include "bits/stdc++.h"
#define MAXN 500005
using namespace std;
int num[MAXN];
int main(){
	for(int i=2;i<MAXN;i++)
		for(int j=2;i*j<MAXN;j++)
			num[i*j]=1;
	int m,n,cnt=0,flag=0;
	cin>>m>>n;
	for(int i=2;cnt<=n;i++){
		if(num[i]==0&&flag==0){
			cnt++;
			if(cnt==m)flag=1;
		}
		if(num[i]==0&&flag==1){
			cout<<i;
			if((cnt-m+1)%10==0&&cnt!=m||cnt==n)
				cout<<endl;
			else
				cout<<' ';
			cnt++;
		}
	}
	return 0;
} 
