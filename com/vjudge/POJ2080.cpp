#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
string w[]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
int m[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);cout.tie(0);
    int n=-1;
    while(cin>>n&&n>=0){
        int y=2000,i=1,ww=n%7;
        while(n>=366-(y%400&&(y%4||y%100==0)))
            n-=366-(y%400&&(y%4||y%100==0)),y++;
        while(n>=m[i]-(i==2&&y%400&&(y%4||y%100==0)))
            n-=m[i]-(i==2&&y%400&&(y%4||y%100==0)),i++;
        printf("%d-%02d-%02d ",y,i,n+1);
        cout<<w[ww]<<endl;
    }
    return 0;
}