#include<bits/stdc++.h>
using namespace std;
int post[33],in[33],level[3333];
void pre(int root,int start,int end,int index){
	if(start>end)return;
	int i;
	for(i=start;i<end&&in[i]!=post[root];i++);
	level[index]=post[root];
	pre(root-1-end+i,start,i-1,2*index+1);
	pre(root-1,i+1,end,2*index+2);
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>post[i];
	for(int i=0;i<n;i++)cin>>in[i];
	pre(n-1,0,n-1,0);
	int j=0;
	for(int i=0;j<n;i++)
		if(level[i]){
			cout<<level[i];
			j++;
			if(j!=n)cout<<' ';
		}
	return 0;
}