#include "bits/stdc++.h"
using namespace std;
struct Node{
	double num;
	double pri;
	double perpri;
};
struct Node nodes[1005];
int N,D;
bool cmp(struct Node a,struct Node b)
{
	return a.perpri>b.perpri;
}
int main()
{
	double ans=0.0;
	scanf("%d %d",&N,&D);
	for(int i=0;i<N;i++)
		scanf("%lf",&nodes[i].num);
	for(int i=0;i<N;i++)
	{
		scanf("%lf",&nodes[i].pri);
		nodes[i].perpri=1.0*nodes[i].pri/nodes[i].num;
	}
	sort(nodes,nodes+N,cmp);
	for(int i=0;i<N;i++)
	{
		if(D>=nodes[i].num)
		{
			D-=nodes[i].num;
			ans+=1.0*nodes[i].pri;
		}
		else
		{
			ans+=1.0*D/nodes[i].num*nodes[i].pri;
			break;
		}
	}	
	printf("%.2lf\n",ans);
	return 0;
} 
