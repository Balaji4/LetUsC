/*#include<stdio.h>

void rev(char *l, char *r);


int main(int argc, char *argv[])
{
char buf[80];// = "the world will go on forever";
char *end, *x, *y;
clrscr();
printf("Enter a string \n");
scanf("%s",&buf);
printf("words in reverse \n");
// Reverse the whole sentence first..
for(end=buf; *end; end++);
rev(buf,end);


// Now swap each word within sentence...
x = buf-1; 
y = buf; 

while(x++ < end)
{
if(*x == '\0' || *x == ' ')
{
rev(y,x-1);
y = x+1;
}
} 

// Now print the final string....
printf("%s\n",buf);
getch();
return(0);

}


// Function to reverse a string in place...
void rev(char *l,char *r) 
{
char t;
while(l < r) 
{ 
t = *l;
*l++ = *r;
*r-- = t;
}
}*/
#include<stdio.h>
#include<conio.h>
#include<string.h>

void rev(char *,char *);

int main()
{
int s,i=0;
int count=0;
char name[10][30], *end, *start,reversed[30]={"\0"};
printf("enter the text\n");
while(1)
{
gets(name[i]);
if(name[i][0]=='\0')
break;
i++;
}
for(s=0;s<=i;s++)
{
end=name[s];
start=name[s];
for(end =name[s];*end !='\0';end++)
if(*end=='\0' || *end ==' ')
{
rev(start,end-1);
start=end+1;
}

count= strlen(name[s]);
end=name[s]+count-1;
rev(start,end);
strcat(reversed,name[s]);
}
strrev(reversed);
printf("\nthe reverse order is : \n");
for(s=0;s<=i;s++)
puts(name[s]);
printf(" ori =%s",reversed);
return(0);

}


void rev(char *l ,char *m)
{

char t;
while(l<m)
{
t = *l;
*l++ = *m;
*m-- = t ;
}

}





