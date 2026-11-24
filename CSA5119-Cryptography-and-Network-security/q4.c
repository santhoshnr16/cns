#include<stdio.h>
#include<string.h>
int main(){
char s[100],k[50];
int i,j=0;
printf("Text (lowercase): ");
scanf("%s",s);
printf("Key (lowercase): ");
scanf("%s",k);
for(i=0;s[i];i++)s[i]=(s[i]-'a'+k[j++%strlen(k)]-'a')%26+'a';
printf("Cipher: %s\n",s);
}
