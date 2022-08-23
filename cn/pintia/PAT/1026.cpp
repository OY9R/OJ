#include "bits/stdc++.h"
using namespace std;
int main(){
	long long int C1,C2;
	cin>>C1>>C2;
	int second,minute,hour;
	second=(0.5+(double)(C2-C1)/100);
	hour=second/3600;
	second=second-hour*3600;
	minute=second/60;
	second=second-minute*60;
	printf("%02d:%02d:%02d\n",hour,minute,second);
	return 0;
} 
