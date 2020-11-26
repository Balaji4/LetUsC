# include <stdio.h>
# include <string.h>
# include <stdlib.h>


int areRotations(char *str1, char *str2)
{
  int size1   = strlen(str1);
  int size2   = strlen(str2);
  char *temp;
  void *ptr;

  if(size1 != size2)
     return 0;
  temp   = (char *)malloc(sizeof(char)*size1*2 + 1);
  temp[0] = '\0';
  strcat(temp, str1);
  strcat(temp, str1);


  ptr = strstr(temp, str2);

  if(ptr != NULL)
    return 1;
  else
    return 0;
}

void main()
{
    char str1[80];
    char str2[80];
    clrscr();
    printf("\n enter string 1");
    scanf("%s",&str1);
    printf("\n enter string 2");
    scanf("%s",&str2);
    if(areRotations(str1, str2))
       printf("Strings are rotations of each other");
    else
       printf("Strings are not rotations of each other");

    getch();

}