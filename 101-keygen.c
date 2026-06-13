#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generates random valid passwords for the program 101-crackme.
 *
 * Return: 0
 */
int main(void)
{
	int sum, character, index;
	char password[100];

	srand(time(NULL)); /* sets the seed/starting point for rand() */
	sum = 0; /* sum of the character */
	index = 0;

	while (sum < 0xad4)
	{
		character = rand() % 95 +32; /** some large number is produced by rand,
					      * % 95 → squeezes it into the range 0–94,
					      * + 32 → shifts it to 32–126, which is the
					      * printable ASCII range (space through ~
					      */
		if (sum + character > 0xad4)
			character = 0xad4 - sum;

		password[index] = character;
		sum += character;
		index++;
	}

	password[index] = '\0';
	puts(password);

	return(0);
}
