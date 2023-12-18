// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;cin>>n;
//     int odd=0,even=0;
//     for(int i=1;i<=n;i++){
//         if(i%2)odd+=i;
//         else even+=i;
//     }
//     cout<<even<<' '<<odd<<endl;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;cin>>n;
//     int odd=0,even=0;
//     while(n){
//         if(n%2)odd+=n;
//         else even+=n;
//         n--;
//     }
//     cout<<even<<' '<<odd<<endl;
// }

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int odd=0,even=0;
    for(int i=1;i<=n;i+=2)odd+=i;
    for(int i=2;i<=n;i+=2)even+=i;
    cout<<even<<' '<<odd<<endl;
}