#include<bits/stdc++.h>
using namespace std;
int rate[25];
typedef struct Phone {
	string name;
	int M,d,H,m,t;
	bool on;
};
bool cmp(Phone a,Phone b){
	if(a.name==b.name)
		return a.t<b.t;
	return a.name<b.name;
}
 
double billfromzero(Phone call) {
    double tot=rate[call.H]*call.m+rate[24]*60*call.d;
    for (int i=0;i<call.H;i++) {
        tot+=rate[i]*60;
    }
    tot/=100.0;
    return tot;
}

int main() {
	for(int i=0;i<24;i++){
		cin>>rate[i];
		rate[24]+=rate[i];
	}
	int n;
	cin>>n;
	vector<Phone> p(n);
	for(int i=0;i<n;i++){
		string s;
		cin>>p[i].name;
		scanf("%d:%d:%d:%d",&p[i].M,&p[i].d,&p[i].H,&p[i].m);
		p[i].t=(p[i].d*24+p[i].H)*60+p[i].m;
		cin>>s;
		p[i].on=s=="on-line";
	}
	sort(p.begin(),p.end(),cmp);
	map<string,vector<Phone>> m;
	for(int i=0;i<n;i++){
		if(p[i].name==p[i-1].name&&p[i-1].on&&!p[i].on){
			m[p[i].name].push_back(p[i-1]);
			m[p[i].name].push_back(p[i]);
		}
	}
	for(auto it:m){
		auto tmp=it.second;
		cout<<it.first;
		printf(" %02d\n",tmp[0].M);
		double pay=0;
		for(int i=1;i<tmp.size();i+=2){
			double $=billfromzero(tmp[i])-billfromzero(tmp[i-1]);
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",tmp[i-1].d,tmp[i-1].H,tmp[i-1].m,tmp[i].d,tmp[i].H,tmp[i].m,tmp[i].t-tmp[i-1].t,$);
			pay+=$;
		}
		printf("Total amount: $%.2lf\n",pay);
	}
	return 0;

}