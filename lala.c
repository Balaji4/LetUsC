#include <stdio.h>

void f1(int*, int);
void f2(int*, int);
void (*p[2])(int*, int);

int main(void)
{
   int a = 3;
   int b = 5;

   p[0] = f1;
   p[1] = f2;

   p[0](&a, b);
   printf("%d %d ", a, b);

   p[1](&a, b);
   printf("%d %d\n", a, b);

   return 0;
}

void f1(int *p, int q)
{
   int tmp = *p;
   *p = q;
   q = tmp;
}

void f2(int *p, int q)
{
   int tmp = *p;
   *p = q;
   q = tmp;
}