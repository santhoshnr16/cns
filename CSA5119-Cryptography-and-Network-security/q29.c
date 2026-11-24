#include<stdio.h>
int main(){
int a[5][5],b[5][5],c[5],d[5],x,y,r=0,z;
for(y=0;y<5;y++)for(x=0;x<5;x++)a[x][y]=y*5+x<16;
do{
for(x=0;x<5;x++){c[x]=0;for(y=0;y<5;y++)c[x]|=a[x][y];}
for(x=0;x<5;x++)d[x]=c[(x+4)%5]|c[(x+1)%5];
for(x=0;x<5;x++)for(y=0;y<5;y++)a[x][y]|=d[x];
for(x=0;x<5;x++)for(y=0;y<5;y++)b[y][(2*x+3*y)%5]=a[x][y];
for(x=0;x<5;x++)for(y=0;y<5;y++)a[x][y]=b[x][y]|b[(x+1)%5][y]|b[(x+2)%5][y];
r++;
for(z=1,x=0;x<5;x++)for(y=0;y<5;y++)z&=a[x][y];
}while(!z);
printf("All capacity lanes nonzero after %d round(s)\n",r);
}
