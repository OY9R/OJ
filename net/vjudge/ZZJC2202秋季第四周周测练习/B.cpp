#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int N=2000001;
const int mod=100003;
int n,m;
int h[N],e[N],ne[N],idx;
int dist[N];
int cnts[N];
bool st[N];
void dij(){
	memset(dist,0x3f,sizeof dist);
	dist[1]=0,cnts[1]=1;
	priority_queue<PII,vector<PII>,greater<PII>> heap;
	heap.push({0,1});
	while(heap.size()){
		auto t=heap.top();
		heap.pop();
		int ver=t.second,distance=t.first;
		if(st[ver])continue;
		st[ver]=true;
		for(int i=h[ver];i!=-1;i=ne[i]){
			int j=e[i];
			if(dist[j]>distance+1){
				dist[j]=distance+1;
				heap.push({dist[j],j});
				cnts[j]=cnts[ver];
			}else if(dist[j]==distance+1){
				cnts[j]=(cnts[j]+cnts[ver])%mod;
			}
		}
	}
}
void add(int a,int b){
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
}
int main(){
	memset(h,-1,sizeof h);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		if(a!=b){
			add(a,b);
			add(b,a);
		}
	}
	dij();
	// for(int i=1;i<=n;i++)
	// 	cout<<dist[i]<<endl;
	for(int i=1;i<=n;i++)
		cout<<cnts[i]<<endl;
	return 0;
}