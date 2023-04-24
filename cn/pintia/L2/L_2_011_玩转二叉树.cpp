#include<bits/stdc++.h>
using namespace std;
int n,in[31],pre[31];
int L[100],R[100];
int cont(int root, int l, int r){
    if(l>r) return 0;
    int k,num=pre[root];
    for(k=l;k<=r;k++){
        if(in[k]==num) break;
    }
    L[num] = cont(root+1,l,k-1);
    R[num] = cont(root+k-l+1,k+1,r);
    return num;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>in[i];
    for(int i=0;i<n;i++) cin>>pre[i];
    cont(0,0,n-1);
    queue<int> q;
    vector<int> v;
    q.push(pre[0]);
    while(!q.empty()){
        int t = q.front();
        q.pop();
        v.push_back(t);
        if(R[t]) q.push(R[t]);
        if(L[t]) q.push(L[t]);
    }
    for(int i=0;i<v.size();i++){
        if(i) cout<<" ";
        cout<<v[i];
    }
	return 0;
}