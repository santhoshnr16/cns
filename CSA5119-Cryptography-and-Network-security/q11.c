#include<stdio.h>
#include<math.h>
int main(){
double f=1;
int i;
for(i=2;i<=24;i++)f*=i;
printf("Total keys 25! = 2^%.0f\n",log2(f*25));
printf("Effective keys 24! = 2^%.0f\n",log2(f));
}
