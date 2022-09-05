#include<bits/stdc++.h>
using namespace std;
struct User{
    string name;
    string strin;
    string strout;
    int in;
    int out;
};
int main(){
    int n;
    cin>>n;
    struct User users[n];
    for(int i=0;i<n;i++){
        cin>>users[i].name>>users[i].strin>>users[i].strout;
        users[i].in=(users[i].strin[0]*10+users[i].strin[1]-'0'*11)*3600+(users[i].strin[4]*10+users[i].strin[5]-'0'*11)*60+users[i].strin[6]*10+users[i].strin[7]-'0'*11;
        users[i].out=(users[i].strout[0]*10+users[i].strout[1]-'0'*11)*3600+(users[i].strout[4]*10+users[i].strout[5]-'0'*11)*60+users[i].strout[6]*10+users[i].strout[7]-'0'*11;
    }
    int minin=INT_MAX,maxout=0;
    string minid,maxid;
    for(int i=0;i<n;i++){
        if(minin>users[i].in){
            minin=users[i].in;
            minid=users[i].name;
        }
        if(maxout<users[i].out){
            maxout=users[i].out;
            maxid=users[i].name;
        }
    }
    cout<<minid<<' '<<maxid;
    return 0;
}