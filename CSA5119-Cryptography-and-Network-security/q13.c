#include<stdio.h>
int main(){
char p[5],c[5];
int P[4],C[4],q[4],i,d,e;
printf("Plaintext (4 letters): ");
scanf("%s",p);
printf("Ciphertext (4 letters): ");
scanf("%s",c);
for(i=0;i<4;i++){P[i]=p[i]-'a';C[i]=c[i]-'a';}
d=((P[0]*P[3]-P[1]*P[2])%26+26)%26;
for(e=1;e<26&&d*e%26!=1;e++);
if(e==26){printf("Plaintext matrix not invertible\n");return 0;}
q[0]=P[3]*e%26;q[1]=(26-P[2])*e%26;q[2]=(26-P[1])*e%26;q[3]=P[0]*e%26;
printf("Key:\n%d %d\n%d %d\n",(C[0]*q[0]+C[2]*q[2])%26,(C[0]*q[1]+C[2]*q[3])%26,(C[1]*q[0]+C[3]*q[2])%26,(C[1]*q[1]+C[3]*q[3])%26);
}
