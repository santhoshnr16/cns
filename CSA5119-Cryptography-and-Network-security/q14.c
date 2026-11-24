#include<stdio.h>
int main(){
char *p="sendmoremoney",*q="cashnotneeded",c[14];
int k[]={9,0,1,7,23,15,21,14,11,11,2,8,9},i;
for(i=0;i<13;i++)c[i]=(p[i]-'a'+k[i])%26+'a';
c[13]=0;
printf("Cipher: %s\nKey for cashnotneeded: ",c);
for(i=0;i<13;i++)printf("%d ",(c[i]-q[i]+26)%26);
printf("\n");
}
