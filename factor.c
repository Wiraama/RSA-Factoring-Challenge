#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
/**
 * factorize - fction to factorize number
 * @number: given value
 *
 * Return: nothing
 */
void factorize(unsigned long int number)
{
	int i, j;

	/**loop to factorize**/
	for (i = 2; i <= number / 2; i++)
	{
		/** checking if rem of number div by i is 0**/
		if (number % i == 0)
		{
			j = number / i;
			printf("%lu=%d*%d\n", number, i, j);
			return;
		}
	}
}

/**
 * main - main fuction
 * @argc: argument 1
 * @argv: argument 2
 *
 * Return: zero
 */
int main(int argc, char *argv[])
{
	int value;
	FILE *file; /**accessing the file in the terminal**/

	if (argc != 2)
	{
		printf("Error...Usage: %s <file>", argv[0]);
		return (0);
	}

	file = fopen(argv[1], "r"); /**opening file**/
	if (file == NULL)
	{
		printf("%s Is Empty", argv[1]);
		return (0);
	}
	/** looop to go through file**/
	while (fscanf(file, "%d", &value) == 1)
		factorize(value);

	printf("\n");

	struct rusage usage;
	getrusage(RUSAGE_SELF, &usage);

	printf("real    %ldm%.3fs\n", usage.ru_utime.tv_sec / 60, usage.ru_utime.tv_sec % 60 + usage.ru_utime.tv_usec / 1000000.0);
	printf("user    %ldm%.3fs\n", usage.ru_stime.tv_sec / 60, usage.ru_stime.tv_sec % 60 + usage.ru_stime.tv_usec / 1000000.0);
	printf("sys     %ldm%.3fs\n", usage.ru_stime.tv_sec / 60, usage.ru_stime.tv_sec % 60 + usage.ru_stime.tv_usec / 1000000.0);
	fclose(file);
	return (0);
}
