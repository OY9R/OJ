//ащЪ§
#include<bits/stdc++.h>
using namespace std;using ll=long long;const int M=998244353;const double eps=1e-10,inf=1e30;
struct Im_num
{
	double re,im;void ini(double y,double x){re=y,im=x;}
	Im_num(double y=0,double x=0){ini(y,x);}
	void outp(){cout<<re<<"|"<<im<<'\n';}
};
Im_num add(Im_num a,Im_num b){return Im_num(a.re+b.re,a.im+b.im);}
Im_num sub(Im_num a,Im_num b){return Im_num(a.re-b.re,a.im-b.im);}
Im_num mul(Im_num a,Im_num b){return Im_num(a.re*b.re-a.im*b.im,a.re*b.im+a.im*b.re);}
double mol(Im_num a){return a.re*a.re+a.im*a.im; }
Im_num inv(Im_num a){double L=mol(a);return Im_num(a.re/L,-a.im/L);}
Im_num div(Im_num a,Im_num b){return mul(a,inv(b));}