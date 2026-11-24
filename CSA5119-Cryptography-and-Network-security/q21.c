#include<stdio.h>
#include<string.h>
int main(){
char m[64];
int n,i,p;
printf("Message: ");
scanf("%s",m);
n=strlen(m);
p=8-n%8;
m[n]=(char)0x80;
for(i=n+1;i<n+p;i++)m[i]=0;
n+=p;
printf("Padded: ");
for(i=0;i<n;i++)printf("%02X ",(unsigned char)m[i]);
for(i=n-1;m[i]==0;i--);
printf("\nUnpadded: %.*s\n",i,m);
}
