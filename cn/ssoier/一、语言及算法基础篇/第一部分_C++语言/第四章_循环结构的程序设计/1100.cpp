#include<bits/stdc++.h>
using namespace std;
int n,ans;
int main(){
    cin>>n;
    for(int i=1;;i++){
        if(i<=n){
            ans+=i*i;
            n-=i;
        }else{
            ans+=i*n;
            break;
        }
    }
    cout<<ans;
	return 0;
}