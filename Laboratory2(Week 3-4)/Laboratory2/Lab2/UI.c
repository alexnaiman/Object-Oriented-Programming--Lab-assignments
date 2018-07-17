#include "UI.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
UI* createUI(Controller* c)
{
	UI* ui = (UI*)malloc(sizeof(UI));
	ui->ctrl = c;

	return ui;
}

void destroyUI(UI * ui)
{
	// first destroy the controller
	destroyController(ui->ctrl);
	// free the UI memory
	free(ui);
}

/*
Prints the available menu for the problem
Input: -
Output: the menu is printed at the console
*/
void printMenu()
{
	printf("\n**********************************************************\n");
	printf("1 - add a product.\n");
	printf("2 - list all products.\n");
	printf("3 - delete a product\n");
	printf("4 - update a product\n");
	printf("5 - display all the products whose names contain a given string sorted by quantity\n");
	printf("6 - display all the products whose names contain a given string sorted by name\n");
	printf("7 - display all products of a given category (if the category is empty, all types of food will be considered) whose expiration dates are close (expire in the following given X days)\n");
	printf("8 - filter products bigger than a given quantity.\n");
	printf("9 - undo\n");
	printf("10 - redo\n");
	printf("11 - filter products bigger than a given quantity \n");



	printf("0 - to exit.\n");
	//printf("3 - to delete a produ")
	printf("\n**********************************************************\n");
}

/*
Verifies if the given command is valid (is either 1, 2, 3or 0)
Input: command - integer
Output: 1 - if the command is valid
0 - otherwise
*/
int validCommand(int command)
{
	if (command >= 0 && command <= 12)
		return 1;
	return 0;
}

/*
Reads an integer number from the keyboard. Asks for number while read errors encoutered.
Input: the message to be displayed when asking the user for input.
Returns the number.
*/
int readIntegerNumber(const char* message)
{
	char s[16];
	int res = 0;
	int flag = 0;
	int r = 0;

	while (flag == 0)
	{
		printf(message);
		scanf("%s", s);

		r = sscanf(s, "%d", &res);	// reads data from s and stores them as integer, if possible; returns 1 if successful
		flag = (r == 1);
		if (flag == 0)
			printf("Error reading number!\n");
	}
	return res;
}

/*
Reads a string with spaces from the standard input.
Input:	message - string, message to be shown to the user.
maxStrSize - the maximum size for the string to be read
Output: the string that was read.
*/
void readStringWithSpaces(const char* message, int maxStrSize, char str[])
{
	printf(message);
	int flag = 0;
	while (flag == 0) {
		fgets(str, maxStrSize, stdin);
		// the newline is also read so we must eliminate it from the string
		int size = strlen(str) - 1;
		if (str[size] == '\n')
			str[size] = '\0';
		if (strlen(str) > 0)
			flag = 1;
	}
}

void readType(char* str) {
	int flag = 0;
	while (flag == 0) {
		printf("Please input the type of the product: ");
		fgets(str, 50, stdin);
		// the newline is also read so we must eliminate it from the string
		int size = strlen(str) - 1;
		if (str[size] == '\n')
			str[size] = '\0';
		if (strlen(str) > 0)
			flag = 1;
		if (isValidType(str)) {
			flag = 1;
		}
		else
		{
			printf("Error : invalid type\n");
			flag = 0;
		}
	}
}


void readYesOrNo(char* str) {
	int flag = 0;
	while (flag == 0) {
		fgets(str, 50, stdin);
		// the newline is also read so we must eliminate it from the string
		int size = strlen(str) - 1;
		if (str[size] == '\n')
			str[size] = '\0';
		if (strlen(str) > 0)
			flag = 1;
		if (strcmp(str, "yes") || strcmp(str, "no")) {
			flag = 1;
		}
		else
		{
			printf("Error : invalid type\n");
			flag = 0;
		}
	}
}
/*
Reads a date in format yyyy-mm-dd from the standard input.
Input:	message - string, message to be shown to the user.
-struct of type tm - the date struct
Output: the date that was read.
*/
void readDate(struct tm* s, char message[]) {
	int y = 0, m = 0, d = 0;
	int flag = 0;
	int r = 0;
	char aux[50];
	while (flag == 0)
	{
		printf("%s", message);
		scanf("%s", aux);
		r = sscanf(aux, "%d-%d-%d", &y, &m, &d);	// reads data from s and stores them as integer, if possible; returns 3 if successful
		flag = (r == 3);
		if (flag == 0)
			printf("Error reading number!\n");
		else {
			s->tm_year = y;
			s->tm_mon = m;
			s->tm_mday = d;
			time_t t = time(NULL);
			time_t date = mktime(s);
			double seconds = difftime(date, t);
			if (seconds > 0) {
				flag = 0;
			}
		}
	}
}



int addProductUI(UI* ui)
{
	// read the product's data
	char name[50], type[50];
	double quantity;
	fgetc(stdin); // read the newline, to prevent it from going further to fgets
	readStringWithSpaces("Please input the name: ", 50, name);
	readType(type);
	quantity = readIntegerNumber("Please input the quantity: ");
	struct tm s;
	readDate(&s, "Please input the expiration date in format yyyy-mm-dd: ");
	return addProductCtrl(ui->ctrl, name, type, quantity, s);
}

void categoryExpirationUI(UI* ui) {
	int days;
	days = readIntegerNumber("Please input the number of days: ");
	printf("Enter product to search:\n");
	char x, mystring[20];
	int i = 0;
	getchar();
	while (x = getchar())
	{
		if (x == '\n' || x == '\0')
		{
			break;
		}
		else
		{
			mystring[i] = x;
			i++;
		}
		mystring[i] = 0;
	}
	if (i == 0) {
		struct tm s;
		ProductRepo* b = filterByDate(ui->ctrl->repo, days, &s);
		if (getRepoLength(b) < 1) {
			printf("There are no such products\n");
			return;
		}
		for (int i = 0; i < getRepoLength(b); i++) {
			char aux[200];
			toString(getProductOnPos(b, i), aux);
			printf("%s\n", aux);
		}
		destroyRepo(b);
	}
	else
	{
		if (!isValidType(mystring))
			return;
		struct tm s;
		ProductRepo* a = getProductByType(ui->ctrl, mystring);
		ProductRepo* b = filterByDate(a, days, &s);
		if (getRepoLength(b) < 1) {
			printf("There are no such products\n");
			return;
		}
		for (int i = 0; i < getRepoLength(b); i++) {
			char aux[200];
			toString(getProductOnPos(b, i), aux);
			printf("%s\n", aux);
		}
		destroyRepo(a);
		destroyRepo(b);

	}
}
void listAllProducts(UI* ui)
{
	ProductRepo* repo = getRepo(ui->ctrl);
	int length = getRepoLength(repo);

	if (length == 0)
	{
		char* str = "There are no stored products.";
		printf("%s \n", str);
	}

	for (int i = 0; i < getRepoLength(repo); i++)
	{
		char str[200];
		toString(getProductOnPos(repo, i), str);
		printf("%s\n", str);
	}
}
int deleteUI(UI* ui) {
	// read the product's data
	char name[50], type[50];
	fgetc(stdin);
	readStringWithSpaces("Please input the name: ", 50, name);
	readType(type);
	return deleteCtrl(ui->ctrl, name, type);
}

void updateUI(UI* ui) {
	char name[50], type[50], newName[50], newType[50];
	double quantity;
	fgetc(stdin);
	readStringWithSpaces("Please input the name: ", 50, name);
	readType(type);
	readStringWithSpaces("Please input the new name: ", 50, newName);
	readType(newType);
	quantity = readIntegerNumber("Please input the quantity: ");
	struct tm s;
	readDate(&s, "Please input the expiration date in format yyyy-mm-dd: ");

	if (updateCtrl(ui->ctrl, newName, newType, quantity, s, name, type)) {
		printf("\nProduct updated successfully");
		_CrtDumpMemoryLeaks();

	}
	else {
		printf("\nCannot find product!\n");
	}
}

void searchUIquantity(UI* ui) {
	char s[200];
	printf("Enter product to search:\n");
	char x, mystring[20];
	int i = 0;
	getchar();
	while (x = getchar())
	{
		if (x == '\n' || x == '\0')
		{
			break;
		}
		else
		{
			mystring[i] = x;
			i++;
		}
		mystring[i] = 0;
	}
	printf("\nDescending? ");
	readYesOrNo(s);
	int reverse = strcmp(s, "yes") ? 1 : 0;
	if (i == 0) {
		ProductRepo* repo = reverse ? sort(ui->ctrl, &sortByQuantity) : sort(ui->ctrl, &sortByQuantityDesc);
		int length = getRepoLength(repo);

		if (length == 0)
		{
			char* str = "There are no stored products.";
			printf("%s \n", str);
		}

		for (int i = 0; i < getRepoLength(repo); i++)
		{
			char str[200];
			toString(getProductOnPos(repo, i), str);
			printf("%s\n", str);
		}
		//destroyRepo(repo);
	}
	else
	{

		ProductRepo* a = reverse ? searchCtrl(ui->ctrl, mystring, &sortByQuantity) : searchCtrl(ui->ctrl, mystring, &sortByQuantityDesc);
		if (getRepoLength(a) == 0)
			printf("Cannot find any element with that name");
		else
			for (int i = 0; i < getRepoLength(a); i++) {
				char aux[200];
				toString(getProductOnPos(a, i), aux);
				printf("%s\n", aux);

			}
		destroyRepo(a);
	}
}

void filterByQuantityBigggerUI(UI* ui) {
	double quantity = readIntegerNumber("Please input the quantity\n");
	ProductRepo* auxRepo = filterByQuantity(ui->ctrl, quantity, &filterQuantityBigger);
	if (getRepoLength(auxRepo) == 0)
	{
		destroyRepo(auxRepo);
		printf("Cannot find any such elements");
		return;
	}
	else
		for (int i = 0; i < getRepoLength(auxRepo); i++) {
			char aux[200];
			toString(getProductOnPos(auxRepo, i), aux);
			printf("%s\n", aux);

		}
	destroyRepo(auxRepo);
}


void filterByQuantitySmillerUI(UI* ui) {
	double quantity = readIntegerNumber("Please input the quantity\n");
	ProductRepo* auxRepo = filterByQuantity(ui->ctrl, quantity, &filterQuantitySmaller);
	if (getRepoLength(auxRepo) == 0)
	{
		destroyRepo(auxRepo);
		printf("Cannot find any such elements");
		return;
	}
	else
		for (int i = 0; i < getRepoLength(auxRepo); i++) {
			char aux[200];
			toString(getProductOnPos(auxRepo, i), aux);
			printf("%s\n", aux);

		}
	destroyRepo(auxRepo);
}

void searchUIName(UI* ui) {

	printf("Enter product to search:\n");
	char x, mystring[20];
	int i = 0;
	getchar();
	while (x = getchar())
	{
		if (x == '\n' || x == '\0')
		{
			break;
		}
		else
		{
			mystring[i] = x;
			i++;
		}
		mystring[i] = 0;
	}
	char s[200];
	printf("\nDescending? ");
	readYesOrNo(s);
	int reverse = strcmp(s, "yes") ? 1 : 0;
	if (i == 0) {
		ProductRepo* repo = reverse ? sort(ui->ctrl, &sortByNameDesc) : sort(ui->ctrl, &sortByName);
		int length = getRepoLength(repo);

		if (length == 0)
		{
			char* str = "There are no stored products.";
			printf("%s \n", str);
		}

		for (int i = 0; i < getRepoLength(repo); i++)
		{
			char str[200];
			toString(getProductOnPos(repo, i), str);
			printf("%s\n", str);
		}
		//destroyRepo(repo);
	}
	else
	{

		ProductRepo* a = reverse ? searchCtrl(ui->ctrl, mystring, &sortByNameDesc) : searchCtrl(ui->ctrl, mystring, &sortByName);
		if (getRepoLength(a) == 0)
			printf("Cannot find any element with that name");
		else
			for (int i = 0; i < getRepoLength(a); i++) {
				char aux[200];
				toString(getProductOnPos(a, i), aux);
				printf("%s\n", aux);

			}
		destroyRepo(a);
	}
}



void filterCategoryQuantity(UI* ui) {
	char type[50];
	readType(type);
	ProductRepo* auxRepo = getProductByType(ui->ctrl, type);
	Controller* c2 = createController(auxRepo);
	ProductRepo* auxRepo2 = sort(c2, &sortByQuantityDesc);
	for (int i = 0; i < getRepoLength(auxRepo2); i++) {
		char aux[200];
		toString(getProductOnPos(auxRepo, i), aux);
		printf("%s\n", aux);

	}
	destroyController(c2);

}


void startUI(UI* ui)
{
	while (1)
	{
		printMenu();
		int command = readIntegerNumber("Input command: ");
		while (validCommand(command) == 0)
		{
			printf("Please input a valid command!\n");
			command = readIntegerNumber("Input command: ");
		}
		if (command == 0) {
			destroyUI(ui);
			break;
		}
		switch (command)
		{
		case 1:
		{
			int res = addProductUI(ui);
			if (res == 1)
				printf("Product successfully added.\n");
			else
				if (res == -1)
					printf("There was another product with the same key, quantity updated!");
				else
					printf("Error! product could not be added, as there is another product with the same symbol combination!\n");
			break;
		}
		case 2:
		{
			listAllProducts(ui);
			break;
		}
		case 9:
		{
			int res = 1;
				undo(ui->ctrl);
			if (res == 1)
				printf("Undo was successful.\n");
			else
				printf("No more undos to be made.\n");
			break;
		}
		case 10:
		{
			int res = 1;
			redo(ui->ctrl);
			if (res == 1)
				printf("Redo was successful.\n");
			else
				printf("No more undos to be made.\n");
			break;
		}
		case 3: {
			if (deleteUI(ui)) {
				printf("\nProduct successfully deleted\n");
			}
			else {
				printf("\nCannot find that product");
			}
			break;
		}
		case 4: {
			updateUI(ui);
			break;

		}
		case 5: {
			searchUIquantity(ui);
			break;
		}
		case 6: {
			searchUIName(ui);
			break;
		}
		case 7: {
			categoryExpirationUI(ui);
			break;
		}
		case 8: {
			filterByQuantityBigggerUI(ui);
			break;
		}
		case 11: {
			filterByQuantitySmillerUI(ui);
			break;
		}
		case 12: {

			filterCategoryQuantity(ui);
		}
		}
	}
}