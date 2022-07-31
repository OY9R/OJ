#include "bits/stdc++.h"
using namespace std;
#define ll long long
double a,b,c;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>a>>b>>c;
	double d=b*b-4*a*c;
	if(d<0) {
		cout<<"No answer!"<<endl;
	} else if(!d) {
		printf("x1=x2=%.5lf\n",-b/(2*a));
	} else {
		d = sqrt(d);
		if(-(d+b)/(2*a)>(d-b)/(2*a)) {
			printf("x1=%.5lf;x2=%.5lf\n",(d-b)/(2*a),-(d+b)/(2*a));
		} else {
			printf("x1=%.5lf;x2=%.5lf\n",-(d+b)/(2*a),(d-b)/(2*a));
		}
	}
	return 0;
}
