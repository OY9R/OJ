#include<stdio.h>
#define N 10000
int a[N];
int main(){
	int i,n,x,flag=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&x);
	for(i=0;i<n;i++)
		if(a[i]==x){
			printf("%d",i+1);
			flag=1;
			break;
		}
	if(flag==0)
		printf("-1\n");
    return 0;
}