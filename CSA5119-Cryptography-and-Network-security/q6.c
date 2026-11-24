#include<stdio.h>
int main(){
int a,b;
for(a=1;a<26;a++)for(b=0;b<26;b++)
if((4*a+b)%26==1&&(19*a+b)%26==20)printf("a=%d b=%d\n",a,b);
}
