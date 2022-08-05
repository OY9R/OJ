#include <bits/stdc++.h>
using namespace std;
const int N=110;
int m[N][N];
queue<pair<int,int> > q;
void change(int fa,int fb,int a,int b){
    if(!m[fa][fb]){
        q.push({fa,fb});
        m[fa][fb]=m[a][b]+1;
    }
}
int main(){
    int x,y,z;
    cin>>x>>y>>z;
    q.push({0,0});
    m[0][0]=1;
    while(q.size()){
        auto u=q.front();
        q.pop();
        int a=u.first;
        int b=u.second;
        if(a==z||b==z)return cout<<m[a][b]-1,0;
        change(0,b,a,b);
        change(a,y,a,b);
        change(a,0,a,b);
        change(x,b,a,b);
        if(b<=x-a)change(a+b,0,a,b);
        else change(x,b-x+a,a,b);
        if(a<=y-b)change(0,b+a,a,b);
        else change(a-y+b,y,a,b);
    }
    cout<<"No Solution!";
    return 0;
}