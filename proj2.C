#include <dos.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct data
{
   int n, x, y, level;
   struct data *left, *right, *prev;
} *root = NULL, *parent = NULL, *curr = NULL, *temp = NULL, *move = NULL;

int posX, posY, posKlik, i = 0;

void show_mouse(void)
{
   asm{
      mov ax,1h
      int 33h
   }
}

void set_mouse(void)
{
   asm{
      mov ax,4h
      mov cx,0
      mov dx,479
      int 33h
   }
}

void read_mouse(void)
{
   asm{
      mov ax,3h
      int 33h
      mov posX,cx // posX posisi X Mouse
      mov posY,dx // posY posisi Y Mouse
      mov posKlik,bx // posKlik keadaan Mouse, saat diklik atau tidak, dan tombol mana yang diklik
   }
}

void cetak(struct data *root1)
{
   if(root1)
   {
      if(root1 -> left) cetak(root1 -> left);
      if(root1 -> right) cetak(root1 -> right);
      gotoxy(root1 -> x, root1 -> y); cprintf("%2d",root1 -> n);
   }
}

void popall(struct data *root1)
{
   if(root1)
   {
      if(root1 -> left) popall(root1 -> left);
      if(root1 -> right) popall(root1 -> right);
      free(root1);
   }
}

void inorder(struct data *root1)
{
   if(root1)
   {
      if(root1 -> left) inorder(root1 -> left);
      textcolor(13);
      gotoxy(root1 -> x,root1 -> y); cprintf("%2d",root1 -> n);
      delay(500); textcolor(15);
      gotoxy(root1 -> x,root1 -> y); cprintf("%2d",root1 -> n);
      if(root1 -> right) inorder(root1 -> right);
   }
}

void adjustpositionX(struct data *root1, int direct)
{
   root1 -> level = root1 -> prev -> level + 1;
   root1 -> y = root1 -> prev -> y + 2;
   if(direct)
   {
      root1 -> x = root1 -> prev -> x + (80/pow(2,root1 -> level));
   }
   else
   {
      root1 -> x = root1 -> prev -> x - (80/pow(2,root1 -> level));
   }
   if(root1 -> left) adjustpositionX(root1 -> left, 0);
   if(root1 -> right) adjustpositionX(root1 -> right, 1);
}

void SearchAndDelete(int con,int key)
{
   int pos, flag = 0;
   _setcursortype(1);
   if(con)
   {
      gotoxy(2,23); cprintf("Masukkan Angka Yang Mau Dihapus : ");
      fflush(stdin); key = random(100);
      gotoxy(36,23); cprintf("%2d",key);
      delay(1000);
   }
   _setcursortype(0);
   parent = root;
   do
   {
      if(key==parent->n) break;
      else if(key < parent->n) {parent = parent -> left; pos = 0;}
      else {parent = parent -> right; pos = 1;}
   }while(parent);

   // Aturan ambil yang paling besar di sebelah kiri //

   if(parent)
   {
      textcolor(13); gotoxy(parent -> x, parent -> y); cprintf("%2d",parent -> n);
      delay(500);
      if(parent -> left)
      {
	 temp = parent -> left;
	 while(temp -> right) {temp = temp -> right; flag = 1;}
	 textcolor(LIGHTBLUE); gotoxy(temp -> x, temp -> y);
	 cprintf("%2d",temp -> n); delay(500);
	 parent -> n = temp -> n;
	 textcolor(LIGHTBLUE); gotoxy(parent -> x, parent -> y);
	 cprintf("%2d",parent -> n);
	 gotoxy(temp -> x, temp -> y); cprintf("  "); delay(500);
	 textcolor(15); gotoxy(parent -> x, parent -> y);
	 cprintf("%2d",parent -> n);
	 if(flag)
	 {
	    if(temp -> left)
	    {
	       move = temp -> left;
	       temp = temp -> prev;
	       free(temp -> right);
	       temp -> right = move;
	       move -> prev = temp;
	    }
	    else
	    {
	       temp = temp -> prev;
	       free(temp -> right);
	       temp -> right = NULL;
	    }
	 }
	 else
	 {
	    if(temp -> left)
	    {
	       move = temp -> left;
	       temp = temp -> prev;
	       free(temp -> left);
	       temp -> left = move;
	       move -> prev = temp;
	    }
	    else
	    {
	       temp = temp -> prev;
	       free(temp -> left);
	       temp -> left = NULL;
	    }
	 }
	 parent = root;
	 if(parent -> left) adjustpositionX(parent->left,0);
	 parent = root;
	 if(parent -> right) adjustpositionX(parent->right,1);
      }

      // Aturan ambil yang paling kecil di sebelah kanan //

      else if(parent -> right)
      {
	 temp = parent -> right;
	 while(temp -> left) {temp = temp -> left; flag = 1;}
	 textcolor(LIGHTBLUE); gotoxy(temp -> x, temp -> y);
	 cprintf("%2d",temp -> n); delay(500);
	 parent -> n = temp -> n;
	 textcolor(LIGHTBLUE); gotoxy(parent -> x, parent -> y);
	 cprintf("%2d",parent -> n);
	 gotoxy(temp -> x, temp -> y); cprintf("  "); delay(500);
	 textcolor(15); gotoxy(parent -> x, parent -> y);
	 cprintf("%2d",parent -> n);
	 if(flag)
	 {
	    if(temp -> right)
	    {
	       move = temp -> right;
	       temp = temp -> prev;
	       free(temp -> left);
	       temp -> left = move;
	       move -> prev = temp;
	    }
	    else
	    {
	       temp = temp -> prev;
	       free(temp -> left);
	       temp -> left = NULL;
	    }
	 }
	 else
	 {
	    if(temp -> right)
	    {
	       move = temp -> right;
	       temp = temp -> prev;
	       free(temp -> right);
	       temp -> right = move;
	       move -> prev = temp;
	    }
	    else
	    {
	       temp = temp -> prev;
	       free(temp -> right);
	       temp -> right = NULL;
		 }
	 }
	 parent = root;
	 if(parent -> left) adjustpositionX(parent->left,0);
	 parent = root;
	 if(parent -> right) adjustpositionX(parent->right,1);
      }

      // Jika tidak ada left child atau right child //

      else
      {  textcolor(15); gotoxy(parent -> x, parent -> y); cprintf("  ");
	 if(parent==root)
	 {
	    free(root);
	    root = parent = curr = NULL;
	 }
	 else if(!pos)
	 {
	    parent = parent -> prev;
	    temp = parent -> left;
	    free(temp);
	    parent -> left = NULL;
	 }
	 else if(pos)
	 {
	    parent = parent -> prev;
	    temp = parent -> right;
	    free(temp);
	    parent -> right = NULL;
	 }
      }
      i--;
   }
   else
   {
      gotoxy(2,24); cprintf("Maaf nilai yang anda ingin hapus tidak ada");
      delay(1000);
   }
   parent = root;
   clrscr(); textbackground(15); textcolor(0);
   gotoxy(2,25); cprintf(" 1.Push           2.Pop           3.Search          4.InOrder         5.Exit ");
   textbackground(0); textcolor(15);
   cetak(parent);
}

int cek(void)
{
   parent = root;
   if(curr -> n < 1 || curr -> n > 100) return 1;
   if(!root) if(curr -> n < 30 || curr -> n > 70) return 1;
   do
   {
      if(curr -> n == parent -> n)
      {
	 gotoxy(2,24); cprintf("Data sudah ada atau tidak diantara 1 - 100, tolong ulangi sekali lagi.");
	 delay(1000);
	 gotoxy(2,24); clreol();
	 return 1;
      }
      else if(curr -> n < parent -> n) parent = parent -> left;
      else parent = parent -> right;
   }while(parent);
   return 0;
}

int search(void)
{
   int nn;
   _setcursortype(1);
   parent = root;
   gotoxy(2,23); printf("Masukkan Angka Yg Akan Dicari : ");
   scanf("%d",&nn);
   _setcursortype(0);
   do
   {
      if(nn == parent -> n)
      {
	 gotoxy(parent -> x, parent -> y); textcolor(LIGHTBLUE); cprintf("%2d",parent -> n);
	 delay(500);
	 textcolor(15); gotoxy(parent -> x, parent -> y); cprintf("%2d",parent -> n);
	 gotoxy(2,24); textcolor(15); cprintf("Data ada pada level %d",parent -> level);
	 return 1;
      }
      else if(nn < parent -> n) parent = parent -> left;
      else parent = parent -> right;
      gotoxy(parent -> x, parent -> y); textcolor(13); cprintf("%2d",parent -> n);
      delay(500);
      gotoxy(parent -> x, parent -> y); textcolor(15); cprintf("%2d",parent -> n);
   }while(parent);
   gotoxy(2,24); cprintf("Data tidak ada");
   return 0;
}

void push(void)
{
   int a;
   randomize();
   curr = (struct data*)malloc(sizeof(struct data));
   curr -> left = curr -> right = NULL;
   _setcursortype(1);
   gotoxy(2,23); cprintf("Angka [1..100] : ");
   do
   {
      if(a%2) a = random(50) + 1;
      else a = random(100) + 50;
      gotoxy(19,23); clreol(); curr -> n = a;
      fflush(stdin); printf("%d",curr -> n);
   }while(cek());
   _setcursortype(0);
   if(!root)
   {
      root = parent = curr;
      curr -> prev = NULL;
      curr -> level = curr -> y = 1;
      curr -> x = 40;
   }
   else
   {
      parent = root;
      do
      {
	 textcolor(13); gotoxy(parent -> x, parent -> y); cprintf("%2d",parent -> n);
	 delay(500);
	 textcolor(15); gotoxy(parent -> x, parent -> y); cprintf("%2d",parent -> n);
	 if(curr -> n < parent -> n)
	 {
	    if(!parent -> left)
	    {
	       parent -> left = curr;
	       curr -> prev = parent;
	       curr -> level = parent -> level + 1;
	       curr -> y = parent -> y + 2;
	       curr -> x = parent -> x - (80/pow(2,curr -> level));
	       break;
	    }
	    else parent = parent -> left;
	 }
	 else if(curr -> n > parent -> n)
	 {
	    if(!parent -> right)
	    {
	       parent -> right = curr;
	       curr -> prev = parent;
	       curr -> level = parent -> level + 1;
	       curr -> y = parent -> y + 2;
			 curr -> x = parent -> x + (80/pow(2,curr -> level));
	       break;
	    }
	    else parent = parent -> right;
	 }
      }while(1);
   }
   textcolor(LIGHTBLUE); gotoxy(curr -> x, curr -> y); cprintf("%2d",curr -> n);
   delay(500);
   textcolor(15); gotoxy(curr -> x, curr -> y); cprintf("%2d",curr -> n);
}

void main(void)
{
   clrscr();
   textmode(C80);
   _setcursortype(0);
   textbackground(15); textcolor(0);
   gotoxy(2,25); cprintf(" 1.Push           2.Pop           3.Search          4.InOrder         5.Exit ");
   textcolor(15); textbackground(0);
   set_mouse();
   show_mouse();
   do
   {
      read_mouse();
      textcolor(15);
		gotoxy(71,1); cprintf("%4d%4d",posX,posY);
      if((posX>=576&&posX<=632)&&(posY==196)&&posKlik) break;
      else if((posX>=426&&posX<=505)&&(posY==196)&&posKlik)
      {
	 if(i>0)
	 {
	    parent = root;
	    inorder(parent);
	 }
	 else
	 {
	    gotoxy(2,24); cprintf("Data tidak ada");
	    delay(1000);
	    gotoxy(2,23); clreol();
	    gotoxy(2,24); clreol();
	 }
      }
      else if((posX>=281&&posX<=353)&&(posY==196)&&posKlik)
      {
	 search(); delay(1000);
	 gotoxy(2,23); clreol();
	 gotoxy(2,24); clreol();
      }
      else if((posX>=151&&posX<=206)&&(posY==196)&&posKlik)
      {
	 if(i>0) {SearchAndDelete(1,1);}
	 else
	 {
	    gotoxy(2,24); cprintf("Jumlah node sudah 0");
	    delay(1000);
	 }
	 gotoxy(2,23); clreol();
	 gotoxy(2,24); clreol();
      }
      else if((posX>=  8&&posX<= 66)&&(posY==196)&&posKlik)
      {
	 if(i<10) {push(); i++;}
	 else
	 {
	    gotoxy(2,24); cprintf("Jumlah node sudah 10");
	    delay(1000);
	 }
	 gotoxy(2,23); clreol();
	 gotoxy(2,24); clreol();
      }
   }while(1);
   while(parent)
   {
      parent = root;
      SearchAndDelete(0,parent -> n);
   }
}