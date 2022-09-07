#include<bits/stdc++.h>
using namespace std;
int p[51],t[51];
int main(){
    int n,c;
    cin>>n>>c;
    for(int i=0;i<n;i++)
        cin>>p[i];
    for(int i=0;i<n;i++)
        cin>>t[i];
    int limak=0,radewoosh=0;
    int w=0;
    for(int i=0;i<n;i++){
        w+=t[i];
        limak+=max(0,p[i]-c*w);
    }
    w=0;
    for(int i=n-1;i>=0;i--){
        w+=t[i];
        radewoosh+=max(0,p[i]-c*w);
    }
    if(limak>radewoosh)
        cout<<"Limak";
    else if(limak<radewoosh)
        cout<<"Radewoosh";
    else cout<<"Tie";
    return 0;
}