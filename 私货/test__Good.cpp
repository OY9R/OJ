#include<bits/stdc++.h>
using namespace std;
int main() {
std::ios::sync_with_stdio(false);
cin.tie(0);
    string s;
    while(getline(cin,s)&&s[0]!='.'){
        int len=s.size();
        int j=1;
        for(int i=0;i<len;i++){
            if(len%(i+1)==0){
                bool flag=true;
                for(;j<len;j++){
                    if(s[j%(i+1)]!=s[j]){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    cout<<len/(i+1)<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}