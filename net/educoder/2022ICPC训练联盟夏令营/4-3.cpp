#include<bits/stdc++.h>
using namespace std;
const int N=150010;
int t[N],flag[N];
int n,k,q;
set<int> s;
int main(){
    cin>>n>>k>>q;
    for(int i=1;i<=n;i++)cin>>t[i];
    while(q--){
        int type,id;
        cin>>type>>id;
        if(type==1){
            s.insert(t[id]);
            if(s.size()>k)s.erase(s.begin());
        }
        else if(type==2){
            if(s.find(t[id])==s.end())puts("NO");
            else puts("YES");
        }
    }
}