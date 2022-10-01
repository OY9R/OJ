#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
int a[N];
int f(int x) {
	if(a[x]==x)return x;
	else return a[x]=f(a[x]);
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	int z,x,y;
	for(int i=1; i<=n; i++)a[i]=i;
	while(m--) {
		cin>>z>>x>>y;
		if(z==1) {
			int y1=f(y);
			int x1=f(x);
			if(x1!=y1)a[x1]=y1;
		}
		if(z==2)
			if(f(x)!=f(y))cout<<"N"<<endl;
			else cout<<"Y"<<endl;
	}
}