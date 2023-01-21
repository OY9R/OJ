#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;cin>>T;
    while(T--){
        int A,a,B,b,C,c;double D,d,E,e,F,f;
        cin>>A>>a>>B>>b>>C>>c>>D>>d>>E>>e>>F>>f;
        if((A-B)*(c-b)==(C-B)*(a-b)||(A-B)*(A-B)+(a-b)*(a-b)==(C-B)*(C-B)+(c-b)*(c-b))cout<<"NO\n";
        else {
            if((A-B)*(A-B)+(a-b)*(a-b)>(C-B)*(C-B)+(c-b)*(c-b))swap(A,C),swap(a,c);
            if((D-E)*(D-E)+(d-e)*(d-e)>(F-E)*(F-E)+(f-e)*(f-e))swap(D,F),swap(d,f);
            if (fabs(((A-B)*(c-b)-(C-B)*(a-b))-((D-E)*(f-e)-(F-E)*(d-e)))<=1e-9)cout<<"NO\n";
            else cout<<"YES\n";
        }
    }
}