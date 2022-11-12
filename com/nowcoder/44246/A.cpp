#include<bits/stdc++.h>
using namespace std;
int main(){
    char c;
    cin>>c;
    if(c=='Z'||c=='z'){
        cout<<"non−existent";
    }else{
        cout<<++c;
    }
    return 0;
}