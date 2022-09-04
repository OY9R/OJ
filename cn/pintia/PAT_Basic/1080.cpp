#include<bits/stdtr1c++.h>
using namespace std;
struct score{
	int Gp,Gm=-1,Gf=-1,G;
};
map<string,score> mp;
bool cmp(pair<string,score> stu1,pair<string,score> stu2){
	return stu1.second.G==stu2.second.G?stu1.first<stu2.first:stu1.second.G>stu2.second.G;
}
int main(){
	int P,M,N;
	scanf("%d %d %d",&P,&M,&N);
	string name;
	int marks;
	for (int i=0;i<P;i++){
		cin>>name>>marks;
		if (marks >= 200)
			mp[name]={marks,-1,-1,0};
	}
	for (int i=0;i<M;i++){
		cin>>name>>marks;
		if (mp.find(name)!=mp.end()) mp[name].Gm=marks;
		else continue;
	}
	for (int i=0;i<N;i++){
		cin>>name>>marks;
		if (mp.find(name)!=mp.end()){
			mp[name].Gf=marks;
			if (mp[name].Gm>mp[name].Gf) mp[name].G=round(mp[name].Gm*0.4+mp[name].Gf*0.6);
			else mp[name].G=mp[name].Gf;
		} else continue;
	}
	vector<pair<string,score>> v(mp.begin(),mp.end());
	sort(v.begin(),v.end(),cmp);
	for (auto y:v)
		if (y.second.G >= 60)
			printf("%s %d %d %d %d\n",y.first.c_str(),y.second.Gp,y.second.Gm,y.second.Gf,y.second.G);
	return 0;
}