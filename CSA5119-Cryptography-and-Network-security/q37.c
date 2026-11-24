#include<stdio.h>
#include<string.h>
int main(){
char s[500],e[27],m[26],o[]="etaoinshrdlcumwfgypbvkjxqz",t;
int c[26]={0},r[26],n,i,j,v;
printf("Cipher (lowercase): ");
scanf("%s",s);
printf("How many top plaintexts: ");
scanf("%d",&n);
for(i=0;s[i];i++)c[s[i]-'a']++;
for(i=0;i<26;i++)r[i]=i;
for(i=0;i<26;i++)for(j=i+1;j<26;j++)if(c[r[j]]>c[r[i]]){v=r[i];r[i]=r[j];r[j]=v;}
for(v=0;v<n&&v<26;v++){
strcpy(e,o);
if(v){t=e[v-1];e[v-1]=e[v];e[v]=t;}
for(i=0;i<26;i++)m[r[i]]=e[i];
printf("%d. ",v+1);
for(i=0;s[i];i++)putchar(m[s[i]-'a']);
printf("\n");
}
}
