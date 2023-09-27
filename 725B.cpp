#include<bits/stdc++.h>
using namespace std;
int a[15],n,k;
bool b[15];
void dfs(int t){
    if(t==k){//返回的条件 已经有k个数了就输出 
        // 输出函数略
        cout<<endl;
        return;//然后返回 
    }for(int i=1;i<=n;i++){//枚举下一个（第k+1个）数 
        if(_________){//前提是这个数没被用过 
            //标记为被用过 
            //记录添加这个数到 a 数组 
            //并开始新的递归 
            //标记为被未用过
        }
    }
}
int main(){
    cin>>n>>k;
    dfs(0);
}