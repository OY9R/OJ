#include<bits/stdc++.h>
using namespace std;
const int N = 100100;
int a[N],n;
vector<int> ans;
void dfs1(int root,int tail){
    if(root > tail) return;
    int l = root + 1, r = tail;
    while(l <= tail && a[l] < a[root]) l++;
    while(r > root && a[r] >= a[root]) r--;
    if(l != r + 1) return;
    dfs1(root + 1, r);
    dfs1(l, tail);
    ans.push_back(a[root]);
}
void dfs2(int root,int tail){
    if(root > tail) return;
    int l = root + 1, r = tail;
    while(l <= tail && a[l] >= a[root]) l++;
    while(r > root && a[r] < a[root]) r--;
    if(l != r + 1) return;
    dfs2(root + 1, r);
    dfs2(l, tail);
    ans.push_back(a[root]);
}
int main(){
    cin>>n;
    for(int i = 0; i < n; i++) cin>>a[i];
    dfs1(0, n - 1);
    if(ans.size() != n){
        ans.clear();
        dfs2(0, n - 1);
    }
    if(ans.size() == n){
        cout<<"YES"<<endl;
        for(int i = 0; i < n; i++){
            if(i) cout<<" ";
            cout<<ans[i];
        }
    }else{
        cout<<"NO";
    }
	return 0;
}