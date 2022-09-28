#include<bits/stdc++.h>
using namespace std;
const double eps=1e-8;
inline double f(double x){
	return 8*pow(x,4)+7*pow(x,3)+2*pow(x,2)+3*x+6;
}
int main(){
	int n;
	cin>>n;
	while(n--){
		double y;
		cin>>y;
		if(f(0)>y||f(100)<y){
            printf("No solution!\n");
            continue;
		}
		double l=0,r=100;
		while(r-l>eps){
			double m=(l+r)/2;
			if(f(m)>y)r=m;
			else l=m;
		}
		printf("%.4lf\n",l);
	}
	return 0;
}//Shaoxing--binary
