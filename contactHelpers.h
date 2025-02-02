/* -------------------------------
Name:			Mark Moroian
Student number:	126482181
Email:			mmoroian@myseneca.ca
Section:		H
Date:			2019-03-27
----------------------------------
Assignment: 2
Milestone:  4
----------------------------------------------------------------------
Description: This header file modularizes general helper functions to
             help reduce redundant coding for common repetitive tasks.
----------------------------------------------------------------------*/


// Hint:  This header file now has functions with parameters referring to 
//        the struct Contact type so be sure to include the contacts.h header:
#include "contacts.h"


//--------------------------------
// Function Prototypes
//--------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function prototypes here...              |
// +-------------------------------------------------+

// Clear the standard input buffer
// clearKeyboard:
void clearKeyboard(void);


// pause:
void pause(void);


// getInt:
int getInt(void);


// getIntInRange:
int getIntInRange(int min, int max);


// yes:
int yes(void);


// menu:
int menu(void);


// contactManagerSystem:
void contactManagerSystem(void);


// Generic function to get a ten-digit phone number:
// getTenDigitPhone:
void getTenDigitPhone(char phoneNum[]);


// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]);


// displayContactHeader:
void displayContactHeader(void);


// displayContactFooter:
void displayContactFooter(int);


// displayContact:
void displayContact(const struct Contact *contact);


// displayContacts:
void displayContacts(const struct Contact contacts[], int size);


// searchContacts:
void searchContacts(const struct Contact contacts[], int size);


// addContact:
void addContact(struct Contact contacts[], int size);


// updateContact:
void updateContact(struct Contact contacts[], int size);


// deleteContact:
void deleteContact(struct Contact contacts[], int size);


// sortContacts:
void sortContacts(struct Contact contacts[], int size);