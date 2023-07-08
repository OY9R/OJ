#include<bits/stdc++.h>
using namespace std;
int a[110][110],n,m,q,b[110];//a：存储答案;nm：行列;b:一列最高元素在第几行
int col;
char idx[5];
int main(){
	cin>>n>>m>>q;
	for(int i=0;i<q;i++){

		cin>>idx[0]>>idx[1]>>col;
		col--;
		if(idx[0]=='A'/*A类型*/){
			switch(idx[1]){
				case '1':
					if(b[col]<b[col+1]/*找col，col+1谁大。用来寻找b[col(+1)]数值*/ && b[col+1]+1<=n-1/*上边界*/ && col+1<=m-1/*右边界*/){
						a[b[col+1]-1][col]=i+1;
						a[b[col+1]][col]=i+1;
						a[b[col+1]][col+1]=i+1;
						b[col+1]++;
						b[col]=b[col+1];
					}else if(b[col]+1<=n-1 && col+1<=m-1){
						a[b[col]][col]=i+1;
						a[b[col]+1][col]=i+1;
						a[b[col]+1][col+1]=i+1;
						b[col]+=2;
						b[col+1]=b[col];
					}
					break;
				case '2':
					if(b[col]>b[col+1] && b[col]<=n-1 && col+1<=m-1){
						a[b[col]][col]=i+1;
						a[b[col]][col+1]=i+1;
						a[b[col]-1][col+1]=i+1;
						b[col]++;
						b[col+1]=b[col];
					}else if(b[col+1]+1<=n-1 && col+1<=m-1){
						a[b[col+1]+1][col]=i+1;
						a[b[col+1]][col+1]=i+1;
						a[b[col+1]+1][col+1]=i+1;
						b[col]+=2;
						b[col+1]=b[col];
					}
					break;
				case '3':
					if(max(b[col],b[col+1])+1<=n-1 && col+1<=m-1){
						a[max(b[col],b[col+1])+1][col]=i+1;
						a[max(b[col],b[col+1])][col+1]=i+1;
						a[max(b[col],b[col+1])][col]=i+1;
						b[col]=max(b[col],b[col+1])+2;
						b[col+1]=b[col]-1;
					}
					
					break;
				case '4':
					if(max(b[col],b[col+1])+1<=n-1 && col+1<=m-1){
						a[max(b[col],b[col+1])][col]=i+1;
						a[max(b[col],b[col+1])][col+1]=i+1;
						a[max(b[col],b[col+1])+1][col+1]=i+1;
						b[col]=max(b[col],b[col+1])+1;
						b[col+1]=b[col]+1;
					}
					break;
			}
		}else if(idx[0]=='B'/*B类型*/){
			switch(idx[1]){
				case '1':
					if(b[col]+1<=n-1){
						a[b[col]][col]=i+1;
						a[b[col]+1][col]=i+1;
						b[col]+=2;
					}
					break;
				case '2':
					if(col+1<=m-1){
						a[max(b[col],b[col+1])][col]=i+1;
						a[max(b[col],b[col+1])][col+1]=i+1;
						b[col]=max(b[col],b[col+1])+1;
						b[col+1]=b[col];
					}
					break;
			}
		}
		/*for(int i=0;i<m;i++){
			cout<<b[i]<<" ";
		}
		cout<<"\n";
		for(int i=n-1;i>=0;i--){
			for(int j=0;j<m;j++){
				if(a[i][j]==0)  printf("|   ");//0不输出
				else printf("|%3d",a[i][j]);
			}
			printf("|\n");
		}*/
	}
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<m;j++){
			if(a[i][j]==0)  printf("|   ");//0不输出
			else printf("|%3d",a[i][j]);
		}
		printf("|\n");
	}
	return 0;
}