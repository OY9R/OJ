#include "bits/stdc++.h"
using namespace std;
int m[10005];
int main(){
	int n,i=0;
	for(int j=0;j<10;j++){
		cin>>n;
		for(int k=0;k<n;k++)
			m[i++]=j;
	}		
	sort(m,m+i);
	int j=0;
	while(m[j]==0)j++;
	swap(m[0],m[j]);
	for(j=0;j<i;j++)cout<<m[j];
	return 0;	
}

