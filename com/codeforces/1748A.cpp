#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
        if(n%2){
            cout<<(int)sqrt((2+n/2)*n/2);
        }else{
            cout<<(int)sqrt((1+n/2)*n/2);
        }
		cout<<endl;
	}
	return 0;
}