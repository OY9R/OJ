#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main(){
    cin>>a>>b>>c;
    int ans=0;
    for(int i=0;i<=c;i++)
        for(int j=0;j<=c;j++)
            if(a*i+b*j==c)ans++;
    cout<<ans;
	return 0;
}