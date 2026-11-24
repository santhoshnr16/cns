#include<stdio.h>
#include<string.h>
int P10[]={3,5,2,7,4,10,1,9,8,6},P8[]={6,3,7,4,8,5,10,9},IP[]={2,6,3,1,4,8,5,7},FP[]={4,1,3,5,7,2,8,6},EP[]={4,1,2,3,2,3,4,1},P4[]={2,4,3,1};
int S0[4][4]={{1,0,3,2},{3,2,1,0},{0,2,1,3},{3,1,3,2}},S1[4][4]={{0,1,2,3},{2,0,1,3},{3,0,1,0},{2,1,0,3}};
int k1[8],k2[8];
void perm(int*o,int*i,int*t,int n){
int r[10],j;
for(j=0;j<n;j++)r[j]=i[t[j]-1];
for(j=0;j<n;j++)o[j]=r[j];
}
void ls(int*a,int n){
int t=a[0],j;
for(j=0;j<n-1;j++)a[j]=a[j+1];
a[n-1]=t;
}
void keys(int*k){
int a[10];
perm(a,k,P10,10);
ls(a,5);ls(a+5,5);
perm(k1,a,P8,8);
ls(a,5);ls(a,5);ls(a+5,5);ls(a+5,5);
perm(k2,a,P8,8);
}
void fk(int*b,int*k){
int e[8],s[4],r[4],i,u,v;
perm(e,b+4,EP,8);
for(i=0;i<8;i++)e[i]^=k[i];
u=S0[e[0]*2+e[3]][e[1]*2+e[2]];
v=S1[e[4]*2+e[7]][e[5]*2+e[6]];
s[0]=u>>1;s[1]=u&1;s[2]=v>>1;s[3]=v&1;
perm(r,s,P4,4);
for(i=0;i<4;i++)b[i]^=r[i];
}
void run(int*b,int*ka,int*kb){
int i,t;
perm(b,b,IP,8);
fk(b,ka);
for(i=0;i<4;i++){t=b[i];b[i]=b[i+4];b[i+4]=t;}
fk(b,kb);
perm(b,b,FP,8);
}
void go(char*p,char*o,char*iv){
int c[8],b[8],i,j,n=strlen(p);
for(i=0;i<8;i++)c[i]=iv[i]-'0';
for(i=0;i<n;i+=8){
for(j=0;j<8;j++)b[j]=c[j];
run(b,k1,k2);
for(j=0;j<8;j++)o[i+j]='0'+((p[i+j]-'0')^b[j]);
for(j=7;j>=0&&!(c[j]^=1);j--);
}
o[n]=0;
}
int main(){
char kk[11],iv[9],p[100],o[100],d[100];
int k[10],i;
printf("Key (10 bits): ");
scanf("%s",kk);
printf("Counter (8 bits): ");
scanf("%s",iv);
printf("Plaintext bits: ");
scanf("%s",p);
for(i=0;i<10;i++)k[i]=kk[i]-'0';
keys(k);
go(p,o,iv);
printf("Cipher: %s\n",o);
go(o,d,iv);
printf("Decrypted: %s\n",d);
}
