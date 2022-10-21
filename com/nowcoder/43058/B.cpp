#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main() { // long long
    ld n;
    cin>>n;
    for(ld i=1;i<n;i++){
        if((powl(i,11)-i)*(pow(i,451)-pow(i,4))==((ll)((pow(i,11)-pow(i,4))*(pow(i,11)-i)))%(451*4)){
            cout<<i<<' ';
        }
    }
    return 0;
}