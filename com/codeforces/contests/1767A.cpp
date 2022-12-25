#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int x[3],y[3];
		cin>>x[0]>>y[0];
        cin>>x[1]>>y[1];
        cin>>x[2]>>y[2];
        int flag=0;
        if(x[0]==x[1]||x[1]==x[2]||x[0]==x[2])flag++;
        if(y[0]==y[1]||y[1]==y[2]||y[0]==y[2])flag++;
        if(flag==2)cout<<"NO";
        else cout<<"YES";
		cout<<endl;
	}
	return 0;
}