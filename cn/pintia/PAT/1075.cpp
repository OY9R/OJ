#include "bits/stdc++.h"
#define ll long long
using namespace std;
#include<iostream>
#include<stdio.h>
#include<queue>
#include<malloc.h>
using namespace std;
struct Node{
	int next;
	int id;
	int loc;
};
queue<struct Node> q[3];
struct Node nodes[100005];
int now,m,n;
int main(){
	scanf("%d %d %d",&now,&m,&n);
	for(int i=0;i<m;i++){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		nodes[x].id=y;
		nodes[x].next=z;
		nodes[x].loc=x;
	}
	while(now!=-1){
		if(nodes[now].id<0)
			q[0].push(nodes[now]);
		else if(nodes[now].id>=0&&nodes[now].id<=n)
			q[1].push(nodes[now]);
		else 
			q[2].push(nodes[now]);
		now=nodes[now].next;
	}
	int flag=0;
	while(!q[0].empty()){
		struct Node temp=q[0].front();
		q[0].pop();
		if(flag==0){
			printf("%05d %d ",temp.loc,temp.id);
			flag=1;
		}else
			printf("%05d\n%05d %d ",temp.loc,temp.loc,temp.id);
	}
	while(!q[1].empty()){
		struct Node temp=q[1].front();
		q[1].pop();
		if(flag==0){
			printf("%05d %d ",temp.loc,temp.id);
			flag=1;
		}else
			printf("%05d\n%05d %d ",temp.loc,temp.loc,temp.id);
	}
	while(!q[2].empty()){
		struct Node temp=q[2].front();
		q[2].pop();
		if(flag==0){
			printf("%05d %d ",temp.loc,temp.id);
			flag=1;
		}else
			printf("%05d\n%05d %d ",temp.loc,temp.loc,temp.id);
	}
	printf("-1");
	return 0;
 } 