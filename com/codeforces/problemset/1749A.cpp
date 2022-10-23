#include<bits/stdc++.h>
using namespace std;
int chessboard[10][10];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
        memset(chessboard,0,sizeof chessboard);
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            x--,y--;
            chessboard[x][y]=2;
            for(int i=0;i<n;i++){
                chessboard[i][y]++;
                chessboard[x][i]++;
            }
        }
        bool flag=false;
        for(int i=0;i<n&&!flag;i++){
            for(int j=0;j<n&&!flag;j++){
                if(chessboard[i][j]<=1){
                    cout<<"YES"<<endl;
                    flag=true;
                }
            }
        }
        if(!flag)
		    cout<<"NO"<<endl;
	}
	return 0;
}