#include<bits/stdc++.h>
using namespace std;
long long f(string s,long long r){
    long long ans=0;
    int l=s.length();
    for(int i=0;i<l;i++){
        ans*=r;
        if(s[i]>='0'&&s[i]<='9')
            ans+=s[i]-'0';
        else
            ans+=s[i]-'a'+10;
    }
    return ans;
}
long long g(string s){
    char m='0';
    for(int i=0;i<s.length();++i)
        m=max(m,s[i]);
    if(m<='9')return m-'0'+1;
    else return m-'a'+11;
}
int main(){
    string N1,N2;
    int tag;
    long long radix;
    cin>>N1>>N2>>tag>>radix;
    if(tag==2)
        swap(N1,N2);
    long long n1=f(N1,radix);
    long long l=g(N2),r=n1+1;
    while(l<=r){
        long long mid=(l+r)/2;
        long long tmp=f(N2,mid);
        if(l==r&&tmp!=n1)break;
        else if(tmp==n1){
            cout<<mid;
            return 0;
        }else if(tmp>n1||tmp<0)r=mid;
        else l=mid+1;
    }
    cout<<"Impossible";
    return 0;
}