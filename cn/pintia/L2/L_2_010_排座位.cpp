#include<bits/stdc++.h>
using namespace std;
int fir[105];
int fiat[105][105];
int find(int x){
    if(fir[x]==x) return x;
    else return fir[x]=find(fir[x]);
}
int meg(int x,int y){
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy){
        fir[fx]=fy;
        return 1;
    }
    return 0;
}
int main(){
	int n,m,k;cin>>n>>m>>k;
    for(int i=1;i<=n;i++)fir[i]=i;
    for(int i=1;i<=m;i++){
        int a,b,c;cin>>a>>b>>c;
        if(~c)meg(a,b);
        else fiat[a][b]=fiat[b][a]=1;
    }
    for(int i=1;i<=k;i++){
        int a,b;cin>>a>>b;
        if(find(a)==find(b)){
            if(!fiat[a][b])cout<<"No problem"<<endl;
            else cout<<"OK but..."<<endl;
        }else{
            if(fiat[a][b])cout<<"No way"<<endl;
            else cout<<"OK"<<endl;
        }
    }
	return 0;
}