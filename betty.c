#include <stdio.h>

/*
** This is a simple C program
** It demonstrates proper naming conventions
*/

int add_numbers(int num1, int num2)
{
	return (num1 + num2);
}

int main(void)
{
	int x = 5;
	int y = 7;
	int sum = add_numbers(x, y);

	printf("The sum of %d and %d is %d\n", x, y, sum);

	return (0);
}

