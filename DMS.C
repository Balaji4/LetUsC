#include<stdio.h>
#include<conio.h>

static int check1=0,check2=0,check3=0,check4=0;
char *result;

int AND(int a,int b)
{
    if(a&&b)
    return 1;
    else return 0;
}

int OR(int a,int b)
{
    if(a||b)
    return 1;
    else return 0;
}

int XOR(int a,int b)
{
    if(a!=b)
    return 1;
    else return 0;
}

int NOT(int a)
{
    return !a;
}

int CON(int a,int b)
{
    if(a&&!b)return 0;
    else return 1;
}

int BICON(int a,int b)
{
    if(a==b) return 1;
    else return 0;
}

int f0(int a,int b)
{
    check1=1;
    check4=2;
    return BICON(CON(a,b),CON(NOT(b),NOT(a)));
}

int f1(int a,int b)
{
    return BICON(a,b);
}

int f2(int a,int b,int c)
{   
    check4=1;
    check1=1;
    return CON(AND(a,CON(a,b)),b);
}
int f3(int a,int b,int c)
{
    return (AND(AND(a,b),c));
}

int f4(int a,int b,int c)
{
    check1=1;
    check4=2;
    return BICON((AND(OR(a,b),c)),OR(AND(a,c),AND(b,c)));
}
int f5(int a,int b,int c,int d)
{
    check4=1;
    check1=1;
    return CON(AND(AND(CON(a,b),CON(c,d)),OR(a,c)),OR(b,d));
}

void IMP(int res)
{   check3=1;
    if(!res) check2=1;    
}
void EQU(int res)
{
     check3=1;
     if(!res) check2=1;
     
}         



void display2(int(*f)())
{
     int res;
     int i,j;
     printf("\n\nThe Truth Table is \n");
     printf("------------------------\n\n");
     printf("A\tB\t%s\n",result);
     printf("------------------------\n\n");
     for(i=0;i<2;++i)
     {
                     for(j=0;j<2;++j)
                     {
                                     res=(*f)(i,j);
                                     if(check1==1)
                     {            if(check4==1)
                                  IMP(res);
                                  else if(check4==2)
                                  EQU(res);                                  
                                  if(check2==1)
                                  check1=0;
                     }
                                     
                                     printf("%d\t%d\t %d\n\n",i,j,res);
                     }
     }
     if(check3&&check2)
{
check1=0;
check2=0;
check3=0;
if(check4==1) printf("LOGICALLY DOESN'T IMPLY\n");
else if(check4==2) printf("LOGICALLY NOT EQUIVALENT\n");
check4=0;
}
else if(check3)
{
     check1=0;
     check3=0;
     if(check4==1)printf("LOGICALLY IMPLIES\n");    
     else if(check4==2)printf("LOGICALLY EQUIVALENT\n");
     check4=0;
}
                        
}

void display3(int(*f)())
{
     int res;
     int i,j,k;
     printf("\n\nThe Truth Table is \n");
     printf("-----------------------------\n\n");
     printf("A\tB\tC\t%s\n",result);
     printf("-----------------------------\n\n");
     for(i=0;i<2;++i)
     {
                     for(j=0;j<2;++j)
                     {
                                     for(k=0;k<2;++k)
                                     {
                                     res=(*f)(i,j,k);
                     if(check1==1)
                     {            if(check4==1)
                                  IMP(res);
                                  else if(check4==2)
                                  EQU(res);                                  
                                  if(check2==1)
                                  check1=0;
                     }            
                                  
                     
                                     printf("%d\t%d\t%d\t %d\n\n",i,j,k,res);
                     
                                     }
                      }
     }
if(check3&&check2)
{
check1=0;
check2=0;
check3=0;
if(check4==1) printf("LOGICALLY DOESN'T IMPLY\n");
else if(check4==2) printf("LOGICALLY NOT EQUIVALENT\n");
check4=0;
}
else if(check3)
{
     check1=0;
     check3=0;
     if(check4==1)printf("LOGICALLY IMPLIES\n");    
     else if(check4==2)printf("LOGICALLY EQUIVALENT\n");
     check4=0;
}
}
 
 
 
 
 void display4(int(*f)())
{
     int res;
     int i,j,k,l;
     printf("\n\nThe Truth Table is \n");
     printf("---------------------------------------------\n\n");
     printf("A\tB\tC\tD    %s\n",result);
     printf("---------------------------------------------\n\n");
     for(i=0;i<2;++i)
     {
                     for(j=0;j<2;++j)
                     {
                                     for(k=0;k<2;++k)
                                     {
                                                     for(l=0;l<2;++l)
                                                     {
                                     res=(*f)(i,j,k);
                     if(check1==1)
                     {            if(check4==1)
                                  IMP(res);
                                  else if(check4==2)
                                  EQU(res);                                  
                                  if(check2==1)
                                  check1=0;
                     }            
                                  
                     
                                     printf("%d\t%d\t%d\t%d\t %d\n\n",i,j,k,l,res);
                     
                                     }
                      }
     }
     }
if(check3&&check2)
{
check1=0;
check2=0;
check3=0;
if(check4==1) printf("LOGICALLY DOESN'T IMPLY\n");
else if(check4==2) printf("LOGICALLY NOT EQUIVALENT\n");
check4=0;
}
else if(check3)
{
     check1=0;
     check3=0;
     if(check4==1)printf("LOGICALLY IMPLIES\n");    
     else if(check4==2)printf("LOGICALLY EQUIVALENT\n");
     check4=0;
}
}
 
 
void main()
{

display2(f0);
getch();
}                                         
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
