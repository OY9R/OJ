#include "bits/stdc++.h"
#define ll long long
using namespace std;
int main(){
	int n;
	char a;
	cin>>n>>a;
	int len=(0.5+1.0*n/2);
	for(int i=0;i<len;i++){
		if(i==0||i==len-1){
			for(int j=0;j<n;j++)
				printf("%c",a);
			printf("\n");
		}else{
			for(int j=0;j<n;j++){
				if(j==0||j==n-1)
					printf("%c",a);
				else
					printf(" ");
			}
			printf("\n");
		}
	}
	return 0;
 } 