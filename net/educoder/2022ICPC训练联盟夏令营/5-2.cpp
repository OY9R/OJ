#include<bits/stdc++.h>
using namespace std;

struct node {
    int value,id;
    bool operator < (const node &b) const {
        if(value==b.value)
            return id>b.id;
        return value<b.value;
    }
};

int main() {
    int t;
    while(cin>>t) {
        node pep;
        priority_queue<node>q[10];
        int time=1;
        string s;
        while(t--) {
            cin>>s;
            if(s=="IN") {
                int a;
                cin>>a>>pep.value;
                pep.id=time;
                time++;
                q[a-1].push(pep);
            } else {
                int a;
                cin>>a;
                if(q[a-1].empty())
                    cout<<"EMPTY"<<endl;
                else {
                    cout<<q[a-1].top().id<<endl;
                    q[a-1].pop();
                }
            }
        }
    }
    return 0;
}