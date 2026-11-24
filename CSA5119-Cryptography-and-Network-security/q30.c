#include<stdio.h>
int E(int k,int x){return((x^k)*7+k)&255;}
int mac(int k,int*m,int n){
int c=0,i;
for(i=0;i<n;i++)c=E(k,m[i]^c);
return c;
}
int main(){
int k=90,x,t,m[2];
printf("One block message X: ");
scanf("%d",&x);
t=mac(k,&x,1);
m[0]=x;m[1]=x^t;
printf("T=MAC(X)=%d\nMAC(X||X^T)=%d\n",t,mac(k,m,2));
}
