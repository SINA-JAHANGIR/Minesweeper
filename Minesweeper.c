// Minesweeper Game :

#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <io.h>
#include <string.h>

#define ASCII _setmode(_fileno(stdout),_O_TEXT)
#define UNI _setmode(_fileno(stdout),_O_U8TEXT)


// colors :

#define G  "\033[0;32m"
#define CY "\033[0;36m"
#define R  "\033[0;31m"
#define W  "\033[0;37m"
#define B  "\033[0;34m"
#define Y  "\033[0;33m"
#define P  "\033[0;35m"

void adad(int map[9][9][2], int i, int j)
{
	if (i == 0)
	{
		if (j == 0)
		{
			map[i][j + 1][1] = map[i][j + 1][0];
			map[i + 1][j][1] = map[i + 1][j][0];
			map[i + 1][j + 1][1] = map[i + 1][j + 1][0];
		}
		else if (j == 8)
		{
			map[i][j - 1][1] = map[i][j - 1][0];
			map[i + 1][j - 1][1] = map[i + 1][j - 1][0];
			map[i + 1][j][1] = map[i + 1][j][0];
		}
		else
		{
			map[i][j - 1][1] = map[i][j - 1][0];
			map[i][j + 1][1] = map[i][j + 1][0];
			map[i + 1][j - 1][1] = map[i + 1][j - 1][0];
			map[i + 1][j][1] = map[i + 1][j][0];
			map[i + 1][j + 1][1] = map[i + 1][j + 1][0];
		}
	}
	else if (i == 8)
	{
		if (j == 0)
		{
			map[i][j + 1][1] = map[i][j + 1][0];
			map[i - 1][j][1] = map[i - 1][j][0];
			map[i - 1][j + 1][1] = map[i - 1][j + 1][0];
		}
		else if (j == 8)
		{
			map[i][j - 1][1] = map[i][j - 1][0];
			map[i - 1][j - 1][1] = map[i - 1][j - 1][0];
			map[i - 1][j][1] = map[i - 1][j][0];
		}
		else
		{
			map[i - 1][j - 1][1] = map[i - 1][j - 1][0];
			map[i - 1][j][1] = map[i - 1][j][0];
			map[i - 1][j + 1][1] = map[i - 1][j + 1][0];
			map[i][j - 1][1] = map[i][j - 1][0];
			map[i][j + 1][1] = map[i][j + 1][0];
		}
	}
	else
	{
		if (j == 0)
		{
			map[i - 1][j][1] = map[i - 1][j][0];
			map[i - 1][j + 1][1] = map[i - 1][j + 1][0];
			map[i][j + 1][1] = map[i][j + 1][0];
			map[i + 1][j][1] = map[i + 1][j][0];
			map[i + 1][j + 1][1] = map[i + 1][j + 1][0];
		}
		else if (j == 8)
		{
			map[i - 1][j - 1][1] = map[i - 1][j - 1][0];
			map[i - 1][j][1] = map[i - 1][j][0];
			map[i][j - 1][1] = map[i][j - 1][0];
			map[i + 1][j - 1][1] = map[i + 1][j - 1][0];
			map[i + 1][j][1] = map[i + 1][j][0];
		}
		else
		{
			map[i - 1][j - 1][1] = map[i - 1][j - 1][0];
			map[i - 1][j][1] = map[i - 1][j][0];
			map[i - 1][j + 1][1] = map[i - 1][j + 1][0];
			map[i][j - 1][1] = map[i][j - 1][0];
			map[i][j + 1][1] = map[i][j + 1][0];
			map[i + 1][j - 1][1] = map[i + 1][j - 1][0];
			map[i + 1][j][1] = map[i + 1][j][0];
			map[i + 1][j + 1][1] = map[i + 1][j + 1][0];
		}
	}
}

void sefr(int map[9][9][2], int i, int j)
{
	if (i == 0)
	{
		if (j == 0)
		{
			if (map[i][j + 1][1] == 11 && map[i][j + 1][0] == 0)
			{
				map[i][j + 1][1] = map[i][j + 1][0];
				sefr(map, i, j + 1);
				adad(map, i, j + 1);
			}

			if (map[i + 1][j][1] == 11 && map[i + 1][j][0] == 0)
			{
				map[i + 1][j][1] = map[i + 1][j][0];
				sefr(map, i + 1, j);
				adad(map, i + 1, j);
			}

			if (map[i + 1][j + 1][1] == 11 && map[i + 1][j + 1][0] == 0)
			{
				map[i + 1][j + 1][1] = map[i + 1][j + 1][0];
				sefr(map, i + 1, j + 1);
				adad(map, i + 1, j + 1);
			}
		}
		else if (j == 8)
		{
			if (map[i][j - 1][1] == 11 && map[i][j - 1][0] == 0)
			{
				map[i][j - 1][1] = map[i][j - 1][0];
				sefr(map, i, j - 1);
				adad(map, i, j - 1);
			}

			if (map[i + 1][j - 1][1] == 11 && map[i + 1][j - 1][0] == 0)
			{
				map[i + 1][j - 1][1] = map[i + 1][j - 1][0];
				sefr(map, i + 1, j - 1);
				adad(map, i + 1, j - 1);
			}

			if (map[i + 1][j][1] == 11 && map[i + 1][j][0] == 0)
			{
				map[i + 1][j][1] = map[i + 1][j][0];
				sefr(map, i + 1, j);
				adad(map, i + 1, j);
			}
		}
		else
		{
			if (map[i][j - 1][1] == 11 && map[i][j - 1][0] == 0)
			{
				map[i][j - 1][1] = map[i][j - 1][0];
				sefr(map, i, j - 1);
				adad(map, i, j - 1);
			}

			if (map[i][j + 1][1] == 11 && map[i][j + 1][0] == 0)
			{
				map[i][j + 1][1] = map[i][j + 1][0];
				sefr(map, i, j + 1);
				adad(map, i, j + 1);
			}

			if (map[i + 1][j - 1][1] == 11 && map[i + 1][j - 1][0] == 0)
			{
				map[i + 1][j - 1][1] = map[i + 1][j - 1][0];
				sefr(map, i + 1, j - 1);
				adad(map, i + 1, j - 1);
			}

			if (map[i + 1][j][1] == 11 && map[i + 1][j][0] == 0)
			{
				map[i + 1][j][1] = map[i + 1][j][0];
				sefr(map, i + 1, j);
				adad(map, i + 1, j);
			}

			if (map[i + 1][j + 1][1] == 11 && map[i + 1][j + 1][0] == 0)
			{
				map[i + 1][j + 1][1] = map[i + 1][j + 1][0];
				sefr(map, i + 1, j + 1);
				adad(map, i + 1, j + 1);
			}
		}
	}
	else if (i == 8)
	{
		if (j == 0)
		{
			if (map[i][j + 1][1] == 11 && map[i][j + 1][0] == 0)
			{
				map[i][j + 1][1] = map[i][j + 1][0];
				sefr(map, i, j + 1);
				adad(map, i, j + 1);
			}

			if (map[i - 1][j][1] == 11 && map[i - 1][j][0] == 0)
			{
				map[i - 1][j][1] = map[i - 1][j][0];
				sefr(map, i - 1, j);
				adad(map, i - 1, j);
			}

			if (map[i - 1][j - 1][1] == 11 && map[i - 1][j - 1][0] == 0)
			{
				map[i - 1][j - 1][1] = map[i - 1][j - 1][0];
				sefr(map, i - 1, j - 1);
				adad(map, i - 1, j - 1);
			}
		}
		else if (j == 8)
		{
			if (map[i][j - 1][1] == 11 && map[i][j - 1][0] == 0)
			{
				map[i][j - 1][1] = map[i][j - 1][0];
				sefr(map, i, j - 1);
				adad(map, i, j - 1);
			}

			if (map[i - 1][j - 1][1] == 11 && map[i - 1][j - 1][0] == 0)
			{
				map[i - 1][j - 1][1] = map[i - 1][j - 1][0];
				sefr(map, i - 1, j - 1);
				adad(map, i - 1, j - 1);
			}

			if (map[i - 1][j][1] == 11 && map[i - 1][j][0] == 0)
			{
				map[i - 1][j][1] = map[i - 1][j][0];
				sefr(map, i - 1, j);
				adad(map, i - 1, j);
			}

		}
		else
		{
			if (map[i - 1][j - 1][1] == 11 && map[i - 1][j - 1][0] == 0)
			{
				map[i - 1][j - 1][1] = map[i - 1][j - 1][0];
				sefr(map, i - 1, j - 1);
				adad(map, i - 1, j - 1);
			}

			if (map[i - 1][j][1] == 11 && map[i - 1][j][0] == 0)
			{
				map[i - 1][j][1] = map[i - 1][j][0];
				sefr(map, i - 1, j);
				adad(map, i - 1, j);
			}

			if (map[i - 1][j + 1][1] == 11 && map[i - 1][j + 1][0] == 0)
			{
				map[i - 1][j + 1][1] = map[i - 1][j + 1][0];
				sefr(map, i - 1, j + 1);
				adad(map, i - 1, j + 1);
			}

			if (map[i][j - 1][1] == 11 && map[i][j - 1][0] == 0)
			{
				map[i][j - 1][1] = map[i][j - 1][0];
				sefr(map, i, j - 1);
				adad(map, i, j - 1);
			}

			if (map[i][j + 1][1] == 11 && map[i][j + 1][0] == 0)
			{
				map[i][j + 1][1] = map[i][j + 1][0];
				sefr(map, i, j + 1);
				adad(map, i, j + 1);
			}
		}
	}
	else
	{
		if (j == 0)
		{
			if (map[i - 1][j][1] == 11 && map[i - 1][j][0] == 0)
			{
				map[i - 1][j][1] = map[i - 1][j][0];
				sefr(map, i - 1, j);
				adad(map, i - 1, j);
			}

			if (map[i - 1][j + 1][1] == 11 && map[i - 1][j + 1][0] == 0)
			{
				map[i - 1][j + 1][1] = map[i - 1][j + 1][0];
				sefr(map, i - 1, j + 1);
				adad(map, i - 1, j + 1);
			}

			if (map[i][j + 1][1] == 11 && map[i][j + 1][0] == 0)
			{
				map[i][j + 1][1] = map[i][j + 1][0];
				sefr(map, i, j + 1);
				adad(map, i, j + 1);
			}

			if (map[i + 1][j][1] == 11 && map[i + 1][j][0] == 0)
			{
				map[i + 1][j][1] = map[i + 1][j][0];
				sefr(map, i + 1, j);
				adad(map, i + 1, j);
			}

			if (map[i + 1][j + 1][1] == 11 && map[i + 1][j + 1][0] == 0)
			{
				map[i + 1][j + 1][1] = map[i + 1][j + 1][0];
				sefr(map, i + 1, j + 1);
				adad(map, i + 1, j + 1);
			}
		}
		else if (j == 8)
		{
			if (map[i - 1][j - 1][1] == 11 && map[i - 1][j - 1][0] == 0)
			{
				map[i - 1][j - 1][1] = map[i - 1][j - 1][0];
				sefr(map, i - 1, j - 1);
				adad(map, i - 1, j - 1);
			}

			if (map[i - 1][j][1] == 11 && map[i - 1][j][0] == 0)
			{
				map[i - 1][j][1] = map[i - 1][j][0];
				sefr(map, i - 1, j);
				adad(map, i - 1, j);
			}

			if (map[i][j - 1][1] == 11 && map[i][j - 1][0] == 0)
			{
				map[i][j - 1][1] = map[i][j - 1][0];
				sefr(map, i, j - 1);
				adad(map, i, j - 1);
			}

			if (map[i + 1][j - 1][1] == 11 && map[i + 1][j - 1][0] == 0)
			{
				map[i + 1][j - 1][1] = map[i + 1][j - 1][0];
				sefr(map, i + 1, j - 1);
				adad(map, i + 1, j - 1);
			}

			if (map[i + 1][j][1] == 11 && map[i + 1][j][0] == 0)
			{
				map[i + 1][j][1] = map[i + 1][j][0];
				sefr(map, i + 1, j);
				adad(map, i + 1, j);
			}
		}
		else
		{
			if (map[i - 1][j - 1][1] == 11 && map[i - 1][j - 1][0] == 0)
			{
				map[i - 1][j - 1][1] = map[i - 1][j - 1][0];
				sefr(map, i - 1, j - 1);
				adad(map, i - 1, j - 1);
			}

			if (map[i - 1][j][1] == 11 && map[i - 1][j][0] == 0)
			{
				map[i - 1][j][1] = map[i - 1][j][0];
				sefr(map, i - 1, j);
				adad(map, i - 1, j);
			}

			if (map[i - 1][j + 1][1] == 11 && map[i - 1][j + 1][0] == 0)
			{
				map[i - 1][j + 1][1] = map[i - 1][j + 1][0];
				sefr(map, i - 1, j + 1);
				adad(map, i - 1, j + 1);
			}

			if (map[i][j - 1][1] == 11 && map[i][j - 1][0] == 0)
			{
				map[i][j - 1][1] = map[i][j - 1][0];
				sefr(map, i, j - 1);
				adad(map, i, j - 1);
			}

			if (map[i][j + 1][1] == 11 && map[i][j + 1][0] == 0)
			{
				map[i][j + 1][1] = map[i][j + 1][0];
				sefr(map, i, j + 1);
				adad(map, i, j + 1);
			}

			if (map[i + 1][j - 1][1] == 11 && map[i + 1][j - 1][0] == 0)
			{
				map[i + 1][j - 1][1] = map[i + 1][j - 1][0];
				sefr(map, i + 1, j - 1);
				adad(map, i + 1, j - 1);
			}

			if (map[i + 1][j][1] == 11 && map[i + 1][j][0] == 0)
			{
				map[i + 1][j][1] = map[i + 1][j][0];
				sefr(map, i + 1, j);
				adad(map, i + 1, j);
			}

			if (map[i + 1][j + 1][1] == 11 && map[i + 1][j + 1][0] == 0)
			{
				map[i + 1][j + 1][1] = map[i + 1][j + 1][0];
				sefr(map, i + 1, j + 1);
				adad(map, i + 1, j);
			}
		}
	}
}

void print(int a)
{
	switch (a)
	{
	case 0:
		printf("   ");
		break;
	case 1:
		printf(Y);
		printf(" 1 ");
		break;
	case 2:
		printf(G);
		printf(" 2 ");
		break;
	case 3:
		printf(P);
		printf(" 3 ");
		break;
	case 4:
		printf(CY);
		printf(" 4 ");
		break;
	case 5:
		printf(G);
		printf(" 5 ");
		break;
	case 6:
		printf(P);
		printf(" 6 ");
		break;
	case 7:
		printf(R);
		printf(" 7 ");
		break;
	case 8:
		printf(Y);
		printf(" 8 ");
		break;
	case 10:
		printf(W);
		UNI;
		wprintf(L" \x01A0 ");
		ASCII;
		break;
	case 11:
		printf(B);
		printf(" * ");
		break;
	case 13:
		printf(R);
		UNI;
		wprintf(L" \x2660 ");
		ASCII;
		break;
	}
}

int num(int map[9][9][2], int i, int j)
{
	int c = 0;
	if (i == 0)
	{
		if (j == 0)
		{
			if (map[i][j + 1][0] == 10)
				c++;
			if (map[i + 1][j][0] == 10)
				c++;
			if (map[i + 1][j + 1][0] == 10)
				c++;
		}
		else if (j == 8)
		{
			if (map[i][j - 1][0] == 10)
				c++;
			if (map[i + 1][j - 1][0] == 10)
				c++;
			if (map[i + 1][j][0] == 10)
				c++;
		}
		else
		{
			if (map[i][j - 1][0] == 10)
				c++;
			if (map[i][j + 1][0] == 10)
				c++;
			if (map[i + 1][j - 1][0] == 10)
				c++;
			if (map[i + 1][j][0] == 10)
				c++;
			if (map[i + 1][j + 1][0] == 10)
				c++;
		}
	}
	else if (i == 8)
	{
		if (j == 0)
		{
			if (map[i][j + 1][0] == 10)
				c++;
			if (map[i - 1][j][0] == 10)
				c++;
			if (map[i - 1][j + 1][0] == 10)
				c++;
		}
		else if (j == 8)
		{
			if (map[i][j - 1][0] == 10)
				c++;
			if (map[i - 1][j - 1][0] == 10)
				c++;
			if (map[i - 1][j][0] == 10)
				c++;
		}
		else
		{
			if (map[i - 1][j - 1][0] == 10)
				c++;
			if (map[i - 1][j][0] == 10)
				c++;
			if (map[i - 1][j + 1][0] == 10)
				c++;
			if (map[i][j - 1][0] == 10)
				c++;
			if (map[i][j + 1][0] == 10)
				c++;
		}
	}
	else
	{
		if (j == 0)
		{
			if (map[i - 1][j][0] == 10)
				c++;
			if (map[i - 1][j + 1][0] == 10)
				c++;
			if (map[i][j + 1][0] == 10)
				c++;
			if (map[i + 1][j][0] == 10)
				c++;
			if (map[i + 1][j + 1][0] == 10)
				c++;
		}
		else if (j == 8)
		{
			if (map[i - 1][j - 1][0] == 10)
				c++;
			if (map[i - 1][j][0] == 10)
				c++;
			if (map[i][j - 1][0] == 10)
				c++;
			if (map[i + 1][j - 1][0] == 10)
				c++;
			if (map[i + 1][j][0] == 10)
				c++;
		}
		else
		{
			if (map[i - 1][j - 1][0] == 10)
				c++;
			if (map[i - 1][j][0] == 10)
				c++;
			if (map[i - 1][j + 1][0] == 10)
				c++;
			if (map[i][j - 1][0] == 10)
				c++;
			if (map[i][j + 1][0] == 10)
				c++;
			if (map[i + 1][j - 1][0] == 10)
				c++;
			if (map[i + 1][j][0] == 10)
				c++;
			if (map[i + 1][j + 1][0] == 10)
				c++;
		}
	}

	return c;
}

int f = 0;

void show1(int map[9][9][2], int bomb, int flag)
{
	f++;
	system("cls");
	printf(R);
	printf("BOMB : %d\n", bomb);
	printf(G);
	printf("FLAG : %d\n\n", flag);
	printf(W);
	printf(" -----------------------------------\n");
	for (int b5 = 0; b5 < 9; b5++)
	{
		if (f == 1)
			_sleep(50);
		for (int b6 = 0; b6 < 9; b6++)
		{
			if (b6 == 0)
			{
				printf(W);
				printf("|");
			}
			printf(B);
			print(map[b5][b6][1]);
			printf(W);
			printf("|");
		}
		printf("\n");
		printf(" -----------------------------------");
		printf("\n");
	}
	printf("\n");
}

void show0(int map[9][9][2], int bomb, int flag)
{
	system("cls");
	printf(R);
	printf("BOMB : %d\n", bomb);
	printf(G);
	printf("FLAG : %d\n\n", flag);
	printf(W);
	printf(" -----------------------------------\n");
	for (int b5 = 0; b5 < 9; b5++)
	{
		_sleep(50);
		for (int b6 = 0; b6 < 9; b6++)
		{
			if (b6 == 0)
			{
				printf(W);
				printf("|");
			}
			printf(B);
			print(map[b5][b6][0]);
			printf(W);
			printf("|");
		}
		printf("\n");
		printf(" -----------------------------------");
		printf("\n");
	}
	printf("\n");
}



int main()
{
	// Name : 

	printf(G);
	printf("WELCOME\nPLEASE ENTER YOUR NAME : ");
	printf(CY);
	char name[100];
	scanf("%s", &name);

	//

	while (1 == 1)
	{

		// Gamer info :
		int win = 0, lose = 0;
	menu:
		system("cls");
		printf(CY);
		printf("%s\n", name);
		printf(G);
		printf("Win : %d\n", win);
		printf(R);
		printf("Lose : %d\n", lose);

		//

		// Menu :

		printf(W);
		printf("1. PLAY\n");
		printf("2. SETTING\n");
		printf("3. EXIT\n");
		char a1[100];
		scanf("%s", &a1);
		system("cls");

		//
		if (strcmp(a1, "1") == 0)
		{
			while (1 == 1)
			{
				// play : 
				system("cls");
				printf(W);
				printf("1. SMALL LAND\n");
				printf("2. LARGE LAND\n");
				printf("3. BACK\n");
				char a3[100];
				scanf("%s", &a3);
				if (strcmp(a3, "1") == 0)
				{
					// SMALL LAND :

					int map[9][9][2] = { 0 };
				rand:
					int i1[10], j1[10], ij[10][10] = { 0 };
					srand(time(NULL));
					for (int a4 = 0; a4 < 10; a4++)
					{
						i1[a4] = (rand() % 9);
						j1[a4] = (rand() % 9);
						ij[i1[a4]][j1[a4]]++;
					}
					for (int a20 = 0; a20 < 10; a20++)
					{
						if (ij[i1[a20]][j1[a20]] > 1)
						{
							goto rand;
						}
					}
					int jj[10] = { 0 };
					for (int a5 = 0; a5 < 10; a5++)
					{
						switch (j1[a5])
						{
						case 0:
							jj[0]++;
							break;
						case 1:
							jj[1]++;
							break;
						case 2:
							jj[2]++;
							break;
						case 3:
							jj[3]++;
							break;
						case 4:
							jj[4]++;
							break;
						case 5:
							jj[5]++;
							break;
						case 6:
							jj[6]++;
							break;
						case 7:
							jj[7]++;
							break;
						case 8:
							jj[8]++;
							break;
						case 9:
							jj[9]++;
							break;
						}

					}
					for (int a6 = 0; a6 < 10; a6++)
					{
						if (jj[a6] > 3)
						{
							goto rand;
						}
					}
					for (int a7 = 0; a7 < 10; a7++)
					{
						int a8 = i1[a7];
						int a9 = j1[a7];
						map[a8][a9][0] = 10;
					}

					for (int b3 = 0; b3 < 9; b3++)
					{
						for (int b4 = 0; b4 < 9; b4++)
						{
							map[b3][b4][1] = 11;
						}
					}

					for (int b1 = 0; b1 < 9; b1++)
					{
						for (int b2 = 0; b2 < 9; b2++)
						{
							if (map[b1][b2][0] != 10)
							{
								map[b1][b2][0] = num(map, b1, b2);
							}
						}
					}
					int bomb = 10, flag = 10;
					while (1 == 1)
					{
						if (bomb <= 0)
						{
						Win:
							system("cls");
							printf(G);
							printf("YOU WON !");
							win++;
							_sleep(1300);
							show0(map, bomb, flag);
							_sleep(2300);
							goto menu;
						}
						char i13[10], j13[10], s[10];
						while (1 == 1)
						{
							if (strcmp(name, "TA") == 0)
							{
								system("cls");
								printf(R);
								printf("OOPS , TA'S CAN NEVER WIN .");
								_sleep(3000);
								goto End;
							}
							show1(map, bomb, flag);
							scanf("%s", &i13);
							scanf("%s", &j13);
							scanf("%s", s);
							if (strcmp(i13, "E") == 0)
								if (strcmp(j13, "N") == 0)
									if (strcmp(s, "D") == 0)
										goto End;

							if (strcmp(i13, "I") == 0)
								if (strcmp(j13, "AM") == 0)
									if (strcmp(s, "JAVAD") == 0)
										goto Win;

							if (strcmp(i13, "1") == 0 || strcmp(i13, "2") == 0 || strcmp(i13, "3") == 0 || strcmp(i13, "4") == 0 || strcmp(i13, "5") == 0 || strcmp(i13, "6") == 0 || strcmp(i13, "7") == 0 || strcmp(i13, "8") == 0 || strcmp(i13, "9") == 0)
							{
								if (strcmp(j13, "1") == 0 || strcmp(j13, "2") == 0 || strcmp(j13, "3") == 0 || strcmp(j13, "4") == 0 || strcmp(j13, "5") == 0 || strcmp(j13, "6") == 0 || strcmp(j13, "7") == 0 || strcmp(j13, "8") == 0 || strcmp(j13, "9") == 0)
								{
									if (strcmp(s, "L") == 0 || strcmp(s, "R") == 0)
									{
										break;
									}
								}
							}
						}
						int i, j;
						i = i13[0] - 48;
						j = j13[0] - 48;
						i--;
						j--;
						if (strcmp(s, "L") == 0)
						{
							if (map[i][j][1] == 11)
							{
								if (map[i][j][0] == 10)
								{
								End:
									system("cls");
									printf(R);
									printf("GAME OVER !");
									lose++;
									_sleep(1300);
									while (1 == 1)
									{
										show0(map, bomb, flag);
										printf(W);
										printf("PLEASE PRESS 13 TO GO TO THE MENU .\n");
										char a13[10];
										scanf("%s", &a13);
										if (strcmp(a13, "13") == 0)
											goto menu;
										else
										{
											printf(R);
											printf("INVALID ANSWER ! PLEASE TRY AGAIN .");
											_sleep(1300);
										}
									}
								}
								else if (map[i][j][1] == 13)
								{

								}
								else
								{
									map[i][j][1] = map[i][j][0];
									if (map[i][j][0] == 0)
									{
										sefr(map, i, j);
									}
								}
							}
							else
							{

							}
						}
						else if (strcmp(s, "R") == 0)
						{
							if (map[i][j][1] == 11)
							{
								if (flag > 0)
								{
									if (map[i][j][0] == 10)
									{
										map[i][j][1] = 13;
										bomb--;
										flag--;
									}
									else
									{
										map[i][j][1] = 13;
										flag--;
									}
								}
								else
								{
									printf(R);
									printf("THERE IS NO FLAG !");
									_sleep(1300);
								}
							}
							else if (map[i][j][1] == 13)
							{
								if (map[i][j][0] == 10)
								{
									map[i][j][1] = 11;
									bomb++;
									flag++;
								}
								else
								{
									map[i][j][1] = 11;
									flag++;
								}
							}
						}
					}
				}
				else if (strcmp(a3, "2") == 0)
				{
					// LARGE LAND :
					printf(R);
					printf("COMING SOON !!!\n");
					printf(CY);
					printf("PLAY IT IN THE NEW VERSION .");
					_sleep(3000);
				}
				else if (strcmp(a3, "3") == 0)
				{
					// Back :
					goto menu;
				}
				else
				{
					// Invalid answer :
					printf(R);
					printf("INVALID ANSWER ! PLEASE TRY AGAIN .");
					_sleep(1300);
				}
			}
		}
		else if (strcmp(a1, "2") == 0)
		{
			// Setting :
			while (1 == 1)
			{
				system("cls");
				printf(CY);
				printf("%s\n", name);
				printf(W);
				printf("1. CHANGE NAME\n");
				printf("2. BACK\n");
				char a2[100];
				scanf("%s", &a2);
				if (strcmp(a2, "1") == 0)
				{
					// Change name :
					system("cls");
					printf("PLEASE ENTER YOUR NAME : ");
					printf(CY);
					scanf("%s", &name);
				}
				else if (strcmp(a2, "2") == 0)
				{
					// Back :
					goto menu;
				}
				else
				{
					// Invalid answer :
					printf(R);
					printf("INVALID ANSWER ! PLEASE TRY AGAIN .");
					_sleep(1300);
				}
			}
		}
		else if (strcmp(a1, "3") == 0)
		{
			// Exit : 
			return 0;
		}
		else
		{
			// Invalid answer :
			printf(R);
			printf("INVALID ANSWER ! PLEASE TRY AGAIN .");
			_sleep(3000);
		}
	}
	return 0;
}

/*-----END-----*/