#include<stdio.h>
typedef long long L;
L gcd(L a,L b){return b?gcd(b,a%b):a;}
L inv(L e,L f){
L r0=f,r1=e,t0=0,t1=1,q,t;
while(r1){
q=r0/r1;
t=r0-q*r1;r0=r1;r1=t;
t=t0-q*t1;t0=t1;t1=t;
}
return(t0%f+f)%f;
}
int main(){
L n,e,c,g;
int m,i;
printf("n e: ");
scanf("%lld %lld",&n,&e);
printf("Number of ciphertext blocks: ");
scanf("%d",&m);
printf("Blocks: ");
for(i=0;i<m;i++){
scanf("%lld",&c);
g=gcd(c,n);
if(g>1&&g<n){
printf("n factored: p=%lld q=%lld\nPrivate key d=%lld\n",g,n/g,inv(e,(g-1)*(n/g-1)));
return 0;
}
}
printf("No common factor found\n");
}
