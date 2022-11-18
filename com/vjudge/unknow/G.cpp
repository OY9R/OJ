#include<bits/stdc++.h>
using namespace std;
const int N = 33;
int a[N];
int main() {
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        int cnt=0;
        for(int i=n-2;i>=0;i--){
            while(a[i+1]<=a[i]){
                if(a[i]==0){
                    cnt=-1;
                    break;
                }
                a[i]/=2;
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}