#include<stdio.h>
#include<string.h>
#include<ctype.h>
char m[26]="";
int main(){
char k[60],t[100],c,x,y;
int n=0,i,a,b;
printf("Key: ");
scanf("%s",k);
printf("Text: ");
scanf("%s",t);
strcat(k,"ABCDEFGHIKLMNOPQRSTUVWXYZ");
for(i=0;k[i];i++){
c=toupper(k[i]);
if(c=='J')c='I';
if(!strchr(m,c)){m[n++]=c;m[n]=0;}
}
printf("Cipher: ");
for(i=0;t[i];){
x=toupper(t[i++]);
y=t[i]?toupper(t[i]):'X';
if(x=='J')x='I';
if(y=='J')y='I';
if(x==y)y='X';else if(t[i])i++;
a=strchr(m,x)-m;b=strchr(m,y)-m;
if(a/5==b/5)printf("%c%c",m[a/5*5+(a+1)%5],m[b/5*5+(b+1)%5]);
else if(a%5==b%5)printf("%c%c",m[(a+5)%25],m[(b+5)%25]);
else printf("%c%c",m[a/5*5+b%5],m[b/5*5+a%5]);
}
printf("\n");
}
