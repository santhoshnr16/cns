#include<stdio.h>
double f[]={8.2,1.5,2.8,4.3,12.7,2.2,2.0,6.1,7.0,0.15,0.77,4.0,2.4,6.7,7.5,1.9,0.095,6.0,6.3,9.1,2.8,0.98,2.4,0.15,2.0,0.074};
int main(){
char s[200],t[200];
int n,i,j,k,x,o[26];
double sc[26];
printf("Cipher (lowercase): ");
scanf("%s",s);
printf("How many top plaintexts: ");
scanf("%d",&n);
for(k=0;k<26;k++){
sc[k]=0;o[k]=k;
for(i=0;s[i];i++)sc[k]+=f[(s[i]-'a'-k+26)%26];
}
for(i=0;i<26;i++)for(j=i+1;j<26;j++)if(sc[o[j]]>sc[o[i]]){x=o[i];o[i]=o[j];o[j]=x;}
for(i=0;i<n&&i<26;i++){
k=o[i];
for(j=0;s[j];j++)t[j]=(s[j]-'a'-k+26)%26+'a';
t[j]=0;
printf("%d. key=%d %s\n",i+1,k,t);
}
}
