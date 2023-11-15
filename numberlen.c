#include "shell.h"

/**
 * numberlen - function gets the length of a given number
 * @number: number parameter given
 * Return: Always success
 */
int numberlen(int number)
{
	int count = 0;

	if (number == 0)
		return (1);
	if (number < 0)
		number = -number;
	while (number > 0)
	{
		count++;
		number /= 10;
	}
	return (count);
}
/**
 * *conItoA - Function converts integer to ASCII
 * @number: integer
 * Return: Always success
 */
char *conItoA(int number)
{
	unsigned int n;
	int length = numberlen(number);
	/* pointer to hold the string */
	char *buffer = malloc(sizeof(char) * (length + 1));

	if (buffer == NULL)
	{
		perror("malloc failed");
		return (NULL);
	}
	buffer[length] = '\0';
	if (number == 1)
	{
		buffer[0] = '1';
		return (buffer);
	}
	if (number < 0)
	{
		n = -number;
		buffer[0] = '-';
	}
	else
	{
		n = number;
		buffer[0] = '0';
	}
	while (n > 0)
	{
		buffer[length - 1] = (n % 10) + '0';
		n = n / 10;
		length--;
	}
	return (buffer);
}
