#include<stdio.h>
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
int a,b,i;
char s[100];
printf("Allowed a: ");
for(i=1;i<26;i++)if(gcd(i,26)==1)printf("%d ",i);
printf("\nb can be any value from 0 to 25\n");
printf("Enter a b text: ");
scanf("%d %d %s",&a,&b,s);
if(gcd(a,26)!=1){printf("a is not allowed\n");return 0;}
for(i=0;s[i];i++)s[i]=(a*(s[i]-'a')+b)%26+'a';
printf("Cipher: %s\n",s);
}
