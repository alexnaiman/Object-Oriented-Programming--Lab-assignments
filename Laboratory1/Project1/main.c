#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.system.h>

typedef struct Range { // struct we use to return the start point and the end point of the subsequence
	int start, end;
} Range;

/*
	This function checks if a number is prime or not
	in:
		n - integer - the number we need to check its primality
	out:
		0 if it is not prime
		1 otherwise
*/
int IsPrime(int n) {
	if (n < 2)
		return 0;
	for (int i = 2; i <= n / 2; i++)
		if (n % i == 0)
			return 0;
	return 1;
}

/*
	This function checks if the given string can be converted to integer
	in:
		a - array of characters
	out:
		1 - if can be converted
		0 - otherwise
*/
int CanBeInt(char a[]) {
	int len = strlen(a);
	for (int i = 0; i < len; i++) {
		if (!isdigit(a[i]))
			return 0;
	}
	return 1;
}

/*
	Function that prints a given range from a given array
	in:
		- v - the vector of ints
		- start - the starting point -int
		- end - the ending point
*/
int printFromStartToEnd(int v[], int start, int end) {
	printf("\nThe longest subsequence with the given property is:\n");
	for (int i = start; i < end; i++)
		printf("\t%d\n", v[i]);
}
/*
	Function that returns all the prime numbers smaller than a given number
	in:
		n - integer - the given number
		v - array of integers where to save all the prime numbers

*/
void allPrimeNumbers(int n, int v[]) {
	int j = 0;
	for (int i = 2; i <= n; i++)
		if (IsPrime(i))
		{
			v[j] = i;
			j++;
		}
	v[j] = -1;
}

/*
	Function that returns the start and the end points for the longest subsequence with the given property
	in:
		n - the length of the array - integer
		v - the array of integers
	out:
		li - range - type of Range
*/
 struct Range increasingSumIsPrime(int n, int v[50]) {
	 int maxNumber = -1, pos = -1, firstPos = -1;
	 for (int i = 0; i < n - 1; i++) {
		 int poz = i;
		 int l = 1;
		 while (i < n - 1 && IsPrime(v[i] + v[i + 1]) && v[i] < v[i + 1]) {
			 i++;
			 l++;
		 }
		 if (l > maxNumber) {
			 maxNumber = l;
			 firstPos = poz;
		 }

	 }
	 Range li;
	 li.start = firstPos;
	 li.end = firstPos + maxNumber;
	 return li;
 }

 /*
	Our main functions
 */
 void twinNumbers(int n, int v[]) {
	 int len = 0, number = 2;

	 while (n > 0) {
		 if (IsPrime(number) && IsPrime(number + 2))
		 {
			 n--;
			 v[len] = number;
			 len++;
		 }
		 number++;
	 }
 }
int main()
{
	int n, v[50];
	while (1) {
		printf("Options: \n");
		printf("\t1. Generate all the prime numbers smaller than a given natural number n.\n");
		printf("\t2. Given a vector of numbers, find the longest increasing contiguous subsequence, such the sum of that any 2 consecutive elements is a prime number.\n");
		printf("\t3.Determine the first n pairs of twin numbers, where n is a given natural and non-null number. Two prime numbers p and q are called twin if q + p = 2.");
		printf("\t0. Exit\n");
		printf("Select one from the above \n");
		char command[50];
		scanf("%s", &command);
		if (CanBeInt(command) != 1)
		{
			printf("Invalid input - input not recognised as an integer, please try again.");
			continue;
		}
		int convertedCommand = atoi(command);
		if (convertedCommand == 1)
		{
			while (1) {
				printf("Give value: \n\t n=");
				char auxNumber[50];
				scanf("%s", auxNumber);
				if (CanBeInt(auxNumber) != 1) {
					printf("Invalid input - input not recognised as an integer, please try again.\n");
					continue;
				}
				n = atoi(auxNumber);
				int v[50];
				allPrimeNumbers(n, v);
				int aux = v[0], i=0;
				printf("All prime numbers smaller than %d are\n", n);
				while (v[i] != -1) {
					printf("%d\n", v[i]);
					i++;
				}
				break;

			}
		}
		else if (convertedCommand == 2) {
			while (1) {
				printf("Give value: \n\t n=");
				char auxNumber[50];
				scanf("%s", auxNumber);
				if (CanBeInt(auxNumber) != 1) {
					printf("Invalid input - input not recognised as an integer, please try again.\n");
					continue;
				}
				n = atoi(auxNumber);
				for (int i = 0; i < n; i++)
				{
					printf("v[%d]=", i);
					char temp[50];
					scanf("%s", &temp);
					if (CanBeInt(temp))
					{
						v[i] = atoi(temp);
					}
					else {
						printf("Invalid input - input not recognised as an integer, please try again.\n");
						i--;
					}
				}
				Range l = increasingSumIsPrime(n, v);
				printFromStartToEnd(v, l.start, l.end);
				break;
			}
		}
		else if (convertedCommand == 0) {
			break;
		}
		else if (convertedCommand == 3) {

			while (1) {
				printf("Give value: \n\t n=");
				char auxNumber[50];
				scanf("%s", auxNumber);
				if (CanBeInt(auxNumber) != 1) {
					printf("Invalid input - input not recognised as an integer, please try again.\n");
					continue;
				}
				n = atoi(auxNumber);
				int v[100];
				twinNumbers(n, v);
				printf("The first twin pairs are:\n");
				for (int i = 0; i < n; i++) {
					printf("\t%d %d\n", v[i], v[i]+2);
				}
				break;
			}
		}
	}
		
	
	system("pause");
	return 0;

}