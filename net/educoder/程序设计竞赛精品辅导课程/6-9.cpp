#include<stdlib.h>
#include<stdio.h>
const int N=100001;
int m[N];
int cmp(const void* a, const void* b){
    return *(int*)a- *(int*)b;
}
int main() {
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",m+i);
	qsort(m,n,sizeof(int),cmp);
    printf("%d\n",m[n/2]);
	return 0;
}