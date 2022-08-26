#include "bits/stdc++.h"
#define ll long long
using namespace std;

int main(){
	double r1,r2,p1,p2;
	scanf("%lf %lf %lf %lf",&r1,&p1,&r2,&p2);
	double ans1=r1*cos(p1)*r2*cos(p2)-r1*sin(p1)*r2*sin(p2);
	double ans2=r1*cos(p1)*r2*sin(p2)+r2*cos(p2)*r1*sin(p1);
	if(ans1+0.005>=0&&ans1<0)
        printf("0.00");
    else
		printf("%.2lf",ans1);
	if(ans2>=0)
		printf("+%.2lfi\n",ans2);
	else if(ans2+0.005>=0&&ans2<0)
        printf("+0.00i");
    else
		printf("%.2lfi\n",ans2);
	return 0;
}
