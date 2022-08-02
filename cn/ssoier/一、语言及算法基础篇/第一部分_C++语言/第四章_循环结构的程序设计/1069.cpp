#include<cstdio>
int main(){
	int s=1,a=0,n=0;
	scanf("%d%d",&a,&n);
	for(int i=0;i<n;i++){
		s*=a;	
	}
	printf("%d",s);
	return 0;
}