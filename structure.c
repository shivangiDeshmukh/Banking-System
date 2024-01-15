#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validate.h"
#define max 100
#define MAX_YR 9999
#define MIN_YR 1900
// typedef struct {
//   int yyyy;
//   int mm;
//   int dd;
// } Date;

int n=0;
struct Bank {
  char AccountNumber[max];
  char Bname[max], IFSC[max], Aname[max];
  int age, balance;
  char gender[max];
  char DOB[max];
  char address[max];
  char city[max];
  char AccountType[max];
  char PAN[max], AAdhar[max];
  Date d;
}b[100];

struct Bank acceptdetails() {
  
  struct Bank b;
  // for (int i = 0; i < n; i++) {
    // getchar();
    strcpy(b.Bname,"ICICI");
    printf("BANK NAME : %s",b.Bname);
    strcpy(b.IFSC, "ICICI000");
    printf("\nIFSC Code : %s", b.IFSC);
    
   do {
      printf("\nEnter your name (First middle last) : ");
      fgets(b.Aname, max, stdin);
      b.Aname[strlen(b.Aname) - 1] = '\0';
      isValidname(b.Aname);
    } while (isValidname(b.Aname));

    // strcpy(b[i].AccountNumber,generateAccount(&b[i].Aname));
    strcpy(b.AccountNumber,generateAccount(b.Aname));

    printf("Account Number : %s",b.AccountNumber);

    do {
      printf("\nEnter your age : ");
      scanf("%d", &b.age);
      isValidage(b.age);
      getchar();
    } while (isValidage(b.age));

    do {
      printf("Enter your gender (M/F) : ");
      fgets(b.gender, max, stdin);
      b.gender[strlen(b.gender) - 1] = '\0';
      isValidgender(b.gender);
      //   getchar();
    } while (isValidgender(b.gender));

    do {
      printf("Enter your DOB (DD/MM/YYYY) : ");
      scanf("%d/%d/%d", &b.d.dd, &b.d.mm, &b.d.yyyy);
      // fgets(b[i].DOB,max,stdin);
      // b[i].DOB[strlen(b[i].DOB)-1]='\0';
      isValidDate(&b.d);
      getchar();
    } while (isValidDate(&b.d) == 0);

    do {
      printf("Enter your address : ");
      fgets(b.address, max, stdin);
      b.address[strlen(b.address) - 1] = '\0';
      isValidaddress(b.address);
      // getchar();
    } while (isValidaddress(b.address));

    do {
      printf("Enter your City : ");
      fgets(b.city, max, stdin);
      b.city[strlen(b.city) - 1] = '\0';
      isValidCity(b.city);
    } while (isValidCity(b.city));

    do {
      printf("Enter PAN number : ");
      fgets(b.PAN, max, stdin);
      b.PAN[strlen(b.PAN) - 1] = '\0';
      isValidPAN(b.PAN);
    } while (isValidPAN(b.PAN));

    do {
      printf("Enter AAdhar number : ");
      fgets(b.AAdhar, max, stdin);
      b.AAdhar[strlen(b.AAdhar) - 1] = '\0';
      isValidAadhar(b.AAdhar);
    } while (isValidAadhar(b.AAdhar));

    do {
      printf("Enter the Account Type : (Savings(s)/current(c) : ");
      fgets(b.AccountType, max, stdin);
      b.AccountType[strlen(b.AccountType) - 1] = '\0';
      isValidateAccounttype(b.AccountType);
    } while (isValidateAccounttype(b.AccountType));

    do {
      printf("Enter Balance : ");
      scanf("%d", &b.balance);
      isValidBalane(b.balance);
    } while (isValidBalane(b.balance));

    printf("***********************************\n");
  // }
  return b;
};

void display(struct Bank b)
{
  printf("***DETAILS*** ");
  printf("\nBANK NAME : %s",b.Bname);
  printf("\nIFSC Code : %s",b.IFSC);
  printf("\nName : %s " ,b.Aname);
  printf("\nAccount Number : %s",b.AccountNumber);
  printf("\nAge : %d",b.age);
  printf("\nGender : %s",b.gender);
  printf("\nDOB : %d/%d/%d",b.d.dd,b.d.mm,b.d.yyyy);
  printf("\nAddress : %s",b.address);
  printf("\nCity : %s",b.city);
  printf("\nPAN : %s",b.PAN);
  printf("\nAAdhar : %s",b.AAdhar);
  printf("\nAccount Type : %s",b.AccountType);
  printf("\nBalance : %d",b.balance);
  printf("\n***********************************\n");

}
void deposit(struct Bank b[],int n)
{
  char accno[max];
  int amount;
  printf("Enter account number :\n ");
  scanf("%s",accno);
  for(int i=0;i<n;i++)
    {
      if(strcmp(b[i].AccountNumber,accno)==0)
      {
        printf("\nEnter amount to be deposited :");
        scanf("%d",&amount);
        b[i].balance +=amount;
        printf("\nAmount deposited successfully");
        printf("\nBalance : %d",b[i].balance);
        printf("-------------------------");
        return;
      }
    }
  
    printf("Account not found\n");
}

void withdraw(struct Bank b[],int n)
{
  char accno[max];
  int amount;
  printf("Enter the account number from which you want to withdraw : ");
  scanf("%s",accno);
  for(int i=0;i<n;i++)
    {
      if(strcmp(b[i].AccountNumber,accno)==0)
      {
        printf("Enter amount to withdraw :\n");
        scanf("%d",&amount);
        if(b[i].balance<amount)
        {
          printf("Insufficient balance");
          return;
        }
        else{
          b[i].balance -=amount;
          printf("\nAmount withdrwan successfully");
          printf("\nBalance : %d",b[i].balance);
          printf("\n-----------------------");
          return;
        }    
      }
    }

    printf("Account not found\n"); 
}
void checkBalance(struct Bank b[],int n)
{
  char accno[max];
  int amount;
  printf("Enter account number :\n ");
  scanf("%s",accno);
  for(int i=0;i<n;i++)
    {
      if(strcmp(b[i].AccountNumber,accno)==0)
      {
        printf("\nBalance : %d",b[i].balance);
        printf("\n-------------------------");
       return; 
      }
    }

    printf("Account not found\n");
}

void update(struct Bank b[],int n)
{
  printf("****update*****");
  int choice;
  char accno[max];
  char name[max];
  int amount;
  int flag=-1;
  do{
    printf("\nEnter account number :");
    scanf("%s",accno);
    for(int i=0;i<n;i++)
      {
        if(strcmp(b[i].AccountNumber,accno)==0)
        {
          flag=1;
          printf("1.Update name\n2.Update address\n3.update DOB ");
          printf("\n select option : ");
          scanf("%d",&choice);
          getchar();
          do{
            switch(choice)
            {
              case 1: 
                {
                  do {
                    printf("\nEnter your new name (First middle last) : ");
                    fgets(name, max, stdin);
                    name[strlen(name) - 1] = '\0';
                    isValidname(name);
                  } while (isValidname(name));
                  printf("Updated successfully");
                  strcpy(b[i].Aname,name);
                  display(b[i]);
                  printf("-----------------");
              break;

              }
              case 2:
                {
                  do
                    {
                      printf("Enter new address :\n");
                      fgets(b[i].address, max, stdin);
                      b[i].address[strlen(b[i].address) - 1] = '\0';
                      isValidaddress(b[i].address);
                    }while(isValidaddress(b[i].address));
                  printf("Address updated successfully");
                  display(b[i]);
                  printf("-------------------");
                  break;
                }
              case 3:
                {
                  do
                  {
                    printf("Enter new DOB :\n");
                    scanf("%d/%d/%d", &b[i].d.dd, &b[i].d.mm, &b[i].d.yyyy);
                    isValidDate(&b[i].d);
                    getchar();
                  }while(isValidDate(&b[i].d) == 0);
                  printf("DOB updated successfully");
                  display(b[i]);
                  printf("---------------------");
                  break;
                }
            }
          }while(choice<1||choice>3);
        }
      }
  }while(flag==-1);
  
  

  printf("Account not found\n");  
}

void fundTransfer(struct Bank b[],int n)
{
  char accno[max]; 
  char accno1[max];
  int amount;
  int from_f=-1;
  int to_f=-1;
  // for(int i=0;i<n;i++){
    do
    {
      printf("Enter the account number from which you want to transfer : ");
      scanf("%s",accno);
      for(int i=0;i<n;i++){
        if(strcmp(b[i].AccountNumber,accno)==0)
        {
          from_f=i;
        }
      }
      if(from_f==-1)
      {
        printf("Account not found\n");
      
      }
      
    }while(from_f==-1);

    do
      {
        printf("Enter the account number to which you want to transfer : ");
        scanf("%s",accno1);
        for(int i=0;i<n;i++)
          {
            if(strcmp(b[i].AccountNumber,accno1)==0)
            {
              to_f=i;
            }
          }
        if(to_f==-1){
          printf("Enter valid account number");
        }
      }while(to_f==-1);

    do
      {
        printf("Enter the amount to transfer : ");
        scanf("%d",&amount);
      }while(b[from_f].balance<amount);
        
          b[from_f].balance -=amount;
          b[to_f].balance +=amount;
    printf("Transfer successful\n %d",b[to_f].balance);
  // } 
  return;
}

void search(struct Bank b[],int n)
{
  int choice;
  printf("1.search by name\n2.search by type\n3.search by account no. ");
  printf("\n select option : ");
  scanf("%d",&choice);
  getchar();
  switch(choice)
  {
    case 1:
      {
        int flag=1;
        char name[max];
        do{
          // getchar();
          printf("Enter name : ");
          fgets(name, max, stdin);
          name[strlen(name) - 1] = '\0';
          isValidname(name);
        }while(isValidname(name));

        for(int i=0;i<n;i++)
          {
            if(strcmp(b[i].Aname,name)==0)
            {display(b[i]);
              flag=0;}
          }
        if(flag){
          printf("user not found");
        }
        
        break;
      }
    case 2:
      {
        int flag=1;
        char type[max];
        do{
          printf("Enter type : ");  
          fgets(type, max, stdin);
          type[strlen(type) - 1] = '\0';
          isValidateAccounttype(type);
        }while(isValidateAccounttype(type));
        for(int i=0;i<n;i++)
          {
            if(strcmp(b[i].AccountType,type)==0)
            {
              display(b[i]);
            }
          }
        if(flag)
        {
          printf("No user found");
        }
        break;
      }
    case 3 :
      {
        int flag=1;
        char accno[max];
        printf("Enter account number : ");
          scanf("%s",accno);
        for(int i=0;i<n;i++)
          {
            if(strcmp(b[i].AccountNumber,accno)==0)
          {
            display(b[i]);
           return; 
          }
        }

        printf("Account not found\n");
        break;
        }
      }
    
  }



  
int main() {
  printf("Welcome to ICICI : ");
  printf("\n********************");
  
  int ch;
  while(1)
    {
      printf("\n----------------------------------");
      printf("\n1.Accept\n2.Display\n3.Deposit\n4.Withdraw\n5.CheckBalance\n6.update\n7.Fund Transfer\n8.Search\n9.Exit\n");
      printf("\n select option : ");
      scanf("%d",&ch);
      getchar();
      // do{
        switch(ch)
          {
            case 1:
              {
                b[n++] = acceptdetails();
                break;
              }
            case 2:
              {
                for (int i=0;i<n;i++){
                    display(b[i]);
                }
                // display(b,n);
                break;
              }
            case 3:
            {
              deposit(b,n);
              break;
            }
            case 4 :
              {
                withdraw(b,n);
                break;
              }
            case 5 :
              {
                checkBalance(b,n);
                break;
              }
            case 6: 
              {
                update(b,n);
                break;
              }
            case 7:
              {
                fundTransfer(b,n);
                break;
              }
            case 8:
              {
                search(b,n);
                break;
              }
            case 9:
              {
                exit(0) ;
              }

          }



      // }while(ch!=7);            

    }
  
  


  // return 0;
}