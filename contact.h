#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[100];
    int contactCount;
} AddressBook;

void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
int nameVal(AddressBook *addressBook,char *name);
int mobVal(AddressBook *addressBook,char* phone);
int emailVal(AddressBook *addressBook,char *email);
void saveContactsToFile(AddressBook *AddressBook);
void loadContactsFromFile(AddressBook *addressBook);

#endif