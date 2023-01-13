#include<bits/stdc++.h>
using namespace std;
struct node{
    string s;
    int a,b;
    bool operator<(const node &x)const{
        return b>x.b;
    }
};
int main(){
    string s;
    priority_queue<node> q;
    while(cin>>s){
        if(s=="GET"){
            if(q.size()){
                cout<<q.top().s<<' '<<q.top().a<<endl;
                q.pop();
            }else cout<<"EMPTY QUEUE!\n";
        }else{
            node e;cin>>e.s>>e.a>>e.b;
            q.push(e);
        }
    }
}