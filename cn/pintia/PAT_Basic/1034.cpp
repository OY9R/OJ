#include "bits/stdc++.h"
#define ll long long
using namespace std;
ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}
class fraction{
private:
	ll mol,den;
	ll integer=0;
	bool judge=true;
	bool legal;
public:
	fraction(ll a,ll b){
		legal=b!=0;
		mol=a;den=b;
		if(legal)reduction();
	};
    void reduction(){
    	mol+=integer*den;
    	if(mol<0){
    		judge=!judge;
    		mol=-mol;
    	}
    	ll g=gcd(mol,den);
		integer=mol/den;
		mol=(mol%den)/g;
		den=den/g;
    } 
	void print(){
		if(!legal)cout<<"Inf";
		else if(mol==0&&integer==0)cout<<0;
		else{
			if(!judge)cout<<"(-";
			if(integer!=0)cout<<integer;
			if(integer!=0&&mol!=0)cout<<' ';
			if(mol!=0)cout<<mol<<'/'<<den;
			if(!judge)cout<<')';
		}
	};
	fraction add(fraction a){
		ll m=(mol+integer*den)*a.den*(judge*2-1);
		m+=(a.mol+a.integer*a.den)*den*(a.judge*2-1);
		ll d=den*a.den;
		fraction tmp(m,d);
		return tmp;
	};
	fraction sub(fraction a){
		ll m=(mol+integer*den)*a.den*(judge*2-1);
		m-=(a.mol+a.integer*a.den)*den*(a.judge*2-1);
		ll d=den*a.den;
		fraction tmp(m,d);
		return tmp;
	};
	fraction mul(fraction a){
		ll m=(mol+integer*den)*(a.mol+a.integer*a.den);
		m*=(judge*2-1)*(a.judge*2-1);
		ll d=den*a.den;
		fraction tmp(m,d);
		return tmp;
	};
	fraction div(fraction a){
		if(a.mol+a.integer==0){
			fraction tmp(1,0);
			return tmp;
		}
		ll m=(mol+integer*den)*a.den;
		m*=(judge*2-1)*(a.judge*2-1);
		ll d=den*(a.mol+a.integer*a.den);
		fraction tmp(m,d);
		return tmp;
	};
};
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll a1,b1,a2,b2;
	scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
	fraction a(a1,b1);
	fraction b(a2,b2);
	a.print();cout<<" + ";b.print();cout<<" = ";a.add(b).print();cout<<endl;
	a.print();cout<<" - ";b.print();cout<<" = ";a.sub(b).print();cout<<endl;
	a.print();cout<<" * ";b.print();cout<<" = ";a.mul(b).print();cout<<endl;
	a.print();cout<<" / ";b.print();cout<<" = ";a.div(b).print();cout<<endl;
	return 0;
}
