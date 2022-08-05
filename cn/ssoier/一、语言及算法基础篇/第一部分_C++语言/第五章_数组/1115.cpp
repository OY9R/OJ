#include <stdio.h>
#define N 10010
int a[N];
int main(){
    int i,max=-1,n,x;
    scanf("%d",&n);
    for(i=0;i<n;i++){
    	scanf("%d",&x);
    	a[x]+=1;
    	if(x>max)max=x;
	}
	for(i=0;i<=max;i++)
		printf("%d\n",a[i]);
    return 0;
}