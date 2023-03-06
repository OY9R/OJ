#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct Tree {
    int n;
    vector<int> siz,top,dep,parent,in,out;
    vector<vector<int>> adj;
    Tree(int n):
        n(n),siz(n),top(n),dep(n),parent(n,-1),in(n),out(n),adj(n) {}
    void add(int u,int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void init(int root= 0) {
        top[root]= root;
        dfs1(root),dfs2(root);
    }
    void dfs1(int u) {
        if(parent[u] != -1)
            adj[u].erase(find(adj[u].begin(),adj[u].end(),parent[u]));
        siz[u]= 1;
        for(auto &v: adj[u]) {
            parent[v]= u;
            dep[v]= dep[u]+1;
            dfs1(v);
            siz[u]+= siz[v];
            if(siz[v] > siz[adj[u][0]])
                swap(v,adj[u][0]);
        }
    }
    int cur= 0;
    void dfs2(int u) {
        in[u]= cur++;
        for(auto v: adj[u]) {
            top[v]= v == adj[u][0] ? top[u] : v;
            dfs2(v);
        }
        out[u]= cur;
    }
    int lca(int u,int v) {
        while(top[u] != top[v])
            if(dep[top[u]] > dep[top[v]]) u= parent[top[u]];
            else v= parent[top[v]];
        return dep[u] < dep[v] ? u : v;
    }
};
int main() {
    int n,m,root;
    cin >> n >> m >> root;
    Tree tree(n);
    for(int i= 1; i < n; ++i) {
        int a,b;
        cin >> a >> b;
        a--,b--;
        tree.add(a,b);
    }
    tree.init(root - 1);
    while(m--) {
        int a,b;
        cin >> a >> b;
        a--,b--;
        cout << tree.lca(a,b)+1 << "\n";
    }
}