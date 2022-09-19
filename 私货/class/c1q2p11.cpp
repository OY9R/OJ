#include<stdio.h>
void fun(float *p,float *q,float *s){
	float k;
	if(*p<*q){
		k=*p;
		*p=*q;
		*q=k;
	}
	if(*p<*s){
		k=*s;
		*s=*p;
		*p=k;
	}
	if(*q<*s){
		k=*q;
		*q=*s;
		*s=k;
	}
}
int main(){
	float a,b,c;
	printf("请输入三个小数 (a b c): ");
	scanf("%f%f%f",&a,&b,&c);
	printf("这三个小数是: a=%4.1f b=%4.1f c=%4.1f\n",a,b,c);
	fun(&a,&b,&c);
	printf("排序后这三个小数是: a=%4.1f b=%4.1f c=%4.1f\n",a,b,c);
	return 0;
}
