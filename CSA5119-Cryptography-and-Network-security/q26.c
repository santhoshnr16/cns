#include<stdio.h>
typedef long long L;
L pw(L b,L e,L n){L r=1;b%=n;while(e){if(e&1)r=r*b%n;b=b*b%n;e>>=1;}return r;}
L gcd(L a,L b){return b?gcd(b,a%b):a;}
int main(){
L n,e,d,r,g,x,y,p;
int t=0,i;
printf("n e d (leaked): ");
scanf("%lld %lld %lld",&n,&e,&d);
r=e*d-1;
while(r%2==0){r/=2;t++;}
for(g=2;g<n;g++){
x=pw(g,r,n);
for(i=0;i<t&&x!=1&&x!=n-1;i++){
y=x*x%n;
if(y==1){
p=gcd(x-1,n);
printf("n factored: p=%lld q=%lld\nNot safe, a new key pair for the same n can be computed\n",p,n/p);
return 0;
}
x=y;
}
}
}
