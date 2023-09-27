#include<bits/stdc++.h>
using namespace std;
map<string,long long>pc;
bool bs(string a,string b){
	if(a.size()>b.size())
	return true;
	if(a.size()<b.size())
	return false;
	long long i;
	for(i=0;i<a.size();i++)
	{
		if(a[i]>b[i])
		return true;
		if(a[i]<b[i])
		return false;
	}
	return false;
}
bool pd(string y){
	string a;
	long long i=0;
	a="";
	for(;i<y.size();i++)
	{
		if(y[i]>='0'&&y[i]<='9')
		{
			a=a+y[i];
			if(a=="0"&&(!(y[i+1]=='.')))
			return false; 
		}
		if(y[i]=='.')
		{
			if(bs(a,"255"))
			return false;
			break;
		}
	}
	if(a=="")
	return false;
	a="";
	for(i++;i<y.size();i++)
	{
		if(y[i]>='0'&&y[i]<='9')
		{
			a=a+y[i];
			if(a=="0"&&(!(y[i+1]=='.')))
			return false; 
		}
		if(y[i]=='.')
		{
			if(bs(a,"255"))
			return false;
			break;
		}
	}
	if(a=="")
	return false;
	a="";
	for(i++;i<y.size();i++)
	{
		if(y[i]>='0'&&y[i]<='9')
		{
			a=a+y[i];
			if(a=="0"&&(!(y[i+1]=='.')))
			return false; 
		}
		if(y[i]=='.')
		{
			if(bs(a,"255"))
			return false;
			break;
		}
	}
	if(a=="")
	return false;
	a="";
	for(i++;i<y.size();i++)
	{
		if(y[i]>='0'&&y[i]<='9')
		{
			a=a+y[i];
			if(a=="0"&&(!(y[i+1]==':')))
			return false; 
		}
		if(y[i]==':')
		{
			if(bs(a,"255"))
			return false;
			break;
		}
	}
	if(a=="")
	return false;
	a="";
	for(i++;i<y.size();i++)
	{
		if(y[i]>='0'&&y[i]<='9')
		{
			a=a+y[i];
			if(a=="0"&&(!(i+1!=y.size())))
			return false; 
		}
	}
	if(a=="")
	return false;
	if(bs(a,"65535"))
	return false;
	return true;
}
int main(){

	long long n,i=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		string a,b;
		cin>>a>>b;
		if(pd(b)==false)
		{
			cout<<"ERR\n";
			continue;
		}
		if(a[0]=='S')
		{
			if(pc[b]==0)
			{
				pc[b]=i;
				cout<<"OK\n";
			}
			else
			cout<<"FAIL\n"; 
		}
		else if(a[0]=='C')
		{
			if(pc[b]!=0)
			cout<<pc[b]<<"\n";
			else
			cout<<"FAIL\n";
		}
	}

	return 0;
}