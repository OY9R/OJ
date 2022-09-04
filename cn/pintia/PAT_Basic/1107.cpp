#include "bits/stdc++.h"
#define ll long long
using namespace std;
int n,mun,m,win=0;
int main(){
	cin>>n>>mun;
	for(int i=1;i<=n;i++){
		int max=0;
		for(int j=1;j<=mun;j++){
			cin>>m;
			if(m>max)
				max=m;
		}
		cout<<max<<(i==n?"":" "); 
		if(max>win)
			win=max;
	} 
	cout<<endl<<win;
	return 0;
}