#include<iostream>
using namespace std;
const int N=3e4+100;
int fa[N],h[N],d[N];
int find(int x){
	if(fa[x]!=x){
		int t=fa[x];
		fa[x]=find(fa[x]);
		h[x]+=h[t];
	}
	return fa[x];
}
void join(int x,int y){
	x=find(x);
	y=find(y);
	if(x!=y){
		fa[x]=y;
		h[x]+=d[y];
		d[y]+=d[x];
	}
}
int main(){
	int t;
	cin>>t;
	for(int i=1;i<N;i++){
		fa[i]=i;
		d[i]=1;
	}
	while(t--){
		char c;
		cin>>c;
		int u,v;
		if(c=='M'){
			cin>>u>>v;
			join(u,v);
		}else{
			cin>>u;
			int w=find(u);
			cout<<h[u]<<endl;
		}
	}
	return 0;
}