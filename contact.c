#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
#include<ctype.h>

void listContacts(AddressBook *addressBook) 
{
    // Sort contacts based on the chosen criteria
    for(int i=0;i<addressBook->contactCount;i++)
    {
      printf("\t\tContact %d\n\n",i+1);
        printf(" Name: %s\n Phone: %s\n email: %s\n\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
}

void initialize(AddressBook *addressBook) {
    //populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
   saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}

void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    //validation of name
    printf("Enter name:");
    int res1;
    do
    {
      scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);
      res1=nameVal(addressBook,addressBook->contacts[addressBook->contactCount].name);
      if(res1)
      {
        printf("Enter a valid name:");
      }
    }while(res1!=0);
    //validation of number
    printf("Enter number:");
    int res2;
    do
    {
      scanf("%s",addressBook->contacts[addressBook->contactCount].phone);
      res2=mobVal(addressBook,addressBook->contacts[addressBook->contactCount].phone);
      if(res2)
      {
        printf("Enter a valid number:");
      }
    }while(res2!=0);
    
   //validiton of email address
    printf("Enter email:");
    int res3;
    do
    {
      scanf("  %[^\n]",addressBook->contacts[addressBook->contactCount].email);
      res3=emailVal(addressBook,addressBook->contacts[addressBook->contactCount].email);
      if(res3)
      {
        printf("Enter a valid email:");
      }
    }while(res3!=0);
    addressBook->contactCount++;
}


void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    int choice,count=0;
    char name[50],mob[11],addr[50];
    printf("Enter your choise to search: ");//prompting the user to enter his choise to search
    printf("\n1.Name \n 2.Mobile number \n 3.Email id ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
      printf("Enter the name : ");//user entering name
        scanf("  %[^\n]",name);
        for(int i=0;i<addressBook->contactCount;i++)
        {
            if(strcasecmp(name,addressBook->contacts[i].name)==0)//check for user entered name
            {
              count++;
              printf(" Name: %s\n Phone: %s\n email: %s\n\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            }
        }
            if(count>1)
            {
              printf("Multiple contacts found. Please enter the mobile number: ");//asking user to enter mobile number because of multiple contacts
              scanf("%s",mob);
              for(int i=0;i<addressBook->contactCount;i++)
              {
                if(strcmp(mob,addressBook->contacts[i].phone)==0)
                {
                  printf(" Name: %s\n Phone: %s\n email: %s\n\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                  break;
                }
              }
            }
        break;
        case 2:
        printf("Enter the mobile number: ");//searching using mobile number
        scanf("%s",mob);
        for(int i=0;i<addressBook->contactCount;i++)
        {
          if(strcmp(mob,addressBook->contacts[i].phone)==0)
            {
               printf(" Name: %s\n Phone: %s\n email: %s\n\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            }
        }
        break;
        case 3:
        printf("Enter the Email id:");//searching using email id
        scanf("  %[^\n]",addr);
        for(int i=0;i<addressBook->contactCount;i++)
        {
          if(strcmp(addr,addressBook->contacts[i].email)==0)
            {
               printf(" Name: %s\n Phone: %s\n email: %s\n\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            }
        }
        break;
        default:
        printf("No data found!!");

        }
            
  }

void editContact(AddressBook *addressBook)
{
  int sc,count=0,x,indi=0;
     do{
  printf("Search by:\n1.Name\n2.Phone\n3.Email\n4.Go back\nEnter choice:");//users choice to edit
  scanf(" %d",&sc);
  int resP,resE;
  if(sc==1){
    printf("Enter name to edit:");
  }
  else if(sc==2){
    printf("Enter phone number to edit:");
  }
  else if(sc==3){
    printf("Enter Email to edit:");
  }
  switch(sc){
  
    case 1:
    scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name); 
    printf("\n");

     for(int i=0;i<addressBook->contactCount;i++){
    if((strcasecmp(addressBook->contacts[addressBook->contactCount].name,addressBook->contacts[i].name))==0){
        printf("%s %s %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        count++;
        x=i;
    }
  }
   if(count==0){
    printf("Name not found!\n");
  }
  else if(count==1){
   int flag=0;
    do{
      printf("Enter new name:");
      scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);
      if(nameVal(addressBook,addressBook->contacts[addressBook->contactCount].name)){
         printf("Enter a valid name\n");
      }
      else{
      strcpy(addressBook->contacts[x].name,addressBook->contacts[addressBook->contactCount].name);
      flag=1;
      }
    }while(flag!=1);

    do{
    printf("Enter new Phone number:");
    scanf(" %s",addressBook->contacts[addressBook->contactCount].phone);
    resP=mobVal(addressBook,addressBook->contacts[addressBook->contactCount].phone);
      if(resP==2){
      printf("Enter a vaild mobile number\n");
     }
     else if(resP==1){
      printf("Same number is present!\n");
     }
     else{
      strcpy(addressBook->contacts[x].phone,addressBook->contacts[addressBook->contactCount].phone);
      flag=1;
      }
    }while(resP!=0);

    do{
    printf("Enter new Email:");
    scanf(" %s",addressBook->contacts[addressBook->contactCount].email);
    resE=emailVal(addressBook,addressBook->contacts[addressBook->contactCount].email);
    if(resE==2){
      printf("Enter a vaild email\n");
    }
     else if(resE==1){
      printf("Same email is present!\n");
    }
    else{
      strcpy(addressBook->contacts[x].email,addressBook->contacts[addressBook->contactCount].email);
      flag=1;
      printf("Contact edited successfully\n\n");
      }
    }while(resE!=0);
  }

  else if(count>1){
    int i,flag=0;
    printf("Multiple names are present!\nEnter phone number to confirm:");
    scanf(" %s",addressBook->contacts[addressBook->contactCount].phone);
         for(i=0;i<addressBook->contactCount;i++){
         if((strcmp(addressBook->contacts[addressBook->contactCount].phone,addressBook->contacts[i].phone))==0){
          break;
    }
  }
  do{
      printf("Enter new name:");
      scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);
      if(nameVal(addressBook,addressBook->contacts[addressBook->contactCount].name)){
        printf("Enter a valid name\n");
      }
      else{
      strcpy(addressBook->contacts[x].name,addressBook->contacts[addressBook->contactCount].name);
      flag=1;
      }
    }while(flag!=1);

      do{
    printf("Enter new Phone number:");
    scanf(" %s",addressBook->contacts[addressBook->contactCount].phone);
    resP=mobVal(addressBook,addressBook->contacts[addressBook->contactCount].phone);
      if(resP==2){
      printf("Enter a vaild mobile number\n");
     }
     else if(resP==1){
      printf("Same number is present!\n");
     }
     else{
      strcpy(addressBook->contacts[x].phone,addressBook->contacts[addressBook->contactCount].phone);
      flag=1;
      }
    }while(resP!=0);

    do{
    printf("Enter new Email:");
    scanf(" %s",addressBook->contacts[addressBook->contactCount].email);
    resE=emailVal(addressBook,addressBook->contacts[addressBook->contactCount].email);
    if(resE==2){
      printf("Enter a vaild email\n");
    }
     else if(resE==1){
      printf("Same email is present!\n");
    }
    else{
      strcpy(addressBook->contacts[x].email,addressBook->contacts[addressBook->contactCount].email);
      flag=1;
      indi=1;
      printf("Contact edited successfully\n\n");
      }
    }while(resE!=0);
  }
  else{
    printf("Phone number not found!\n");
  }
  break;

  case 2:
    scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].phone); 
    printf("\n");

     for(int i=0;i<addressBook->contactCount;i++){
    if((strcmp(addressBook->contacts[addressBook->contactCount].phone,addressBook->contacts[i].phone))==0){
        printf("%s %s %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        count++;
        x=i;
        break;
    }
  }
  if(count==0){
    printf("Phone number not found!");
  }
  else{
    int flag=0;
    do{
      printf("Enter new name:");
      scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);
      if(nameVal(addressBook,addressBook->contacts[addressBook->contactCount].name)){
         printf("Enter a valid name\n");
      }
      else{
      strcpy(addressBook->contacts[x].name,addressBook->contacts[addressBook->contactCount].name);
      flag=1;
      }
    }while(flag!=1);

    do{
    printf("Enter new Phone number:");
    scanf(" %s",addressBook->contacts[addressBook->contactCount].phone);
    resP=mobVal(addressBook,addressBook->contacts[addressBook->contactCount].phone);
      if(resP==2){
      printf("Enter a vaild mobile number\n");
     }
     else if(resP==1){
      printf("Same number is present!\n");
     }
     else{
      strcpy(addressBook->contacts[x].phone,addressBook->contacts[addressBook->contactCount].phone);
      flag=1;
      }
    }while(resP!=0);

    do{
    printf("Enter new Email:");
    scanf(" %s",addressBook->contacts[addressBook->contactCount].email);
    resE=emailVal(addressBook,addressBook->contacts[addressBook->contactCount].email);
    if(resE==2){
      printf("Enter a vaild email\n");
    }
     else if(resE==1){
      printf("Same email is present!\n");
    }
    else{
      strcpy(addressBook->contacts[x].email,addressBook->contacts[addressBook->contactCount].email);
      flag=1;
      indi=1;
      printf("Contact edited successfully\n\n");
      }
    }while(resE!=0);
  }
    break;

    case 3:
    scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].email); 
    printf("\n");

     for(int i=0;i<addressBook->contactCount;i++){
    if((strcmp(addressBook->contacts[addressBook->contactCount].email,addressBook->contacts[i].email))==0){
        printf("%s %s %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        count++;
        x=i;
        break;
    }
  }
  if(count==0){
    printf("Phone number not found!");
  }
  else{
    int flag=0;
    do{
      printf("Enter new name:");
      scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);
      if(nameVal(addressBook,addressBook->contacts[addressBook->contactCount].name)){
         printf("Enter a valid name\n");
      }
      else{
      strcpy(addressBook->contacts[x].name,addressBook->contacts[addressBook->contactCount].name);
      flag=1;
      }
    }while(flag!=1);

    do{
    printf("Enter new Phone number:");
    scanf(" %s",addressBook->contacts[addressBook->contactCount].phone);
    resP=mobVal(addressBook,addressBook->contacts[addressBook->contactCount].phone);
      if(resP==2){
      printf("Enter a vaild mobile number\n");
     }
     else if(resP==1){
      printf("Same number is present!\n");
     }
     else{
      strcpy(addressBook->contacts[x].phone,addressBook->contacts[addressBook->contactCount].phone);
      flag=1;
      }
    }while(resP!=0);

    do{
    printf("Enter new Email:");
    scanf(" %s",addressBook->contacts[addressBook->contactCount].email);
    resE=emailVal(addressBook,addressBook->contacts[addressBook->contactCount].email);
    if(resE==2){
      printf("Enter a vaild email\n");
    }
     else if(resE==1){
      printf("Same email is present!\n");
    }
    else{
      strcpy(addressBook->contacts[x].email,addressBook->contacts[addressBook->contactCount].email);
      flag=1;
      indi=1;
      printf("Contact edited successfully\n\n");
      }
    }while(resE!=0);
  }

  case 4:
  indi=1;
  }
  }while(indi!=1);
}
void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
    int choice,flag=0,count=0;
    char name[50],mob[11],addr[50];
    printf("Enter your choise to delete: ");
    printf("\n1.Name \n 2.Mobile number \n 3.Email id ");//prompting the user to enter his choise to search
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
      printf("Enter name to delete:");
      scanf("  %[^\n]",name);
      for(int i=0;i<addressBook->contactCount;i++)
      {
      if((strcasecmp(name,addressBook->contacts[i].name))==0)
      {
        count++;
      }
      }
      if(count<=1)
      {
        for(int i=0;i<addressBook->contactCount;i++)
        {
         if((strcasecmp(name,addressBook->contacts[i].name))==0)
        {
        for(int j=i;j<addressBook->contactCount;j++)
        {
          addressBook->contacts[j]=addressBook->contacts[j+1];
          addressBook->contactCount--;
        }
        flag=1;
        }
        }
        if(flag==0)
        {
          printf("Invalid name!!");
        }
      }
       else       
      {
      printf("Multiple contacts found!! Please enter the mobile number");//multiple contacts found delete using mobile number
      scanf("%s",mob);
      for(int i=0;i<addressBook->contactCount;i++)
      {
        if(strcmp(mob,addressBook->contacts[i].phone)==0)
        {
          for(int j=i;j<addressBook->contactCount;j++)
        {
          addressBook->contacts[j]=addressBook->contacts[j+1];
          addressBook->contactCount--;
        }
        }
        flag=1;
      }
      }
      if(flag==0)
      {
        printf("Invalid name!!");
      }
      break;
  case 2:
  printf("Enter the mobile number: ");//deleting using mobile number
  scanf("%s",mob);
  for(int i=0;i<addressBook->contactCount;i++)
      {
      if((strcmp(mob,addressBook->contacts[i].phone))==0)
      {
        for(int j=i;j<addressBook->contactCount;j++)
        {
          addressBook->contacts[j]=addressBook->contacts[j+1];
          addressBook->contactCount--;
        }
        flag=1;
      }
      }
  if(flag==0)
  {
    printf("Invalid number!\n");
  }
  break;
  case 3:
  printf("Enter the Email id");//deleting using email id
  scanf("  %[^\n]",addr);
  for(int i=0;i<addressBook->contactCount;i++)
      {
      if((strcmp(addr,addressBook->contacts[i].email))==0)
      {
        for(int j=i;j<addressBook->contactCount;j++)
        {
          addressBook->contacts[j]=addressBook->contacts[j+1];
          addressBook->contactCount--;
        }
        flag=1;
      }
      }
      if(flag==0)
      {
        printf("Invalid Email id!!");
      }
  break; 

 }
}
int nameVal(AddressBook *addressBook,char* name)
{// Iterate through each character in the name
    for(int i=0;name[i]!=0;i++)
    {
      if(isalpha(name[i]) || name[i]==' '){// Check if the character is an alphabet or a spac
      } // Continue processing if the character is valid
      else{
        // Return 1 if an invalid character is found
        return 1;
      }
    }
    // Return 0 if all characters are valid
    return 0;
}

int mobVal(AddressBook *addressBook,char *phone)
{
  int inval=0,count=0;
    for(int i=0;phone[i]!=0;i++){
      if(!isdigit(phone[i])){
        inval=1;// Set the invalid flag to 1 if a non-digit character is found
        }
      }
      //check the phone number length 
      int len=strlen(phone);
      // Count the number of occurrences of the phone number in the address book
      for(int i=0;i<addressBook->contactCount;i++)
      {
        if(strcmp(addressBook->contacts[i].phone,phone)==0)
        {
          count++;
        }
      }
      if(inval==0&&len==10&&count==0)
      {
        return 0;// Return 0 if the phone number is valid (no invalid characters, length is 10, and not a duplicate)
      }
      else if(count>0)
      {
        return 1;// Return 1 if the phone number is a duplicate
      }
      else
      {
        return 2;// Return 2 if the phone number is invalid (invalid characters or incorrect length)
      }
   }


int emailVal(AddressBook *addressBook,char *email)
{
  int invalemail=0,count=0;
  char* pos=strchr(email,'@');
  // Check if '@' symbol is present and not immediately followed by '.com'
  if(pos != NULL && strstr(email,".com")!=pos+1)
  {
    invalemail=1;
  }
  // Count the number of occurrences of the email in the address book
   for(int i=0;i<addressBook->contactCount;i++)
   {
        if(strcmp(addressBook->contacts[i].email,email)==0)
        {
          count++;
        }
    }
     // Return the appropriate value based on the validation results
      if(count==0 && invalemail==1)
      {
        // Return 0 if the email is valid (no invalid characters, '@' symbol is present and not followed by '.com', and not a duplicate)
        return 0;
      }
      else if(count>0)
      {
        // Return 1 if the email is a duplicate
        return 1;
      }
      else
      {
        // Return 2 if the email is invalid (invalid characters or incorrect format)
        return 2;
      }
}