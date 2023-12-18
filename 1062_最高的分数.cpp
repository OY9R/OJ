#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int maxn=0;
    for(int i=0;i<n;i++){
        int m;cin>>m;
        if(m>maxn)maxn=m;
    }
    cout<<maxn<<endl;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int maxn=0;
    while(n--){
        int m;cin>>m;
        if(m>maxn)maxn=m;
    }
    cout<<maxn<<endl;
}