#include<bits/stdc++.h>
using namespace	std;
int main(){
    int i,n;
	double m=1,f=1;
	scanf("%d",&n);
    for(i=1;i<=n;i++){
    	m*=i;
		f+=1/m;
	}
    printf("%.10lf\n",f);
	return 0;
}