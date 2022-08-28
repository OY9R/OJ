#include "bits/stdc++.h"
#define ll long long
using namespace std;
char card[1004];
int cards[11];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int ld=0,uz=0,vd=0,se=0,dz=0,dp=0;
		int n;
		cin>>n;
		if(n==1){
			cout<<"YES"<<endl;
			continue;
		}
		for(int i=0;i<n;i++){
			cin>>card[i];
			cards[card[i]]++;
		}
		for(int i=1;i<=10;i++){
			if(n==4&&cards[i]==4){
				vd=1;
				break;
			}
			if(n==2&&cards[i]==2){
				dz=1;
				break;
			}
			if(n==5&&cards[i]==3){
				se=1;
				break;
			}
			if(n>=5&&uz>0){
				if(cards[i]==1)
					uz++;
				else if(cards[i]==0){
					if(uz>=5)
						uz=-2;
					else
						uz=-1;
				}else{
					uz=-1;
				}
			}
			if(n>=5&&uz==0&&cards[i]==1){
				uz++;
			}
			if(n>=5&&uz==-2&&cards[i]!=0){
				uz=-1;
			}
			if(n>=6&&ld>0){
				if(cards[i]==2)
					ld++;
				else if(cards[i]==0){
					if(ld>=3)
						ld=-2;
					else
						ld=-1;
				}else{
					ld=-1;
				}
			}
			if(n>=6&&cards[i]==2&&ld==0){
				ld++;
			}
			if(n>=6&&cards[i]!=0&&ld==-2){
				ld=-1;
			}
		}
		if(ld==-2||ld>=3||uz==-2||uz>=5||vd==1||se==1||dz==1){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
