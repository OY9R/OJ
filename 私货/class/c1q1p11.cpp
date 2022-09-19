#include<stdio.h>
#define N 4
int t[][N]={21,12,13,24,25,16,47,38,29,11,32,54,42,21,33,10};
void fun(int (*t)[N],int m){
	for(int i=0;i<N;i++){
		for(int j=N-1-m;j>=0;j--)
			t[i][j+m]=t[i][j];
		for(int j=0;j<m;j++)
			t[i][j]=0;
	}
}
int main(){
	int m;
	printf("\n原矩阵为：\n");
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			printf("%2d ",t[i][j]);
		printf("\n");
	}
	printf("请输入要右移的位数 m(m<=%d): ",N);
	scanf("%d",&m);
	fun(t,m);
	printf("\n右移后矩阵为：\n");
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			printf("%2d ",t[i][j]);
		printf("\n");
	}
	return 0;
}