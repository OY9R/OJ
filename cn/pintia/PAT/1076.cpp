#include "bits/stdc++.h"
#define ll long long
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;i++){
		int tar;
		for(int j=0;j<4;j++){
			char a,b;
			scanf("%c-%c",&a,&b);
			getchar();
			if(b=='T')
				tar=a-'A';
		}
		printf("%d",1+tar);
	}
	printf("\n");
	return 0;
 } 