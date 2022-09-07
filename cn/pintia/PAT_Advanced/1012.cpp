#include<bits/stdc++.h>
using namespace std;
struct Student {
	int c=-1,m,e,a;
	int ci,mi,ei,ai;
} stus[1000000];
int cr[2000],mr[2000],er[2000],ar[2000];
bool cmpa(int a,int b) {
	return stus[a].a>stus[b].a;
}
bool cmpe(int a,int b) {
	if(stus[a].e==stus[b].e)
		return cmpa(a,b);
	return stus[a].e>stus[b].e;
}
bool cmpm(int a,int b) {
	if(stus[a].m==stus[b].m)
		return cmpe(a,b);
	return stus[a].m>stus[b].m;
}
bool cmpc(int a,int b) {
	if(stus[a].c==stus[b].c)
		return cmpm(a,b);
	return stus[a].c>stus[b].c;
}
int main() {
	int n,m;
	cin>>n>>m;
	for(int i=0; i<n; i++) {
		int id;
		cin>>id;
		cin>>stus[id].c>>stus[id].m>>stus[id].e;
		stus[id].a=(stus[id].c+stus[id].m+stus[id].e)/3;
		cr[i]=mr[i]=er[i]=ar[i]=id;
	}
	stable_sort(cr,cr+n,cmpc);
	for(int i=0; i<n; i++)
		stus[cr[i]].ci=i+1;
	stable_sort(mr,mr+n,cmpm);
	for(int i=0; i<n; i++)
		stus[mr[i]].mi=i+1;
	stable_sort(er,er+n,cmpe);
	for(int i=0; i<n; i++)
		stus[er[i]].ei=i+1;
	stable_sort(ar,ar+n,cmpa);
	for(int i=0; i<n; i++)
		stus[ar[i]].ai=i+1;
	while(m--) {
		int k;
		cin>>k;
		if(stus[k].c==-1)
			cout<<"N/A"<<endl;
		else {
			int f=min(min(stus[k].ci,stus[k].mi),min(stus[k].ei,stus[k].ai));
			if(stus[k].ai==f)
				cout<<f<<" A\n";
			else if(stus[k].ci==f)
				cout<<f<<" C\n";
			else if(stus[k].mi==f)
				cout<<f<<" M\n";
			else //(stus[k].ei==f)
				cout<<f<<" E\n";
		}
	}
	return 0;
}