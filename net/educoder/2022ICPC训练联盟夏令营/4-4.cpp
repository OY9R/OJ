#include<stdio.h>
int f(int n){
  if(n==1)
    return 1;
  else
    return 2*(f(n-1)+1);
}
int main(){
  int n;
  while(scanf("%d",&n)&&n!=0){
    f(n);
    printf("%d\n",f(n));
    n=0;
  }
  return 0;
}