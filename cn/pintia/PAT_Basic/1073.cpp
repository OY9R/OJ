#include "bits/stdc++.h"
#define ll long long
using namespace std;
struct Q{
	int score;
	int option;
	int right;
	int rights[5];
	int wrong[5];
}qs[109];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>qs[i].score>>qs[i].option>>qs[i].right;
		for(int j=0;j<qs[i].right;j++){
			char tmp;
			do{cin>>tmp;
			}while(tmp==' ');
			qs[i].rights[tmp-'a']=1;
		}
	}
	for(int i=1;i<=n;i++){
		double score=0;
		for(int j=1;j<=m;j++){
			char tmp;
			do{cin>>tmp;
			}while(tmp!='(');
			int o,os[5];
			for(int k=0;k<5;k++)os[k]=0;
			cin>>o;
			for(int k=1;k<=o;k++){
				char c;
				do{cin>>c;
				}while(c==' ');
				os[c-'a']++;
			}
			int w=0;
			for(int k=0;k<5;k++){
				if(qs[j].rights[k]!=os[k]){
					qs[j].wrong[k]++;
					if(qs[j].rights[k]==1&&w==0)w=1;
					if(qs[j].rights[k]==0)w=2;
				}
			}
			if(w==0)score+=(double)qs[j].score;
			else if(w==1)score+=((double)qs[j].score)/2;
		}
		printf("%.1lf\n",score);
	}
	int maxw=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<5;j++){
			maxw=max(qs[i].wrong[j],maxw);
		}
	}
	if(maxw==0)
		printf("Too simple\n");
	else
	for(int i=1;i<=m;i++){
		for(int j=0;j<5;j++){
			if(qs[i].wrong[j]==maxw){
				printf("%d %d-%c\n",maxw,i,j+'a');
			}
		}
	}
	return 0;
}
