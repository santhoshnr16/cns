#include<stdio.h>
typedef unsigned long long u;
int PC1[]={57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4};
int PC2[]={14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,52,31,37,47,55,30,40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,32};
int R[]={0,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
u perm(u x,int*t,int n,int w){
u r=0;
int i;
for(i=0;i<n;i++)r=r<<1|(x>>(w-t[i]))&1;
return r;
}
int main(){
u k,cd,c,d;
int i;
printf("Key (16 hex digits): ");
scanf("%llx",&k);
cd=perm(k,PC1,56,64);
c=cd>>28;d=cd&0xFFFFFFF;
for(i=0;i<16;i++){
c=(c>>R[i]|c<<(28-R[i]))&0xFFFFFFF;
d=(d>>R[i]|d<<(28-R[i]))&0xFFFFFFF;
printf("Decryption round %d: K%d=%012llX\n",i+1,16-i,perm(c<<28|d,PC2,48,56));
}
}
