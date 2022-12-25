#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
	int h,w,n,a,x,y;
	cin>>w>>h>>n;
	int d[4]={0,w,0,h};
	for(int i=0;i<n;i++){
		cin>>x>>y>>a;a--;
		if(a==0)d[a]=max(d[a],x);
		if(a==2)d[a]=max(d[a],y);
		if(a==1)d[a]=min(d[a],x);
		if(a==3)d[a]=min(d[a],y);
	}
	cout<<max(0,(d[1]-d[0]))*max(0,(d[3]-d[2]))<<endl;
	return 0;
}
