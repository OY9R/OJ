#include "bits/stdc++.h"
#define ll long long
using namespace std;
long long int G1,G2,K1,K2;
int S1,S2;
int main(){
	scanf("%lld.%d.%lld %lld.%d.%lld",&G1,&S1,&K1,&G2,&S2,&K2);
	K1+=G1*17*29+S1*29;
	K2+=G2*17*29+S2*29;
	if(K1<=K2){
		K2-=K1;
		G2=K2/(17*29);
		K2-=G2*17*29;
		S2=K2/29;
		K2-=S2*29;
		printf("%lld.%d.%lld\n",G2,S2,K2);
	}else{
		K1-=K2;
		G1=K1/(17*29);
		K1-=G1*17*29;
		S1=K1/29;
		K1-=S1*29;
		printf("-%lld.%d.%lld\n",G1,S1,K1);
	}
	return 0;
 } 