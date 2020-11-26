# include <stdio.h>
# include <stdlib.h>
# include <iostream.h>
# include <fstream.h>
# include <string.h>
# include <conio.h>
# include <ctype.h>
# define size 80

typedef struct node
{
	char S[80];
	int count;
	struct node *link;
}NODE;

void display(NODE *H)
{
	while(H!=NULL){
		cout<<H->S<<" "<<H->count<<endl;
		H=H->link;
	}
	getch();
}

NODE* insert(NODE *H,char *str)
{

	char ch;
	NODE *T=(NODE *)malloc(sizeof(NODE)),*X=H;
	strcpy(T->S,str);
	T->link=NULL;
	T->count=1;


	if(H==NULL)
	{
		return T;
	}
	while(X->link!=NULL && strcmpi(X->S,T->S)!=0 ){
		X=X->link;
	}

	if(strcmpi(X->S,T->S)==0){
		X->count++;
		return H;
	}

	if(X->link==NULL){
		X->link=T;
		return H;
	}
}
char *getMax(NODE *H)
{
 fstream wout;
wout.open("try.txt",ios::out);
 NODE *T=H;
 int x=0;

 while(H!=NULL)
 {
  if(x<H->count)
  {
   x=H->count;
  }
  H=H->link;
 }
 cout<<"----"<<endl<<"Max Occurance"<<endl;
  wout<<"----"<<endl<<"Max Occurance"<<endl;
 while(T!=NULL)
 {
  if(x==T->count)
  {
   cout<<"----"<<endl<<T->S<<"\t"<<T->count<<endl;
   wout<<"----"<<endl<<T->S<<"\t"<<T->count<<endl;
  }
  T=T->link;
 }
 return T->S;
}

main(int argc,char *argv[])
{

 int found=0;
 clrscr();
 const int SIZE=80;
 char line1[SIZE],line2[SIZE],line3[SIZE];

 char *fname;
 ifstream fin1,fin2,fin3;
 ofstream out2;
cout<<"Enter a file name"<<endl;
 cin>>fname;

 fin1.open(fname);//argv[1]);

 int spacing=0;
 out2.open("rem.txt");

 while(fin1.eof()==0)
 {
  char ch;
  fin1.get(ch);
  if(ch>=65&&ch<=90||ch<=122&&ch>=97)
  {
   out2<<ch;
   spacing=0;
  }
  else if(ch==' '&&(!spacing)||(!(ch>=65&&ch<=90||ch<=122&&ch>=97)&&!(spacing)))
  {
   out2<<" ";
   spacing=1;

  }
  else
  continue;
 }


 fin1.close();

 out2.close();
 ofstream out1;
 out1.open("remstp.txt");

 fin3.open("rem.txt");
 fin2.open("stop.txt");

 while(fin3.eof()==0)
 {
  found=0;
  fin3.getline(line1,SIZE,' ');
  char w1[SIZE];
  strcpy(w1,line1);
  while(fin2.eof()==0 && found==0)
  {
   fin2.getline(line2,SIZE);
   char w2[SIZE];
   strcpy(w2,line2);
   int m=strlen(w1);
   int n=strlen(w2);
   for(int i=0;i<m;i++)
    w1[i]=toupper(w1[i]);
   for(i=0;i<n;i++)
    w2[i]=toupper(w2[i]);
   if(strcmp(w1,w2)==0)
   {
    found=1;
   }
  }
  if(found==0)
  {
   out1<<w1<<" ";
  }
  fin2.close();
  fin2.open("stop.txt");
 }
 fin2.close();
 fin3.close();
 out1.close();
 NODE *H=NULL;
 char temp[80], ch, j=0, i;
 ifstream fp;
 clrscr();
 fp.open("remstp.txt");
 if(fp.fail()==1)
 {
  cout<<"File Not Found"<<endl;
  exit(0);
 }
 while( ! fp.eof() )
 {
  ch=fp.get();
  if(ch==' ' || ch==(char)10)
  {
   if(strlen(temp)==0)
    continue;
   temp[j]='\0';
   H=insert(H,temp);
   j=0;
   strcpy(temp,"");
   continue;
  }
  temp[j++]=ch;
 }
 display(H);
 cout<<endl;
 getMax(H);
/* char *maxword;
 char *topic;
 int flag=0;
 cout<<endl;
  ifstream f;
 f.open("remstp.txt");
 maxword=getMax(H);  */
/* ifstream f;
 f.open("remstp.txt");  */
/*  while(f.eof()==0)
 {
  f.get(ch);
  if(ch==' ')
   break;
  topic=ch;
 }              */

/*  f.getline(topic,SIZE,' ');

 f>>topic;
 cout<<topic<<"i m topic\n";
 cout<<maxword<<"i m maxword\n";
 if(strcmp(topic,maxword)==0)
 {
  cout<<"Match\n";
  flag=1;
 }
 else
 cout<<"Not match\n";   */

 cout<<endl;
 getch();
 return 0;

}


