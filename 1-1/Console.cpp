#include<iostream>
#include<string.h>

int main(int argc, char* argv[])
{
	if (argc == 2)
	{
		if ((strcmp(argv[1], "-h") == 0) || ((strcmp(argv[1], "--help") == 0)))
		{
			printf("\nList of available commands: \n\t -h - call the list of available commands \n\t -c - basic operations between two numbers \n\t -x - output a number in the 16-digit number system \n\t -t - output a table with basic data types.\n");
		}
		else if (strcmp(argv[1], "-t") == 0)
		{
			printf("\n1) Integer - %d", sizeof(int));
			printf("\n2) Long integer - %d", sizeof(long int));
			printf("\n3) Char - %d", sizeof(char));
			printf("\n4) Wchar_t - %d", sizeof(wchar_t));
			printf("\n5) Boolean - %d", sizeof(bool));
			printf("\n6) Short integer - %d", sizeof(short int));
			printf("\n7) Float - %d", sizeof(float));
			printf("\n8) Double - %d\n", sizeof(double));
			printf("\n9) Long long - %d\n", sizeof(long long));
			printf("\n10) Long double - %d\n", sizeof(long double));
		}
	}
	else if ((argc == 3) && (((strcmp(argv[1], "-x") == 0)) || ((strcmp(argv[1], "--hex") == 0))))
	{
		int a = atoi(argv[2]);
		printf("\nHex of %x\n", a);
	}
	else if ((argc == 5) && (((strcmp(argv[1], "-c") == 0)) || ((strcmp(argv[1], "--calc") == 0))))
	{
		char point = 0;
		int a = atoi(argv[2]);
		int b = atoi(argv[4]);
		if (strcmp(argv[3], "+") == 0)
			point = '1';
		else if (strcmp(argv[3], "-") == 0)
			point = '2';
		else if (strcmp(argv[3], "*") == 0)
			point = '3';
		else if ((strcmp(argv[3], "/") == 0) && (b != 0))
			point = '4';
		else if ((strcmp(argv[3], "/") == 0) && (b == 0))
			point = '5';

		switch (point)
		{
			case'1':
			{
				int r = a + b;
				printf("\nResult: %d\n", r);
			break;
			}
			case'2':
			{
				int r = a - b;
				printf("\nResult: %d\n", r);
				break;
			}
			case'3':
			{
				int r = a * b;
				printf("\nResult: %d\n", r);
				break;
			}
			case'4':
			{
				int r = a / b;
				printf("\nResult: %d\n", r);
				break;
			}
			case'5':
			{
				printf("\nFail: division by 0\n");
				break;
			}
		}
	}
	else printf("\nWrong command. Type -h or --help to see the list of available commands\n");
	return 0;
}