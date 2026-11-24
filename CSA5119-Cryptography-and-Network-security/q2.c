#include<stdio.h>
int main(){
char s[100],k[27];
int i;
printf("Key (26 lowercase letters): ");
scanf("%s",k);
printf("Text (lowercase): ");
scanf(" %[^\n]",s);
for(i=0;s[i];i++)if(s[i]>='a'&&s[i]<='z')s[i]=k[s[i]-'a'];
printf("Cipher: %s\n",s);
}
