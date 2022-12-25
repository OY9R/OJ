#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<queue<int>> aa;
    for(int i=0;i<n;i++){
        queue<int> a;
        int k;cin>>k;
        for(int j=0;j<k;j++){
            int b;cin>>b;
            if(a.empty()||a.back()<b)
                a.push(b);
            else{
                aa.push_back(a);
                a = queue<int>();
                a.push(b);
            }
        }
        aa.push_back(a);
        a = queue<int>();
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i=0;i<aa.size();i++){
        pq.push({aa[i].front(),i});
        aa[i].pop();
    }
    int cnt=0;int now=-1;
    while(!pq.empty()){
        int i=pq.top().second;
        if(i!=now)cnt++,now=i;
        if(!aa[i].empty()){
            pq.push({aa[i].front(),i});
            aa[i].pop();
        }
        pq.pop();
    }
	cout<<cnt-n<<' '<<cnt-1<<endl;
	return 0;
}