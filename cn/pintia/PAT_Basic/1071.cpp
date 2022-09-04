#include "bits/stdc++.h"
#define ll long long
using namespace std;
int cnt,k;
int main(){
	srand((unsigned)time(NULL));
	scanf("%d %d",&cnt,&k);
	for(int i=0;i<k;i++){
		int n1,n2,b,t;
		n1=rand()%100;
		cout<<n1<<endl;
		cin>>b>>t;
		n2=rand()%100;
		if(t>cnt){
			printf("Not enough tokens.  Total = %d.\n",cnt);
			continue;
		}
		if(n2>n1&&b==1||n2<n1&&b==0){
			cnt+=t;
			printf("%d Win %d!  Total = %d.\n",n2,t,cnt);
		}
		else{
			cnt-=t;
			printf("%d Lose %d.  Total = %d.\n",n2,t,cnt);
		}
		if(cnt==0){
			printf("Game Over.\n");
			break;
		}
			
	}
	return 0;
 } 