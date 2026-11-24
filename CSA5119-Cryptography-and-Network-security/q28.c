#include<stdio.h>
int pw(int b,int e,int q){int r=1;b%=q;while(e){if(e&1)r=r*b%q;b=b*b%q;e>>=1;}return r;}
int main(){
int q=23,a=5,xa=6,xb=15,ya,yb,ai;
ya=pw(xa,a,q);yb=pw(xb,a,q);
for(ai=1;a*ai%(q-1)!=1;ai++);
printf("Sent values: %d %d\n",ya,yb);
printf("Alice key (xa*xb): %d\n",xa*pw(yb,ai,q)%q);
printf("Bob key (xa*xb): %d\n",xb*pw(ya,ai,q)%q);
printf("Eve finds secrets: %d %d\n",pw(ya,ai,q),pw(yb,ai,q));
printf("Eve key: %d\n",pw(ya,ai,q)*pw(yb,ai,q)%q);
}
