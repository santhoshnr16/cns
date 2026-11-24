#include<stdio.h>
#include<string.h>
int main(){
char s[]="meetmeattheusualplaceattenratherthaneightoclockx",c[60];
int k[2][2]={{9,4},{5,7}},v[2][2],d,i,n=strlen(s),a,b;
for(i=0;i<n;i+=2){
a=s[i]-'a';b=s[i+1]-'a';
c[i]=(k[0][0]*a+k[0][1]*b)%26+'a';
c[i+1]=(k[1][0]*a+k[1][1]*b)%26+'a';
printf("%c%c (%d,%d) -> %c%c\n",s[i],s[i+1],a,b,c[i],c[i+1]);
}
c[n]=0;
printf("Cipher: %s\n",c);
d=(k[0][0]*k[1][1]-k[0][1]*k[1][0])%26;
for(i=1;d*i%26!=1;i++);
v[0][0]=k[1][1]*i%26;v[0][1]=(26-k[0][1])*i%26;
v[1][0]=(26-k[1][0])*i%26;v[1][1]=k[0][0]*i%26;
printf("det=%d inverse of det=%d\n",d,i);
printf("Inverse key: %d %d / %d %d\n",v[0][0],v[0][1],v[1][0],v[1][1]);
printf("Decrypted: ");
for(i=0;i<n;i+=2){
a=c[i]-'a';b=c[i+1]-'a';
printf("%c%c",(v[0][0]*a+v[0][1]*b)%26+'a',(v[1][0]*a+v[1][1]*b)%26+'a');
}
printf("\n");
}
