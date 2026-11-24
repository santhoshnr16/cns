#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
char s[100];
int i,k[100];
printf("Text (lowercase): ");
scanf("%s",s);
srand(time(0));
printf("Key stream: ");
for(i=0;s[i];i++){k[i]=rand()%26;printf("%d ",k[i]);}
printf("\nCipher: ");
for(i=0;s[i];i++)putchar((s[i]-'a'+k[i])%26+'a');
printf("\n");
}
