#include <stdio.h>
#include <math.h>
int n,cnt=0;
int i=2;
int isprime(int x){
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0)return 0;
	return 1;
}
int main(){
    scanf("%d",&n);
    while(1){
    	if(isprime(i))cnt++;
        if(cnt==n){
        	printf("%d\n",i);
        	break;
        }
        i++;
    }
	return 0;
}