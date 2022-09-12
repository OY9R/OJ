#include<bits/stdc++.h>
using namespace std;
int m[1002][1002];
int ans1,ans2;
int main() {
	int x,y;
	scanf("%d%d",&x,&y);
	for(int i=1; i<=x; i++)
		for(int j=1; j<=y; j++)
			cin>>m[i][j];
	for(int i=1; i<=x; i++)
		for(int j=1; j<=y; j++)
			if(m[i][j]) {
				if(m[i+1][j+1])
					ans2++;
				if(m[i+1][j-1])
					ans2++;
				if(m[i+1][j])
					ans1++;
				if(m[i][j+1])
					ans1++;
			}
	cout<<ans1<<' '<<ans1+ans2<<endl;
	return 0;
}