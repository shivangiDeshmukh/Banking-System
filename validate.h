#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "validate.h"
#define max 100
#define MAX_YR 9999
#define MIN_YR 1900

int isValidname(char Aname[]) {
  int count = 0;
  int length = strlen(Aname);
  // int flag=-1;
  
  // for (int i = 0; i < length; i++)
  //   {
  //   if(!isalpha(Aname[i]) ) 
  //   {
  //     return 1;
  //   }
  //   }
  for(int i=0;i<length;i++)
    {
    if (isalpha(Aname[i]) || Aname[i] == 32)
    {
      if(Aname[i]==32)
    {
      count++;
    
    }
  
    }
    }
  if (count != 2) {
    printf("Enter Valid name !! ");
    return 1;
  }
  

  return 0;
  // generateAccount(Aname[]);
}

  
char * generateAccount(char Aname[]) {
  char cc[8] = "";
    char ss[8];
  // printf("In function ");
  int length = strlen(Aname);
  // printf("Lenght is %d",length);
   // Aname=toupper(Aname);
  for (int i = 0; i < length; i++) {
    if (i == 0 && Aname[i] != ' ') {
      char ch = toupper(Aname[i]);
      char s[] = {ch, '\0'};
      strcat(cc, s);
    } else if (i > 0 && Aname[i - 1] == ' ') {
      char ch = toupper(Aname[i]);
      char s[] = {ch, '\0'};
      strcat(cc, s);
    }
  }
  int set = rand() % 900 + 100;
  char s1[10];
  sprintf(s1, "%d", set);
    strcpy(ss,strcat(cc,s1));
  // printf("%s",strcat(cc,s1));
  return cc;
}

int isValidage(int age) {
  if (age < 18 || age > 100) {
    return 1;
  }

  return 0;
}

int isValidgender(char gender[]) {
  if (strcmp(gender, "Male") == 0 || strcmp(gender, "Female") == 0 ||
      strcmp(gender, "m") == 0 || strcmp(gender, "M") == 0 ||
      strcmp(gender, "f") == 0 || strcmp(gender, "F") == 0) {
    return 0;
  }
  printf("Enter Valid Gender !! "); 
  return 1;
}

typedef struct {
  int yyyy;
  int mm;
  int dd;
} Date;

int IsLeapYear(int year) 
{
  return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}
// returns 1 if given date is valid.
int isValidDate(Date *validDate) {
  // check range of year,month and day
  if (validDate->yyyy > MAX_YR || validDate->yyyy < MIN_YR)
    return 0;
  if (validDate->mm < 1 || validDate->mm > 12)
    return 0;
  if (validDate->dd < 1 || validDate->dd > 31)
    return 0;
  // Handle feb days in leap year
  if (validDate->mm == 2) {
    if (IsLeapYear(validDate->yyyy))
      return (validDate->dd <= 29);
    else
      return (validDate->dd <= 28);
  }
  // handle months which has only 30 days
  if (validDate->mm == 4 || validDate->mm == 6 || validDate->mm == 9 ||
      validDate->mm == 11)
    return (validDate->dd <= 30);
  return 1;
}

int isValidaddress(char address[])
  {
  if (address[0] == '\0') {
    return 1;
    printf("Address cannot be Null ");
  }
  return 0;
}


int isValidCity(char city[])
  {
  if (city[0] == '\0') {
    return 1;
    printf("City cannot be null");
  }
  return 0;
}

int isValidPAN(char PAN[]) {
  int isValid = 0;
  if (strlen(PAN) == 10) {

    for (int i = 0; i < strlen(PAN) - 6; i++) {
      if (!isupper(PAN[i]) && isalpha(PAN[i])) {
        printf("First 5 are uppercase alphabets !! ");
        return 1;
      }
    }
    for (int i = 5; i <= 8; i++) {
      if (!isdigit(PAN[i])) {
        return 1;
      }
    }
    if (!isupper(PAN[9])) {
      return 1;
    }
    return 0;
  }
  printf("PAN should have 10 characters !! ");
  return 1;
}

int isValidateAccounttype(char AccountType[]) {
  if (strcmp(AccountType, "Saving") == 0 ||
      strcmp(AccountType, "Current") == 0 || strcmp(AccountType, "s") == 0 ||
      strcmp(AccountType, "c") == 0 || strcmp(AccountType, "S") == 0 ||
      strcmp(AccountType, "C") == 0) {
    return 0;
  }
  printf("Enter Valid Acount type");
  return 1;
}

int isValidAadhar(char AAdhar[]) {
  if (strlen(AAdhar) == 12) {
    for (int i = 0; i < strlen(AAdhar); i++) {
      if (!isdigit(AAdhar[i])) {
        return 1;
      }
    }
    return 0;
  }
  printf("Enter valid Aadhar no. with 12 digits !! ");
  return 1;
}

int isValidBalane(int balance)
  {
  if (balance <= 0) {
    printf("Balance cannot be 0 !!");
    return 1;
  }
  return 0;
}

