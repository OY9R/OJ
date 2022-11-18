#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        int n=s.size();
        int maxn=0;
        for(char i='0';i<='9';i++)
            for(char j='0';j<='9';j++){
                int m=0;
                for(int k=0,f=0;k<n;k++,f=1-f){
                    if(f){
                        while(k<n&&s[k]!=j)k++;
                        if(k<n)m++;
                    }else{
                        while(k<n&&s[k]!=i)k++;
                        if(k<n)m++;
                    }
                }
                if(m%2&&i==j)maxn=max(maxn,m);
                if(m%2==0)maxn=max(maxn,m);
            }
        cout<<n-maxn<<'\n';
    }
}