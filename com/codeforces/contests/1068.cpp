#include "bits/stdc++.h"
#define ll long long
using namespace std;
ll tol,pic[1005][1005];
int dir[8][2]={-1,-1,-1,0,-1,1,0,-1,0,1,1,-1,1,0,1,1};
map<ll,int> mm;
bool check(int x,int y);
int main(){
	int m,n;
	int x=-1,y=-1,cnt=0,tar;
	cin>>n>>m>>tol;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++){
			cin>>pic[i][j];
			mm[pic[i][j]]++;
		}
			
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if(check(i,j)&&mm[pic[i][j]]==1){
				cnt++;
				x=i;
				y=j;
				tar=pic[i][j];
			}
	if(cnt==0)
		printf("Not Exist\n");
	else if(cnt==1)
		printf("(%d, %d): %lld",y+1,x+1,tar);
	else
		printf("Not Unique\n");
	return 0;
 }
 bool check(int x,int y){
	for(int i=0;i<8;i++){
		if(x+dir[i][0]<0||y+dir[i][1]<0)
			continue;
		if(fabs(pic[x][y]-pic[x+dir[i][0]][y+dir[i][1]])<=tol)
			return false;
	}
	return true;
}