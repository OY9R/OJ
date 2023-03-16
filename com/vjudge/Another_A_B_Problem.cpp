#include<bits/stdc++.h>
using namespace std;
bool g[8][10];
int m[10];
int main(){
    fill(g[0],g[0]+sizeof g,true);
    string s,ss;cin>>s>>ss;
    vector<int> p;
    for(int i=0;i<8;i++){
        if(i%3==2)continue;
        if(ss[i]=='G'){
            fill(g[i],g[i]+10,false);
            g[i][s[i]-'0']=true;
        }else g[i][s[i]-'0']=false;
    }
    for(int i=0;i<8;i++){
        if(i%3==2)continue;
        if(ss[i]=='B')m[s[i]-'0']=min(~m[s[i]-'0'],m[s[i]-'0']);
        else if(m[s[i]-'0']<0)m[s[i]-'0']--;
        else m[s[i]-'0']++;
    }
    int tmp[10];
//     for(int i=0;i<10;i++)cout<<m[i];
    vector<pair<int,int> > ans;
    for(int i=0;i<=99;i++)
        for(int j=0;i+j<=99;j++){
            if(!g[0][i/10]||!g[1][i%10]||!g[3][j/10]||!g[4][j%10]||!g[6][(i+j)/10]|!g[7][(i+j)%10])continue;
            memset(tmp,0,sizeof tmp);
            tmp[i/10]++,tmp[i%10]++,tmp[j/10]++,tmp[j%10]++,tmp[(i+j)/10]++,tmp[(i+j)%10]++;
            bool flag=true;
            for(int i=0;i<10;i++)
                if(m[i]<0&&tmp[i]!=~m[i]||m[i]>=0&&tmp[i]<m[i]){flag=false;break;}
            if(flag) ans.push_back({i,j});
        }
    cout<<ans.size()<<endl;
    for(auto i:ans)printf("%02d+%02d=%02d\n",i.first,i.second,i.first+i.second);
}