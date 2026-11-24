#include<stdio.h>
int PC1[]={57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4};
int PC2[]={14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,52,31,37,47,55,30,40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,32};
int main(){
int a[65]={0},b[65]={0},i,ok=1;
for(i=0;i<24;i++){
if(PC2[i]>28)ok=0;
a[PC1[PC2[i]-1]]=1;
}
for(i=24;i<48;i++){
if(PC2[i]<=28)ok=0;
b[PC1[PC2[i]-1]]=1;
}
printf("First 24 bits of each subkey come from key bits:\n");
for(i=1;i<=64;i++)if(a[i])printf("%d ",i);
printf("\nSecond 24 bits of each subkey come from key bits:\n");
for(i=1;i<=64;i++)if(b[i])printf("%d ",i);
for(i=1;i<=64;i++)if(a[i]&&b[i])ok=0;
printf("\nFirst half from C, second half from D, subsets disjoint: %s\n",ok?"yes":"no");
}
