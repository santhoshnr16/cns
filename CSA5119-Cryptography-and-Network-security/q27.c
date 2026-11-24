#include<stdio.h>
typedef long long L;
L pw(L b,L e,L n){L r=1;b%=n;while(e){if(e&1)r=r*b%n;b=b*b%n;e>>=1;}return r;}
int main(){
L n=3599,e=31,t[26],c[100];
char s[100];
int i,j;
printf("Message (A-Z): ");
scanf("%s",s);
for(i=0;i<26;i++)t[i]=pw(i,e,n);
for(i=0;s[i];i++)c[i]=pw(s[i]-'A',e,n);
printf("Cipher: ");
for(i=0;s[i];i++)printf("%lld ",c[i]);
printf("\nAttack (encrypt all 26 letters and match): ");
for(i=0;s[i];i++)for(j=0;j<26;j++)if(t[j]==c[i])putchar('A'+j);
printf("\nNot secure\n");
}
