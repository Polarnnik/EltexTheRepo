//
// Created by polarnik on 09.11.2024.
//

#ifndef CONTACTS_H
#define CONTACTS_H


#define MAX_CONTACTS 100
#define MAX_STRING_LENGTH 50

typedef struct {
    char lastName[MAX_STRING_LENGTH];
    char firstName[MAX_STRING_LENGTH];
    char workPlace[MAX_STRING_LENGTH];
    char position[MAX_STRING_LENGTH];
    char phone[MAX_STRING_LENGTH];
    char email[MAX_STRING_LENGTH];
    char socialMedia[MAX_STRING_LENGTH];
    char messenger[MAX_STRING_LENGTH];
} Contact;

void readInput(char* buffer, int length);
Contact* createContact();
void displayContact(Contact* contact);
void editContact(Contact* contact);

#endif //CONTACTS_H
