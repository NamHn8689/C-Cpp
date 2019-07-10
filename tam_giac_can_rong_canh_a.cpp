#include <stdio.h>
#include <conio.h>

int main()
{
	int a;
	scanf("%d", &a);
	for (int i = 1; i < a; i++)
	{
		for (int j = a - i; j > 0; j--)
			printf(" ");
		for (int k = 1; k <= 2 * i - 1; k++)

			if (k == 2 * i - 1 || k == 1)
				printf("*");
			else
				printf(" ");

		printf("\n");
	}
	for (int l = 1; l < 2 * a; l++)
		printf("*");
	getch();
}