/* Copyright Protected by mycfiles.com
C Program to Block any website on computer */
#include<DOS.h>
#include<DIR.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>

char ip[12]="127.0.0.1";
FILE *target;

int rootfinder(void);
void siteblocker(char *);
void main()
{
char name[20];
int success=0;
clrscr();
printf("Enter The web site name to be block\n");
gets(name);
success=rootfinder();
if(success)
siteblocker(name);
printf("%s is blocked",name);
getch();
}

int rootfinder()
{
int done;
struct ffblk ffblk;//File block structure

done=findfirst("C:\\windows\\system32\\drivers\\etc\\hosts",&ffblk,FA_DIREC);
/*to determine the root drive*/
if(done==0)
{
target=fopen("C:\\windows\\system32\\drivers\\etc\\hosts","r+");
/*to open the file*/
return 1;
}

else return 0;
}

void siteblocker(char *na)
{


int i;
fseek(target,0,SEEK_END); /*to move to the end of the file*/

fprintf(target,"\n");
fprintf(target,"%s\t%s\n",ip,na);
fclose(target);
}

/*
Save the code as block_site.c and open it and compile it by Ctrl+F9. It will create a exe.
Now right click on that exe and open it with run as administrator.
Now the program will ask to enter the web site name to be block.
Enter the site name like www.site.com and press enter program will say www.site.com is blocked.

Code Analysis:
There is manual way of doing this trick
Go to C:\Windows\System32\Drivers\Etc and find the file “hosts”. Open hosts file in Notepad.
In hosts file go at the end and add the sites you want to block
Example :
127.0.0.1             www.site.com
Save the file and exit
Hosts file description
Restart your browser and try to open the site, changes will take place immediately.
This is what we are doing with above c program..

To unblock site:
To unblock sites follow the manual way and open the hosts file in notepad and delete last lines
That 127.0.0.1  www.site.com and save.

You might cannot modify the hosts file because of windows file permission issue, then
Right click on hosts files > properties > security > and to change permissions click edit then select user and check full control box and save now again open the hosts file and modify.

Note: the reason we are running program exe in run as administrator mode is because the windows file permission issue. Normal user doesn’t have full access to the system files that we can’t write anything into the file.
*/