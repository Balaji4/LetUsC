#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_attempt 3
#define n 10000
#define m 15000
int count=0;

int t;


void create_account();
void create_account_bank(int bank_code);
void general_requirement();
void authorization();
void authorization_bank(int Atm_no,int bankcode);
void withdrawl(int accno,char cust_name[],int atmno,int bal,int bankcode);

struct customer
{
        int acc_no;
        char name[15];
        char dob[15];
        char place[10];
        int atm_no;
        int balance;
        int password;

};
struct customer s;
struct customer e;

main()
{
        int ch;

        printf("\nenter the amount in ATM center at the start of the day\n");
        scanf("%d",&t);
        general_requirement();
        while(1)
        {
        printf("\nEnter \n1:Create Account \n2:ATM transaction\n3:Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:create_account();
                break;

        case 2:authorization();
                break;
        case 3:exit(0);
        }
        }
}

void create_account()
{
        int sbi_code=10001;
        int vb_code=10002;
        int kb_code=10003;
        int choice;
        while(1)
        {
        printf("\nenter\n1: SBI\n2:Vijaya Bank\n3:Karnataka Bank\n4:exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
                case 1:create_account_bank(sbi_code);
                        break;
                case 2:create_account_bank(vb_code);
                        break;
                case 3:create_account_bank(kb_code);
                        break;
                case 4:return;
        }
        }
}

void create_account_bank(int bank_code)
{
        FILE *fp;
        if(bank_code==10001)
        {
        fp=fopen("SBI","a+");
        }
        else if(bank_code==10002)
        {
        fp=fopen("VB","a+");
        }
        else
        {
        fp=fopen("KB","a+");
        }
        s.acc_no=bank_code+count;
        count++;
        printf("\nenter\nName\tDob\tPlace\tatm_no\tbalance\tPassword\n");
        fscanf(stdin,"%s%s%s%d%d%d",s.name,s.dob,s.place,&s.atm_no,&s.balance,&s.password);
        fprintf(fp,"%d\t%s\t%s\t%s\t%d\t%d\t%d\n",s.acc_no,s.name,s.dob,s.place,s.atm_no,s.balance,s.password);
        //fprintf(stdout,"\n");
        fclose(fp);
}

void general_requirement()
{
        if(t<=n)
        {
         printf("\nNo ATM SERVICE\n");
         exit(0);
        }
        else
        return;
}

void authorization()
{
        int Atm_no,bankcode;
        printf("\nWelcome to ATM\n");
        printf("\nInsert the ATM card\n");
        printf("\nRead the Atm card no and bank code\n");
        scanf("%d%d",&Atm_no,&bankcode);
        if((bankcode==10001)||(bankcode==10002)||bankcode==10003)
        {
        authorization_bank(Atm_no,bankcode);
        return;
        }
        else
        {
        printf("\nunauthorized access\nPlease contact the Bank\n");
        return;
        }
}

void authorization_bank(int Atm_no,int bankcode)
{
        int psw;
        int attempt=0;
        char bankname[10];
        FILE *ptr;
                if(bankcode==10001)
                {
                ptr=fopen("SBI","r");
                }
                else if(bankcode==10002)
                {
                ptr=fopen("VB","r");
                }
                else
                {
                ptr=fopen("KB","r");
                }

        while(fscanf(ptr,"%d%s%s%s%d%d%d",&e.acc_no,e.name,e.dob,e.place,&e.atm_no,&e.balance,&e.password)!=EOF)
        {

        fprintf(stdout,"%d\t%s\t%s\t%s\t%d\t%d\t%d\n",e.acc_no,e.name,e.dob,e.place,e.atm_no,e.balance,e.password);
                
                if(Atm_no==e.atm_no)
                {
                  while(attempt<max_attempt)
                   {
                    printf("\nEnter the password\n");
                    scanf("%d",&psw);
                     if(psw==e.password)
                        {
                        attempt=0;
                        fclose(ptr);
                        printf("\nEnter the Amount\n");
                        printf("a===========%s\n", e.name);
                        withdrawl(e.acc_no,e.name,e.atm_no,e.balance,bankcode);
                        return;
                        }
                     else
                      {
                       attempt++;
                       }
                   }
                }
                else
                {
                continue;
                }
        }
                fclose(ptr);
                printf("\nNot a Valid card\n");
                return;
}


void withdrawl(int accno,char cust_name[],int atmno,int bal,int bankcode)
{
     FILE *b;
     int c=0;
     int amt;
     int cust_bal=0;
     char bankname[13];
     printf("SJCE---------\n");
     
     while(1)
     {
     scanf("%d",&amt);
     if((amt>=m)||(amt%100==90)||(amt%100==80)||(amt%100==70)||(amt%100==60)||(amt%100==50)||(amt%100==40)||(amt%100==30)||(amt%100==20)||(amt%100==10)||(amt%100==9)|(amt%100==8)||(amt%100==7)||(amt%100==6)||(amt%100==5)||(amt%100==4)||(amt%100==3)||(amt%100==2)||(amt%100==1))
     {
        printf("\nenter the amount less than 15000\n OR \nenter the amount in terms of 100 only\n ");
        continue;
     }
     else
     {
      break;

     }

     }

     //l:printf("RAJANARAYAN-----------------------\n");

     cust_bal=bal-amt;
     printf("BAL_________%d\n",cust_bal);
     t=t-amt;
     printf("\nplease collect the amount\n");
     b=fopen("ATM","a+");
     fprintf(b,"%d\t%s\t%d\t%d\n",accno,cust_name,atmno,cust_bal);
     fprintf(stdout,"\n");
     fclose(b);

     printf("\nTransaction succeeded\n");
     FILE *f;

     if(bankcode==10001)
     {
     f=fopen("SBI","r+b");
     }

     else if(bankcode==10002)
     {

     f=fopen("VB","r+b");

     }
     else
     {
     f=fopen("KB","r+b");
     }

     while(fscanf(f,"%d%s%s%s%d%d%d",&e.acc_no,e.name,e.dob,e.place,&e.atm_no,&e.balance,&e.password)!=EOF)
     {
        c++;
        printf("\nFile search count : %d\n",c);
     
     if((e.atm_no==atmno)&&(e.acc_no==accno))
     {
     
     e.balance=cust_bal;
     printf("\ne.balance : %d\n",e.balance);

     printf("previous %u\n",ftell(f));
     fseek(f,-sizeof(e),SEEK_CUR);
     printf("next %u\n",ftell(f));

     //fwrite(f,sizeof(struct customer),1,f);
     //fwrite(f,"%d\t%s\t%s\t%s\t%d\t%d\t%d\n",e.acc_no,e.name,e.dob,e.place,e.atm_no,e.balance,e.password);
     fprintf(f,"%d\t%s\t%s\t%s\t%d\t%d\t%d\n",e.acc_no,e.name,e.dob,e.place,e.atm_no,e.balance,e.password);
     fclose(f);
     printf("\nplease take the Receipt\n");
     printf("\nThank You!!\nVisit Again\n");
     return;
     }

     }
     
     printf("\n Transaction not successfull\tEject the card\n");
     fclose(f);
     return;

}


