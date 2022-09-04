#include"bits/stdc++.h"
using namespace std;
struct Node{
	int id;
	int num;
};
struct Node team[1005];
int main(){
	int n,mmax=-1,tar=-1;
	scanf("%d",&n);
	while(n--){
		int a,b,c;
		scanf("%d-%d %d",&a,&b,&c);
		team[a].num+=c;
		if(mmax<team[a].num){
			mmax=team[a].num;
			tar=a;
		}
	}
	printf("%d %d\n",tar,mmax);
	return 0;
} 