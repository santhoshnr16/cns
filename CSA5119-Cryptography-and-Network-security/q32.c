#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int pw(int b,int e,int m){int r=1;while(e--)r=r*b%m;return r;}
int inv(int a,int m){int i;for(i=1;i<m;i++)if(a*i%m==1)return i;return 0;}
int main(){
int p=23,q=11,g=4,x=3,h=5,n=3599,d=3031,i,k,r,s;
srand(time(0));
for(i=0;i<2;i++){
do{
k=rand()%(q-1)+1;
r=pw(g,k,p)%q;
s=inv(k,q)*(h+x*r)%q;
}while(!r||!s);
printf("DSA signature of same message: k=%d r=%d s=%d\n",k,r,s);
}
for(i=0;i<2;i++)printf("RSA signature of same message: %d\n",pw(h,d,n));
}
