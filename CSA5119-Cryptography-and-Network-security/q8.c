#include<stdio.h>
int main(){
char k[30],t[100],m[27],u[26]={0};
int n=0,i;
printf("Keyword (lowercase): ");
scanf("%s",k);
printf("Text (lowercase): ");
scanf("%s",t);
for(i=0;k[i];i++)if(!u[k[i]-'a']){u[k[i]-'a']=1;m[n++]=k[i];}
for(i=0;i<26;i++)if(!u[i])m[n++]='a'+i;
m[n]=0;
printf("Cipher alphabet: %s\n",m);
for(i=0;t[i];i++)t[i]=m[t[i]-'a'];
printf("Cipher: %s\n",t);
}
