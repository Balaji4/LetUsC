#include<stdio.h>
int main()
{
int var = 1;
int cnt = 0; 
int siz; 
while(var) 
{ 
  var<<=1;
  cnt++; 
} 
siz = cnt/8; 
printf("size of integer %d(calulated)\n originally=%d", siz,sizeof(int));
return 0;
}