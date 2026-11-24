#include<stdio.h>
int main(){
int e=31,n=3599,p,q,f,d,r0,r1,t0=0,t1=1,t,x;
for(p=2;n%p;p++);
q=n/p;f=(p-1)*(q-1);
r0=f;r1=e;
while(r1){
x=r0/r1;
t=r0-x*r1;r0=r1;r1=t;
t=t0-x*t1;t0=t1;t1=t;
}
d=(t0%f+f)%f;
printf("p=%d q=%d phi=%d\nPrivate key d=%d\n",p,q,f,d);
}
