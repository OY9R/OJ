#include<bits/stdc++.h>
using namespace std;
map<int,int> ne,vs,vi;
int main(){
    int h,n;cin>>h>>n;
    for(int i=0;i<n;i++){
        int addr,value,next;
        cin>>addr>>value>>next;
        ne[addr]=next,vs[addr]=value;
    }
    vector<int> tmp;
    for(int i=h,j=0;~i;i=ne[i]){
        vi[abs(vs[i])]++;
        if(vi[abs(vs[i])]==1){
            if(j)printf(" %05d\n",i);
            printf("%05d %d",i,vs[i]);
            j++;
        }else{
            tmp.push_back(i);
        }
    }
    cout<<" -1\n";
    for(int i=0;i<tmp.size();i++){
        if(i)printf(" %05d\n",tmp[i]);
        printf("%05d %d",tmp[i],vs[tmp[i]]);
    }
    if(tmp.size())cout<<" -1\n";
}