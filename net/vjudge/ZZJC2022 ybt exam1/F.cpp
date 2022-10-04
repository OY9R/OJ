#include<stdio.h>
#include<math.h>
int main() {
	double a,b,c,d;
	scanf("%lf %lf %lf",&a,&b,&c);
	if(a==0)
		if(b==0)
			if(c==0)puts("INF");
			else puts("NO");
		else printf("%.3lf",-c/b);
	else{
		if(a<0)a=-a,b=-b,c=-c;
		d=b*b-4*a*c;
		if(d==0)printf("%.3lf",-b/2/a);
		else if(d<0)puts("NO");
		else{
			double x1=(-b-sqrt(d))/2/a;
			double x2=(-b+sqrt(d))/2/a;
			printf("%.3lf %.3lf",x1,x2);
		}
	}
	return 0;
}