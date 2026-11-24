#include<stdio.h>
#include<string.h>
int main(){
char *m="MFHIKUNOPQZVWXYELARGDSTBC",*t="MUSTSEEYOUOVERCADOGANWESTCOMINGATONCE";
int i=0,a,b;
char x,y;
printf("Cipher: ");
while(t[i]){
x=t[i++];
y=t[i]?t[i]:'X';
if(x==y)y='X';else if(t[i])i++;
a=strchr(m,x)-m;b=strchr(m,y)-m;
if(a/5==b/5)printf("%c%c",m[a/5*5+(a+1)%5],m[b/5*5+(b+1)%5]);
else if(a%5==b%5)printf("%c%c",m[(a+5)%25],m[(b+5)%25]);
else printf("%c%c",m[a/5*5+b%5],m[b/5*5+a%5]);
}
printf("\n");
}
