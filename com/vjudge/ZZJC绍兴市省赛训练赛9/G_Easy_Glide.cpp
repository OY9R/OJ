#include<bits/stdc++.h>
using namespace std;
#define double long double
const int N=1010;
int n,m;
double g[N][N];
double dist[N];
bool st[N];
double v1,v2;
struct node{
	double x,y;
}Node[N];
void dijkstra()
{
//long double只能精确到小数点后 15位
  for(int i=1;i<=n;i++)dist[i]=2e15;
  dist[1]=0.0;
  for(int i=0;i<n;i++){
    int t=-1;
    for(int j=1;j<=n;j++){
      if(!st[j] && (t==-1 || dist[j]<dist[t]))t=j;
    }

    st[t]=true;
    for(int j=1;j<=n;j++){
      dist[j]=min(dist[j],dist[t]+g[t][j]);
    }
  }
	cout<<fixed<<setprecision(12)<<dist[n]<<endl; 
}

int  main(){
  cin>>n;
  //memset(g,0x3f,sizeof g);
  for(int i=1;i<=n+2;i++){
  	for(int j=1;j<=n+2;j++){
  		g[i][j]=2e15;
	  }
  }
  for(int i=2;i<=n+1;i++){
    int a,b;
    cin>>a>>b;
    Node[i].x=a,Node[i].y=b;
  }
double s1,s2,t1,t2;
  cin>>s1>>s2>>t1>>t2;
  Node[1].x=s1,Node[1].y=s2;
  Node[n+2].x=t1,Node[n+2].y=t2;
  n=n+2;
  cin>>v1>>v2;
   double x1=Node[1].x,y1=Node[1].y;
  for(int i=2;i<=n;i++){
  	double x2=Node[i].x,y2=Node[i].y;
  	double p=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
  	g[1][i]=p/(double)v1;
  }
  for(int i=2;i<=n;i++){
  	x1=Node[i].x,y1=Node[i].y;
  	for(int j=3;j<=n;j++){
  		double x2=Node[j].x,y2=Node[j].y;
  		double p=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
  		double second;
  		if((double)v2*3<p){
  			second=(double)3+(p-(double)v2*3)/v1;
		  }else{
		  	second=p/(double)v2;
		  }
  		g[i][j]=second;
  		g[j][i]=second;
	  }
  }
  dijkstra();
  return 0;
}
