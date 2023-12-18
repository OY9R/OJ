/*
    差分约束
    形如 x-y>=c add_e(x,y,-c)
        x-y<=c add_e(y,x,c)
        x-y=0 add_e(a,b,0) add_e(b,a,0)
*/
#include <bits/stdc++.h>
typedef long long ll;
const int N = 2e5 + 100 , M = 2e5 + 100;
const ll INF = (1ll << 31) - 1;
const int MOD = 998244353;
struct{
    int to , next , w;
}e[ M ];
int n , m;
int dis[ N ] , vis[ N ] , cnt[ N ];
int head[ N ] , tot;
void add_e( int x , int y , int w ){
    e[ ++tot ].to = y;
    e[ tot ].next = head[ x ];
    e[ tot ].w = w;
    head[ x ] = tot;
}
bool spfa(){
    dis[ 0 ] = 0;
    for( int i = 1 ; i <= n ; i ++ ) dis[ i ] = INF;
    std::queue< int > q;
    q.push( 0 );
    while( q.size() ){
        int x = q.front();
        q.pop();
        vis[ x ] = 0;
        for( int i = head[ x ] ; i ; i = e[ i ].next ){
            int y = e[ i ].to;
            if( dis[ x ] + e[ i ].w < dis[ y ] ){
                dis[ y ] = dis[ x ] + e[ i ].w;
                if( vis[ y ] == 0 ){
                    vis[ y ] = 1;
                    q.push( y );
                    cnt[ y ]++;
                }
                if( cnt[ y ] > n ) return 0;
            }
        }
    }
    return 1;
}
void solve(){
    std::cin>>n>>m;
    for( int i = 1 ; i <= m ; i ++ ){
        int x , y , w;std::cin>>x>>y>>w;
        add_e( y , x , w );
    }
    for( int i = 1 ; i <= n ; i ++ ){
        add_e( 0 , i , 0 );
    }
    if( !spfa() ) std::cout<<"NO\n";
    else{
        for( int i = 1 ; i <= n ; i ++ ) std::cout<<dis[ i ]<<' ';
    }
}

int main(){
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
    // int t;std::cin>>t;
    // while( t-- )
        solve();
}