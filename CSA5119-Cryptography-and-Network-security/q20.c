#include<stdio.h>
int k=90,iv=77;
int E(int x){return((x^k)*7+k)&255;}
int D(int y){return(((y-k)*183)&255)^k;}
void enc(int*p,int*c,int n){int i,v=iv;for(i=0;i<n;i++)v=c[i]=E(p[i]^v);}
void dec(int*c,int*p,int n){int i,v=iv;for(i=0;i<n;i++){p[i]=D(c[i])^v;v=c[i];}}
void show(char*s,int*a){int i;printf("%s",s);for(i=0;i<4;i++)printf("%5d",a[i]);printf("\n");}
int main(){
int p[4]={10,20,30,40},p2[4]={10,20,30,40},c[4],e[4],q[4],i;
enc(p,c,4);dec(c,q,4);
show("P:               ",p);show("C:               ",c);show("Decrypted:       ",q);
for(i=0;i<4;i++)e[i]=c[i];
e[0]^=1;dec(e,q,4);
show("Error in C1 -> P:",q);
p2[0]^=1;enc(p2,e,4);
show("Error in P1 -> C:",e);
dec(e,q,4);
show("Receiver gets P: ",q);
}
