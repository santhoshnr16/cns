#include<stdio.h>
typedef unsigned long long u;
u dbl(u l){return(l<<1)^((l>>63)?0x1B:0);}
int main(){
u l;
printf("L = E(K,0) (16 hex digits): ");
scanf("%llx",&l);
printf("Constants: 64-bit block=0x1B, 128-bit block=0x87\n");
printf("K1=%016llX\nK2=%016llX\n",dbl(l),dbl(dbl(l)));
}
