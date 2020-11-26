#include<iostream.h>
#include<constream.h>
template <class D> // use of single class template
void DeSelSort(D arr[],int n) //Normal template function declaration
{
int smallIndex,largeIndex;
int leftPass=0,rightPass=n-1,i,j;
D temp; // data member of template
while (leftPass<=rightPass)
{
smallIndex=leftPass;
largeIndex=rightPass;
for (i=leftPass+1;i<rightPass;i++)
if (arr[i]<arr[smallIndex])
smallIndex=i;
if (smallIndex!=leftPass)
{
temp=arr[leftPass];
arr[leftPass]=arr[smallIndex];
arr[smallIndex]=temp;
}
for (j=rightPass-1;j>leftPass;j--)
if(arr[j]>arr[largeIndex])
largeIndex=j;
if(largeIndex!=rightPass)
{
temp=arr[rightPass];
arr[rightPass]=arr[largeIndex];
arr[largeIndex]=temp;
}
leftPass++;
rightPass--;
}
}

void main()
{
clrscr ();
cout<<"Entered list for double end selection."<<endl;
int i[8] = {4,6,2,0,3,7,9,5};
float f[8] = {2.3,7.5,5.4,9.6,3.5,6.7,8.3,4.5};
DeSelSort(i,8);//call to function
DeSelSort(f,8);//call to function
int leftPass = 0,rightPass = 0;
cout<<"\n Integer array elements in ascending order :->";
while(leftPass<8)
cout<<i[leftPass++]<<" "; //display contents of integer array
cout<<"\n";
cout<<"\n Float array elements in ascending order :-> ";
while(rightPass<8)
cout<<f[rightPass++]<<" "; //display contents of float array
getch ();
}