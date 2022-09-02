#include<bits/stdc++.h>
using namespace std;
vector<long> result[10001];
long ia[100001],it[100001];
long start,N,K,len,num;
int main(){
    cin>>start>>N>>K;
    while(N--)
        cin>>num>>ia[num]>>it[num];
    while(start!=-1){
        if(result[len].size()==K)len++;
        result[len].push_back(start);
        start=it[start];
    }
    printf("%05ld %ld ",result[len].front(),ia[result[len].front()]);
    result[len].erase(result[len].begin());
    for(int i=len;i>=0;i--)
        for(long x:result[i])
            printf("%05ld\n%05ld %ld ",x,x,ia[x]);
    printf("-1");
    return 0;
}