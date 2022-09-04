#include "bits/stdc++.h"
using namespace std;
int nodes[100000],nexts[100000];
int node_stank[100000];
int main(){
	int root,n,k;
	cin>>root>>n>>k;
	while(n--){
		int address,data,next;
		cin>>address>>data>>next;
		nodes[address]=data;
		nexts[address]=next;
	}
	int cnt=0,si=0;
	int node=root;
	bool first=true;
	while(node!=-1||cnt==k){
		if(cnt!=k){
			node_stank[si++]=node;
			cnt++;
			node=nexts[node];
		}else{
			while(--si>=0){
				if(!first){
					printf("%05d\n",node_stank[si]);
				}
				first=false;
				printf("%05d %d ",node_stank[si],nodes[node_stank[si]]);
			}
			si++;
			cnt=0;
		}
	}
	for(int i=0;i<si;i++){
		printf("%05d\n%05d %d ",node_stank[i],node_stank[i],nodes[node_stank[i]]);
	}
	printf("-1\n");
	return 0;
}
