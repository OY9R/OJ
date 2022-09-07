#include<bits/stdc++.h>
using namespace std;    
int main(){ 
	double odd[3];
	char choice[3]; 
	for(int i=0;i<3;i++){ 
		double a,b,c,x; 
		cin>>a>>b>>c;
		x=max(max(a,b),c);
		odd[i]=x;
		if(x==a)
			choice[i] = 'W';
		else if(x==b)
			choice[i] = 'T';
		else
			choice[i] = 'L'; 
	} 
	double maxPro=(odd[0]*odd[1]*odd[2]*0.65-1)*2;
	printf("%c %c %c %.2lf",choice[0],choice[1],choice[2],maxPro); 
	return 0;
}