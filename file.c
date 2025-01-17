#include <stdio.h>
#include "file.h"

void loadContactsFromFile(AddressBook *addressBook)
{
  FILE* fptr=fopen("contacts.txt","r");
  if(fptr==NULL)
  {
    printf("File not present!");
    return ;
  }
  fscanf(fptr,"%d\n",&addressBook->contactCount);
  for(int i=0;i<addressBook->contactCount;i++)
  {
    fscanf(fptr,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
  }
  fclose(fptr);
}

void saveContactsToFile(AddressBook *addressBook)
{
  FILE* fptr=fopen("contacts.txt","w");
  fprintf(fptr,"%d\n",addressBook->contactCount);
  for(int i=0;i<addressBook->contactCount;i++)
  {
    fprintf(fptr,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
  }
  fclose(fptr);
}
