#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
typedef long long ll;
const int N= 45;
int n;
int postorder[N], inorder[N];                                  // 后序遍历，中序遍历
unordered_map<int, int> l, r, pos;                             // 每个点左右儿子，pos代表在中序遍历中每个值对应的下标
int build(int il, int ir, int pl, int pr) {                    // 中序遍历和后序遍历左右端点
    int root= postorder[pr];                                   // 根节点是后序遍历的右端点
    int k= pos[root];                                          // 根节点在中序遍历中的下标
    if(il < k) l[root]= build(il, k - 1, pl, pl + k - 1 - il); // 左子树存在
    // 左子树中序遍历和后序遍历的长度一样所以 x-pl=k-1-il
    if(ir > k) r[root]= build(k + 1, ir, pl + k - 1 - il + 1, pr - 1); // 右子树存在
    return root;
}
void bfs(int root, int n) {
    queue<int> q;
    q.push(root);
    while(q.size()) {
        auto t= q.front();
        q.pop();
        n--;
        if(n != 0) cout << t << " ";
        else cout << t;
        if(l.count(t)) q.push(l[t]); // 左子树存在，插入队列
        if(r.count(t)) q.push(r[t]); // 右子树存在，插入队列
    }
}
int main() {
    cin >> n;
    for(int i= 0; i < n; i++) cin >> postorder[i];
    for(int i= 0; i < n; i++) {
        cin >> inorder[i];
        pos[inorder[i]]= i; // 中序遍历每个值对应的下标
    }
    int root= build(0, n - 1, 0, n - 1); // 中序遍历，后序遍历区间
    bfs(root, n);
    return 0;
}