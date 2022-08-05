#include <stdio.h>
int main(){
    int i,n;
 	scanf("%d",&n);
 	for(i=2;i*i<=n;i++)
 		if(n%i==0)printf("%d",n/i);
	return 0;
}