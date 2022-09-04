#include <bits/stdc++.h>
using namespace std;
bool is_prime(int x){
    if(x<=1)return false;
    for(int i=2;i*i<=x;++i){
        if(x%i==0)return false;
    }
    return true;
}
int main(){
    int N;
    cin>>N;
    bool ans_s=is_prime(N-6);
    bool ans_b=is_prime(N+6);
    if(is_prime(N)&&(ans_s||ans_b)){
        cout<<"Yes"<<endl;
        if(ans_s)cout<<N-6;
        else cout<<N+6;
    }else{
        for(int i=N+1;;++i){
            ans_s=is_prime(i-6);
            ans_b=is_prime(i+6);
            if(is_prime(i)&&(ans_s||ans_b)){
                cout<<"No"<<endl;
                cout<<i;
                return 0;
            }
        }
    }
    return 0;
}