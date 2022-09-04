#include<stdio.h>
#include<iostream>
using namespace std;
struct Node{
	string name;
	string code;
	int grade;
};
int main()
{
	int n;
	scanf("%d",&n);
	struct Node stu[n];
	int mmax,mmin,tarmax,tarmin;
	for(int i=0;i<n;i++){
		cin>>stu[i].name>>stu[i].code>>stu[i].grade;
		if(i==0){
			mmax=stu[i].grade;
			mmin=stu[i].grade;
			tarmax=tarmin=0;
		}else{
			if(mmax<stu[i].grade){
				mmax=stu[i].grade;
				tarmax=i;
			}
			if(mmin>stu[i].grade){
				mmin=stu[i].grade;
				tarmin=i;
			}
		}
	}	
	cout<<stu[tarmax].name<<" "<<stu[tarmax].code<<endl;
	cout<<stu[tarmin].name<<" "<<stu[tarmin].code<<endl;	
	return 0;
}
