#include "bits/stdc++.h"
#define ll long long
using namespace std;
typedef struct student {
	string id;
	int score;
	int operator<(const student &p){
		if(score!=p.score)
			return score>p.score;
		else
			return id<p.id;
	}
}Student;
typedef struct room {
	int roomno;
	int stuno;
	int operator<(const room &r){
		if(stuno!=r.stuno)
			return stuno>r.stuno;
		else
			return roomno<r.roomno;
	}
}Room;
int main(){
	int l,rno,command,score,date,datecount=1,index;
	unsigned int i,j,n,m;
	string id,s;
	cin>>n>>m;
	vector<Student>student[3];
	map<char,int>levelindex={{'T',0},{'A',1},{'B',2}};
	map<int,int>rmcount;
	map<int,int>rmtotalscore;
	map<int,vector<Room>>groupbydate;
	for(i=0;i<n;++i){
		cin>>id>>score;
		student[levelindex[id[0]]].push_back({ id,score });
		rno=stoi(id.substr(1,3));
		date=stoi(id.substr(4,6));
		++rmcount[rno];
		rmtotalscore[rno]+=score;
		for(j=0;j<groupbydate[date].size()&&groupbydate[date][j].roomno!=rno;++j);
		if(j==groupbydate[date].size())
			groupbydate[date].push_back({rno,1});
		else
			++groupbydate[date][j].stuno;
	}
	for(i=0;i<3;++i)
		sort(student[i].begin(),student[i].end());
	for(i=0;i<m;++i){
		cin>>command>>s;
		printf("Case %d: %d %s\n",i+1,command,s.c_str());
		if(command==1){
			index=levelindex[s[0]];
			if(student[index].size()==0)
				printf("NA\n");
			else
				for(l=0;l<student[index].size();++l)
					printf("%s %d\n",student[index][l].id.c_str(),student[index][l].score);
		}else if(command==2){
			rno=stoi(s);
			if(rmcount[rno]==0)
				cout<<"NA"<<endl;
			else
				printf("%d %d\n",rmcount[rno],rmtotalscore[rno]);
		}else if(command ==3){
			date=stoi(s);
			if(groupbydate[date].size()==0)
				cout<<"NA"<<endl;
			else{
				sort(groupbydate[date].begin(),groupbydate[date].end());
				for(j=0;j<groupbydate[date].size();++j)
					printf("%d %d\n",groupbydate[date][j].roomno,groupbydate[date][j].stuno);
			}
		}
	}
	return 0;
}