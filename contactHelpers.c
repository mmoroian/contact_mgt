/* -------------------------------
Name:			Mark Moroian
Student number: 126482181
Email:			mmoroian@myseneca.ca
Section:        H
Date:           2019-03-29
----------------------------------
Assignment: 2
Milestone:  4
---------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>


// -------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"


// -------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5


//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}


// pause:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}


// getInt:
int getInt(void)
{
	int Value;
	char NL = 'x';

	while (NL != '\n')
	{
		scanf("%d%c", &Value, &NL);
		if (NL != '\n')
		{
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");

		}
	}


	return Value;
}


// getIntInRange:
int getIntInRange(int min, int max)
{
	int received = getInt();

	while (received < min || received > max)
	{
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		received = getInt();
	}

	printf("\n");

	return received;
}


// yes:
int yes(void)
{
	int flag = 2;
	char letter = '\0';
	char NL = 'x';

	do {
		scanf("%c%c", &letter, &NL);


		if (NL != '\n' && ((letter != 'n' || letter != 'N') || (letter != 'y' || letter != 'Y'))) {

			clearKeyboard();

			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		}
		else if (NL == '\n' && (letter == 'n' || letter == 'N')) {
			flag = 0;
		}
		else if (NL == '\n' && (letter == 'y' || letter == 'Y')) {
			flag = 1;
		}
		else
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");


	} while (flag == 2);

	return flag;
}


// menu:
int menu(void)
{
	int selection;

	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\n");
	printf("Select an option:> ");

	selection = getIntInRange(0, 6);

	return selection;
}


// contactManagerSystem:
void contactManagerSystem(void)
{


	struct Contact contacts[MAXCONTACTS] =
	{
		{
			{ "Rick", { '\0' }, "Grimes" },
			{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
		{ "4161112222", "4162223333", "4163334444" } },
{
{ "Maggie", "R.", "Greene" },
{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
{ "9051112222", "9052223333", "9053334444" } },
{
{ "Morgan", "A.", "Jones" },
{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
{ "7051112222", "7052223333", "7053334444" } },
{
{ "Sasha", {'\0'}, "Williams" },
{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
{ "9052223333", "9052223333", "9054445555" } },
	};




	int check = 0;
	while (check == 0) {


		switch (menu())
		{
		case 1:
			//printf("\n<<< Feature 1 is unavailable >>>\n\n");
			displayContacts(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 2:
			//printf("\n<<< Feature 2 is unavailable >>>\n\n");
			addContact(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;

		case 3:
			//printf("\n<<< Feature 3 is unavailable >>>\n\n");
			updateContact(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;

		case 4:
			//printf("\n<<< Feature 4 is unavailable >>>\n\n");
			deleteContact(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;

		case 5:
			//printf("\n<<< Feature 5 is unavailable >>>\n\n");
			searchContacts(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;

		case 6:
			//printf("\n<<< Feature 6 is unavailable >>>\n\n");
			sortContacts(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;

		case 0:
			printf("Exit the program? (Y)es/(N)o: ");
			if (yes() == 1)
			{
				check = 1;
				printf("\nContact Management System: terminated\n");
				break;
			}
			else
			{
				printf("\n");
				break;
			}

		}

	}
}


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
void getTenDigitPhone(char phoneNum[])
{
	int needInput = 1;
	int i, counter;

	while (needInput == 1) {
		scanf("%10s", phoneNum);
		//scanf("%10[^\n]", phoneNum);												// s or ^ is better?

		clearKeyboard();

		// (String Length Function: validate entry of 10 characters)
		if (strlen(phoneNum) == 10)
		{
			counter = 0;
			for (i = 0; i < 10; i++)
			{
				if (phoneNum[i] >= '0' && phoneNum[i] <= '9')
				{
					counter++;
				}
			}

			if (counter == 10)
			{
				needInput = 0;
			}
			else
			{
				printf("Enter a 10-digit phone number: ");
				needInput = 1;
			}
		}
		else
		{
			printf("Enter a 10-digit phone number: ");
			needInput = 1;
		}

	}
}


// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int i, result = -1;



	for (i = 0; i < size; i++)
	{
		if (strcmp(contacts[i].numbers.cell, cellNum) == 0)
		{
			result = i;
		}

	}
	return result;
}


// displayContactHeader
void displayContactHeader(void)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter
void displayContactFooter(int count)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", count);

}


// displayContact:
void displayContact(const struct Contact *contact)
{
	if ((strcmp(contact->name.middleInitial, "\0")) != 0)
	{
		printf(" %s %s %s\n", contact->name.firstName, contact->name.middleInitial, contact->name.lastName);
	}
	else
	{
		printf(" %s %s\n", contact->name.firstName, contact->name.lastName);
	}

	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);

	if (contact->address.apartmentNumber != 0)
	{

		printf("       %d %s, Apt# %d, %s, %s\n", contact->address.streetNumber, contact->address.street, contact->address.apartmentNumber, contact->address.city, contact->address.postalCode);

	}
	else
	{
		printf("       %d %s, %s, %s\n", contact->address.streetNumber, contact->address.street, contact->address.city, contact->address.postalCode);

	}
}


// displayContacts:														// 2019-03-28
void displayContacts(const struct Contact contacts[], int size)
{
	int i;
	int valid = 0;
	displayContactHeader();

	for (i = 0; i < size; i++)
	{

		if ((strcmp(contacts[i].numbers.cell, "\0")) > 0)
		{
			valid++;
			displayContact(&contacts[i]);
		}
	}

	displayContactFooter(valid);
}


void searchContacts(const struct Contact contacts[], int size)					// V1
{
	char tempStr[11];
	int contNo;
	printf("Enter the cell number for the contact: ");

	getTenDigitPhone(tempStr);

	contNo = findContactIndex(contacts, size, tempStr);

	if (contNo == -1)
	{
		printf("*** Contact NOT FOUND ***\n\n");
	}
	else
	{
		printf("\n");
		displayContact(&contacts[contNo]);
		printf("\n");

	}
}


// addContact:
void addContact(struct Contact contacts[], int size)
{
	int part;
	part = findContactIndex(contacts, size, "");

	if (part == -1)
	{
		printf("*** ERROR: The contact list is full! ***\n\n");
	}
	else
	{
		getContact(&contacts[part]);
		printf("--- New contact added! ---\n\n");
	}
}


void updateContact(struct Contact contacts[], int size)
{
	char tempCell[11];
	int indxNo;

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(tempCell);

	indxNo = findContactIndex(contacts, size, tempCell);

	if (indxNo == -1)
	{
		printf("*** Contact NOT FOUND ***\n\n");
	}
	else
	{
		printf("\nContact found:\n");

		displayContact(&contacts[indxNo]);

		printf("\n");
		printf("Do you want to update the name? (y or n): ");
		if (yes())
		{
			getName(&contacts[indxNo].name);
			//printf("---Contact Updated!---\n");
		}

		printf("Do you want to update the address? (y or n): ");
		if (yes())
		{
			getAddress(&contacts[indxNo].address);
			//printf("---Contact Updated!---\n");
		}

		printf("Do you want to update the numbers? (y or n): ");
		if (yes())
		{
			getNumbers(&contacts[indxNo].numbers);
			//printf("---Contact Updated!---\n");
		}

		printf("--- Contact Updated! ---\n\n");

	}
}


// deleteContact:
void deleteContact(struct Contact contacts[], int size)
{
	char tempCellDel[11];
	int indxDel;

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(tempCellDel);

	indxDel = findContactIndex(contacts, size, tempCellDel);

	if (indxDel == -1)
	{
		printf("*** Contact NOT FOUND ***\n");
	}
	else
	{
		printf("\nContact found:\n");

		displayContact(&contacts[indxDel]);

		printf("\n");
		printf("CONFIRM: Delete this contact? (y or n): ");
		if (yes())
		{

			contacts[indxDel].numbers.cell[0] = '\0';


			printf("--- Contact deleted! ---\n\n");
		}
		else
		{
			printf("\n");
		}
	}
}


// sortContacts:
void sortContacts(struct Contact contacts[], int size)
{
	//printf("<<< Feature to sort is unavailable >>>\n\n");



int i, k, m;
struct Contact temp;

for (i = 0; i < size ; i++) {
	m = i;
	for (k = i + 1; k < size  ; k++)
		if (strcmp(contacts[k].numbers.cell, contacts[m].numbers.cell) < 0)
		{
			m = k;
		}
	if (m != i) {
		temp = contacts[i];
		contacts[i] = contacts[m];
		contacts[m] = temp;

	}
}
printf("--- Contacts sorted! ---\n\n");

}