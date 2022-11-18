#include<bits/stdc++.h>
using namespace std;
int main () {
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a.begin(),a.end());
        long long x=0,y=0;
        for(int i=n-1,k=0;~i;i--,k++){
            if(k%2){
                if(a[i]%2)
                    y+=a[i];
            }else{
                if(a[i]%2==0)
                    x+=a[i];
            }
        }
        //cout<<x<<' '<<y<<endl;
        if(x>y){
            cout<<"Alice\n";
        }else if(x==y){
            cout<<"Tie\n";
        }else{
            cout<<"Bob\n";
        }
    }
    return 0;
}