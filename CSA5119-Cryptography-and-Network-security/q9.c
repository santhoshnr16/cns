#include<stdio.h>
#include<string.h>
int main(){
char m[26]="",*k="ROYALNEWZEALANDNAVYABCDEFGHIKLMNOPQRSTUVWXYZ";
char *c="KXJEYUREBEZWEHEWRYTUHEYFSKREHEGOYFIWTTTUOLKSYCAJPOBOTEIZONTXBYBNTGONEYCUZWRGDSONSXBOUYWRHEBAAHYUSEDQ";
int n=0,i,a,b;
char x,y;
for(i=0;k[i];i++)if(!strchr(m,k[i])){m[n++]=k[i];m[n]=0;}
for(i=0;c[i];i+=2){
x=c[i]=='J'?'I':c[i];
y=c[i+1]=='J'?'I':c[i+1];
a=strchr(m,x)-m;b=strchr(m,y)-m;
if(a/5==b/5)printf("%c%c",m[a/5*5+(a+4)%5],m[b/5*5+(b+4)%5]);
else if(a%5==b%5)printf("%c%c",m[(a+20)%25],m[(b+20)%25]);
else printf("%c%c",m[a/5*5+b%5],m[b/5*5+a%5]);
}
printf("\n");
}
