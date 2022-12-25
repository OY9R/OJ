#include<bits/stdc++.h>
using namespace std;
bool inorder=false;
void ofind(vector<int> a){
    printf("请输入待查找的数字:");
    int k;cin>>k;
    auto it=find(a.begin(),a.end(),k);
    if(it==a.end())printf("查找失败:序列中不存在该数!\n");
    else printf("查找成功:该数在第%d位上 a[%d]=%d\n",it-a.begin(),it-a.begin(),k);
}
void tfind(vector<int> a){
    printf("请输入待查找的数字:");
    int k;cin>>k;
    auto it=lower_bound(a.begin(),a.end(),k);
    if(*it!=k)printf("查找失败:序列中不存在该数!\n");
    else printf("查找成功:该数是第%d位数 a[%d]=%d\n",it-a.begin(),it-a.begin(),k);
}
void print(vector<int> b,int n){
    if(b[n]==-1)return;
    cout<<b[n];
    cout<<'(';
    print(b,n*2);
    cout<<',';
    print(b,n*2+1);
    cout<<')';
}
void tmenu(vector<int> a){
    vector<int> b(a.size()<<8,-1);
    int n=0;
    for(int i=0;i<a.size();i++){
        int j=1;
        while(b[j]!=-1){
            if(b[j]>a[i])j*=2;
            else j=j*2+1;
        }
        b[j]=a[i];
        n=max(n,j);
    }
    print(b,1);
    cout<<endl;
    printf("1.顺序查找\n2.排序\n3.二分查找\n4.分块查找\n5.建二叉搜索树\n0.退出\n请选择功能:");
}
int main() {
    printf("查找子系统\n请输入待查找序列的元素个数:");
    int n;cin>>n;
    vector<int> a(n);
    printf("请输入待查找序列的%d个元素:",n);
    for(int i=0;i<n;i++)cin>>a[i];
    int o=-1;
    while(o){
    printf("1.顺序查找\n2.排序\n3.二分查找\n4.分块查找\n5.建二叉搜索树\n0.退出\n请选择功能:");
    cin>>o;
    switch(o){
        case 1:ofind(a);break;
        case 4:
        case 3:if(inorder)tfind(a);else printf("错误:序列不是有序的，请先排序！\n");break;
        case 2:sort(a.begin(),a.end());
            printf("排序成功:排完的序列为:");
            for(int i=0;i<n;i++){cout<<a[i]<<' ';}
            cout<<endl;inorder=true;break;
        case 5:tmenu(a);break;
    }
    }
    return 0;
}