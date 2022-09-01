#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
int n,up[maxn],down[maxn];
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>up[i];
    for(int i=0;i<n;i++)
        cin>>down[i];
    int button=*min_element(up,up+n);
    int top=*max_element(down,down+n);
    if(button>top)
        printf("Yes %d",button-top);
    else
        printf("No %d",abs(button-top)+1); 
    return 0;
}