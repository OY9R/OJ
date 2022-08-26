#include<stdio.h>
#include<iostream>
struct Node{
	int id;
	int rank;
	int flag;
}nodes[10005];
int num[10005];
int m,n;
int main(){
	for(int i=2;i<10005;i++)
		for(int j=2;i*j<10005;j++)
			num[i*j]=1;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		int temp;
		scanf("%d",&temp);
		nodes[temp].flag=0;
		nodes[temp].id=temp;
		nodes[temp].rank=i+1;
	}
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int temp;
		scanf("%04d",&temp);
		if(nodes[temp].rank==0)
			printf("%04d: Are you kidding?\n",temp);
		else if(nodes[temp].flag==1)
			printf("%04d: Checked\n",temp);
		else{
			if(nodes[temp].rank==1)
				printf("%04d: Mystery Award\n",temp);
			else if(num[nodes[temp].rank]==0)
				printf("%04d: Minion\n",temp);
			else
				printf("%04d: Chocolate\n",temp); 
			nodes[temp].flag=1;
		}
	}
	return 0;
}