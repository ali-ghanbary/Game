#define CRT_SECURE_NO_WARNINGS
#include "graphics.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>   
#include <ctype.h>   
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<conio.h>
/*PROTOTYPES*/
void avvalie(void);
void ekhtar(int y);
int checkchar(int, int, int);
void printing(int);
void printboard(char board[][21], int, char, char, int, int, int, int);
char checkint(char);
int cpuselection(char board[][21], int, char, char);
int checkwinning(char board[][21], int, char, char);
void game(int, char, char, int);

/*MAIN FUNCTION*/
int main()
{
	int i = 0, j = 0, flag = 0, size = 0, sehat = 0, x = 0;
	initwindow(1500, 800, "Gomoku Game");
	while (flag == 0)
	{
		int input = 0, mode = 0, play = 0;
		avvalie();
		cleardevice();
		outtextxy(0, 0, ">>>Welcome to Gomoku Game<<<");/*chap menu avvalie*/
		outtextxy(20, 50, "[1] Start the game");
		outtextxy(20, 105, "[2] Adjust the size of the playground");
		outtextxy(20, 160, "[3] Quit");
		setcolor(15);
		outtextxy(0, 210, "Please select one of the above items : ");
		system("cls");
		scanf_s("%d", &input);/*vorodi avvalie menu*/
		if (((x = checkchar(input, 0, 285)) == 1) && (input == 0))/*barresi character naboodan vorodi*/
		{
			printing(285);
			continue;
		}
		switch (input)
		{
		case 1:
		{
			if (sehat != 1)
				size = 10;
			sehat = 0;
			cleardevice();
			while (1)
			{
				play = 0;
				setcolor(0);/*menu entekhab sabk bazi*/
				outtextxy(20, 0, "[1] Play with another player");
				outtextxy(20, 50, "[2] Play with cpu");
				setcolor(15);
				outtextxy(0, 100, "Choose your select : ");
				system("cls");
				scanf_s("%d", &play);/*vorodi entekhab sabk*/
				if (((x = checkchar(play, 0, 185)) == 1) && (play == 0))/*barresi character naboodan vorodi*/
				{
					printing(185);
					continue;
				}
				else if ((play != 1) && (play != 2))/*vorodi kharej az mahdoode tain shode*/
				{
					play = 0;
					ekhtar(185);
					setcolor(14);
					outtextxy(70, (185 + 35), "Your input is out of range!");
					printing(185);
					continue;
				}
				else
				{
					cleardevice();
					break;
				}
			}
			if (play == 1)/*bazi ba bazikon digar*/
			{
				game(size, 'A', 'B', 0);
				size = 0;
				_getch();
			}
			else if (play == 2)/*bazi ba cpu*/
			{
				while (1)
				{
					mode = 0;
					cleardevice();
					setcolor(0);
					outtextxy(20, 0, "[1] Simple mode");/*menu entekhab daraje sakhti bazi*/
					outtextxy(20, 50, "[2] Medium mode");
					setcolor(15);
					outtextxy(0, 100, "Which one do you want to play?");
					system("cls");
					scanf_s("%d", &mode);
					if (((x = checkchar(mode, 0, 185)) == 1) && (mode == 0))/*barresi character naboodan vorodi*/
					{
						printing(185);
						continue;
					}
					if ((mode != 1) && (mode != 2))/*vorodi kharej az mahdoode tain shode*/
					{
						ekhtar(185);
						setcolor(14);
						outtextxy(70, (185 + 35), "Your input is out of range!");
						printing(185);
						continue;
					}
					else
					{
						cleardevice();
						break;
					}
				}
				if (mode == 1)/*halat sade*/
				{
					game(size, 'A', 'C', 1);
					size = 0;
					_getch();
				}
				else if (mode == 2)/* EMTIAZI : halat motavaset*/
				{
					game(size, 'A', 'C', 2);
					size = 0;
					_getch();
				}
			}
			break;
		}
		case 2:
		{
			while (1)
			{
				size = 0;
				cleardevice();
				setcolor(0);
				outtextxy(0, 0, "[Announcement] : The size of the playground is from [7] to [20]...");/*taine size jadval*/
				setcolor(15);
				outtextxy(20, 50, "Specify the size of the playground : ");
				system("cls");
				scanf_s("%d", &size);
				if (((x = checkchar(size, 0, 135)) == 1) && (size == 0))/*barresi character naboodan vorodi*/
				{
					printing(135);
					continue;
				}
				if ((size < 7) || (size > 20))/*vorodi kharej az mahdoode tain shode*/
				{
					ekhtar(135);
					setcolor(14);
					outtextxy(70, (135 + 35), "Your input is out of range!");
					printing(135);
					continue;
				}
				else
				{
					cleardevice();
					sehat = 1;
					break;
				}
			}
			break;
		}
		case 3:
		{
			cleardevice();
			outtextxy(20, 0, "Good bye...");/*peigham chap shode ghabl az khorooj az safhe*/
			flag = 1;
			continue;
		}
		default:
		{
			ekhtar(285);
			setcolor(14);
			outtextxy(70, (285 + 35), "Your input is out of range!");/*vorodi kharej az mahdoode tain shode*/
			printing(285);
			continue;
		}
		}
	}
	_getch();
	return 0;
}

/*FUNCTION DEFINITIONS*/
void avvalie(void)/*tanzimat avvalie*/
{
	settextstyle(9, 0, 4);
	setcolor(0);
	setbkcolor(3);
}

void ekhtar(int y)/*chap navar ekhtar*/
{
	setcolor(4);
	circle(40, y, 30);
	setfillstyle(1, 4);
	floodfill(40, y, 4);
	settextstyle(9, 0, 6);
	setcolor(15);
	setbkcolor(4);
	outtextxy(27, (y - 27), "!");
	avvalie();
	setcolor(4);
	outtextxy(75, (y - 15), "===============WARNING===============");
}

int checkchar(int temporary_number, int magic, int arz)/*check if is there a chracter in the input number or not?*/
{
	while (1)
	{
		int c;
		if ((c = getchar()) != '\n' && c != EOF)
		{
			while ((c = getchar()) != '\n' && c != EOF)
			{
			}
			if (magic == 0)
			{
				ekhtar(arz);
				setcolor(14);
				outtextxy(70, (arz + 35), "Your input must be a number but contains characters :((");
			}
			else
				return temporary_number;
			return 1;
		}
		return temporary_number;
	}
}

void printing(int arz)/*Print a few sentences just for the beauty of the code*/
{
	outtextxy(70, (arz + 85), "Wait a few seconds and then try again...");
	delay(4000);
	cleardevice();
}

void printboard(char board[][21], int size, char x, char y, int satr, int sotoon, int type, int flag)/*chap jadval*/
{
	int i, j;
	settextstyle(3, 0, 1);
	char titr[3];
	setcolor(6);
	setbkcolor(6);
	rectangle(5, 5, (44 + (size * 21)), (44 + (size * 21)));
	setfillstyle(1, 6);
	floodfill(70, 70, 6);
	setcolor(0);
	for (i = 0; i < size; i++)
	{
		if ((i % 3) == 0)
			setlinestyle(0, 0, 2);
		else
			setlinestyle(0, 0, 1);

		line(45, (45 + (i * 21)), (45 + ((size - 1) * 21)), (45 + (i * 21)));/*OFOGHI*/
		line((45 + (i * 21)), 45, (45 + (i * 21)), (45 + ((size - 1) * 21)));/*AMUDI*/
	}
	for (i = 0; i < size; i++)
	{
		snprintf(titr, sizeof(titr), "%c", (i + 'A'));/*chap horuf*/
		setbkcolor(6);
		if ((i + 'A') == 'I')
			outtextxy((44 + (i * 21)), 10, titr);
		else if (((i + 'A') == 'M') || ((i + 'A') == 'O') || ((i + 'A') == 'N'))
			outtextxy((40 + (i * 21)), 10, titr);
		else
			outtextxy((42 + (i * 21)), 10, titr);
		snprintf(titr, sizeof(titr), "%d", (i + 1));/*chap adad*/
		if ((i + 1) == 1)
			outtextxy(13, (33 + (i * 21)), titr);
		else if ((i + 1) <= 9)
			outtextxy(12, (33 + (i * 21)), titr);
		else
			outtextxy(8, (33 + (i * 21)), titr);
	}
	for (i = 0; i < size; i++)
		for (j = 0; j < size; j++)
		{
			if (board[i][j] == x)/*ma siahim*/
			{
				setcolor(0);
				circle((45 + (i * 21)), (45 + (j * 21)), 10);
				setfillstyle(1, 0);
				floodfill((50 + (i * 21)), (50 + (j * 21)), 0);
				floodfill((40 + (i * 21)), (40 + (j * 21)), 0);
				floodfill((50 + (i * 21)), (40 + (j * 21)), 0);
				floodfill((40 + (i * 21)), (50 + (j * 21)), 0);
			}
			else if (board[i][j] == y)/*harif sefide*/
			{
				setcolor(15);
				circle((45 + (i * 21)), (45 + (j * 21)), 10);
				setfillstyle(1, 15);
				floodfill((50 + (i * 21)), (50 + (j * 21)), 15);
			}
		}
	if (flag == 1)/************khat keshidan roye barande************/
	{
		setcolor(4);
		setlinestyle(0, 0, 6);
		if (type == 1)/*sotoon*/
		{
			line((45 + (satr * 21)), (45 + (sotoon * 21)), (45 + (satr * 21)), (45 + ((sotoon + 4) * 21)));
		}
		else if (type == 2)/*satr*/
		{
			line((45 + (satr * 21)), (45 + (sotoon * 21)), (45 + ((satr + 4) * 21)), (45 + (sotoon * 21)));
		}
		else if (type == 3)/*movarab nozuli*/
		{
			line((45 + (satr * 21)), (45 + (sotoon * 21)), (45 + ((satr + 4) * 21)), (45 + ((sotoon + 4) * 21)));
		}
		else if (type == 4)/*movarab soudi*/
		{
			line((45 + (satr * 21)), (45 + (sotoon * 21)), (45 + ((satr - 4) * 21)), (45 + ((sotoon + 4) * 21)));
		}
	}
}

char checkint(char what)/*check if is there a number in the input number or not?*/
{
	int check = (int)what;
	if ((check >= 48) && (check <= 57))
	{
		return '\0';
	}
	else
		return what;
}

int cpuselection(char board[][21], int size, char x, char y)/*entekhab cpu dar mode motavasset*/
{
	int check = 0, win = 0, Temp = 0, i = 0, j = 0, k = 0, maximum = 0, t = 0, m = 0, n = 0, z = 0, flag = 0;
	int max[400] = { 0 };/*max tedad mohre harif dar type tain shode*/
	int satr[400] = { 0 };/*satr noghte mored nazar*/
	int sotoon[400] = { 0 };/*sotoon noghte mored nazar*/
	int type[400] = { 0 };/*type noghte mored nazar*/
	int satrkhali[5] = { 0 };
	int sotoonkhali[5] = { 0 };
	srand((unsigned int)time(0));
	/*barande shodan dar haman ebteda dar surate emkan*/
	for (i = 0; i < size; i++)/*******sotoon********/
	{
		for (j = 0; j <= (size - 5); j++)
		{
			if ((board[i][j] == y) || (board[i][j] == '-'))
			{
				for (k = 0; k < 5; k++)
					if (board[i][j + k] == y)
						win++;
			}
			if (win == 4)
			{
				for (k = 0; k < 5; k++)
					if (board[i][j + k] == '-')
						return Temp = (i * 100) + (j + k);
			}
			win = 0;
		}
	}
	for (j = 0; j < size; j++)/*******satr*******/
	{
		for (i = 0; i <= (size - 5); i++)
		{
			if ((board[i][j] == y) || (board[i][j] == '-'))
			{
				for (k = 0; k < 5; k++)
					if (board[i + k][j] == y)
						win++;
			}
			if (win == 4)
			{
				for (k = 0; k < 5; k++)
					if (board[i + k][j] == '-')
						return Temp = ((i + k) * 100) + j;
			}
			win = 0;
		}
	}
	for (i = 0; i <= (size - 5); i++)/*******movarrab nozuli*******/
	{
		for (j = 0; j <= (size - 5); j++)
		{
			if ((board[i][j] == y) || (board[i][j] == '-'))
			{
				for (k = 0; k < 5; k++)
					if (board[i + k][j + k] == y)
						win++;
			}
			if (win == 4)
			{
				for (k = 0; k < 5; k++)
					if (board[i + k][j + k] == '-')
						return Temp = ((i + k) * 100) + (j + k);
			}
			win = 0;
		}
	}
	for (i = 4; i < size; i++)/********movarrab soudi**********/
	{
		for (j = 0; j <= (size - 5); j++)
		{
			if ((board[i][j] == y) || (board[i][j] == '-'))
			{
				for (k = 0; k < 5; k++)
					if (board[i - k][j + k] == y)
						win++;
			}
			if (win == 4)
			{
				for (k = 0; k < 5; k++)
					if (board[i - k][j + k] == '-')
						return Temp = ((i - k) * 100) + (j + k);
			}
			win = 0;
		}
	}
	/**************************************barresi halate khatarnak************************************************/
	maximum = 2;
	check = 1;
	for (i = 0; i < size; i++)/**********sotoon************/
	{
		for (j = 0; j <= (size - 2); j++)
		{
			if (board[i][j] == x)
			{
				for (k = 1; k < 4; k++)
					if ((j + k) < size)
					{
						if (board[i][j + k] == x)
							check++;
						else
							break;
					}
				if (((j != 0) && (board[i][j - 1] == '-')) || ((board[i][j + check] == '-') && ((j + check) < size)))
				{
					if (check > maximum)
					{
						maximum = check;
						for (k = 0; k < 400; k++)
						{
							max[k] = 0;
							satr[k] = 0;
							sotoon[k] = 0;
							type[k] = 0;
						}
						t = 0;
						max[t] = maximum;
						satr[t] = i;
						sotoon[t] = j;
						type[t] = 1;
						t++;
					}
					else if (check == maximum)
					{
						max[t] = maximum;
						satr[t] = i;
						sotoon[t] = j;
						type[t] = 1;
						t++;
					}
				}
				check = 1;
			}
		}
	}
	for (j = 0; j < size; j++)/**********satr************/
	{
		for (i = 0; i <= (size - 2); i++)
		{
			if (board[i][j] == x)
			{
				for (k = 1; k < 4; k++)
					if ((i + k) < size)
					{
						if (board[i + k][j] == x)
							check++;
						else
							break;
					}
				if (((i != 0) && (board[i - 1][j] == '-')) || ((board[i + check][j] == '-') && ((i + check) < size)))
				{
					if (check > maximum)
					{
						maximum = check;
						for (k = 0; k < 400; k++)
						{
							max[k] = 0;
							satr[k] = 0;
							sotoon[k] = 0;
							type[k] = 0;
						}
						t = 0;
						max[t] = maximum;
						satr[t] = i;
						sotoon[t] = j;
						type[t] = 2;
						t++;
					}
					else if (check == maximum)
					{
						max[t] = maximum;
						satr[t] = i;
						sotoon[t] = j;
						type[t] = 2;
						t++;
					}
				}
				check = 1;
			}
		}
	}
	for (i = 0; i <= (size - 2); i++)/*******movarrab nozuli*******/
	{
		for (j = 0; j <= (size - 2); j++)
		{
			if (board[i][j] == x)
			{
				for (k = 1; k < 4; k++)
					if (((i + k) < size) && ((j + k) < size))
					{
						if (board[i + k][j + k] == x)
							check++;
						else
							break;
					}
				if (((j != 0) && (i != 0) && (board[i - 1][j - 1] == '-')) || ((board[i + check][j + check] == '-') && ((j + check) < size) && ((i + check) < size)))
				{
					if (check > maximum)
					{
						maximum = check;
						for (k = 0; k < 400; k++)
						{
							max[k] = 0;
							satr[k] = 0;
							sotoon[k] = 0;
							type[k] = 0;
						}
						t = 0;
						max[t] = maximum;
						satr[t] = i;
						sotoon[t] = j;
						type[t] = 3;
						t++;
					}
					else if (check == maximum)
					{
						max[t] = maximum;
						satr[t] = i;
						sotoon[t] = j;
						type[t] = 3;
						t++;
					}
				}
				check = 1;
			}
		}
	}
	for (i = 1; i < size; i++)/********movarrab soudi**********/
	{
		for (j = 0; j <= (size - 2); j++)
		{
			if (board[i][j] == x)
			{
				for (k = 1; k < 4; k++)
					if (((i - k) >= 0) && ((j + k) < size))
					{
						if (board[i - k][j + k] == x)
							check++;
						else
							break;
					}
				if (((j != 0) && (i != (size - 1)) && (board[i + 1][j - 1] == '-')) || ((board[i - check][j + check] == '-') && ((j + check) < size) && ((i - check) >= 0)))
				{
					if (check > maximum)
					{
						maximum = check;
						for (k = 0; k < 400; k++)
						{
							max[k] = 0;
							satr[k] = 0;
							sotoon[k] = 0;
							type[k] = 0;
						}
						t = 0;
						max[t] = maximum;
						satr[t] = i;
						sotoon[t] = j;
						type[t] = 4;
						t++;
					}
					else if (check == maximum)
					{
						max[t] = maximum;
						satr[t] = i;
						sotoon[t] = j;
						type[t] = 4;
						t++;
					}
				}
				check = 1;
			}
		}
	}
	k = 0;
	for (i = 0; i < 400; i++)
	{
		if (max[i] != 0)
			k++;
		else
			break;
	}
	if (k > 0)/***************************************************************halate khatarnak**********************************************************/
	{
		m = rand() % k;
		if (type[m] == 1)/*sotoon*/
		{
			if ((board[satr[m]][sotoon[m] - 1] == '-') && (board[satr[m]][sotoon[m] + max[m]] == '-') && (sotoon[m] != 0) && ((sotoon[m] + max[m]) < size))
			{
				n = rand() % 2;
				if (n == 0)
					return Temp = (satr[m] * 100) + (sotoon[m] - 1);
				else
					return Temp = (satr[m] * 100) + (sotoon[m] + max[m]);
			}
			else if ((board[satr[m]][sotoon[m] - 1] == '-') && (sotoon[m] != 0))
				return Temp = (satr[m] * 100) + (sotoon[m] - 1);
			else
				return Temp = (satr[m] * 100) + (sotoon[m] + max[m]);
		}
		else if (type[m] == 2)/*satr*/
		{
			if ((board[satr[m] - 1][sotoon[m]] == '-') && (board[satr[m] + max[m]][sotoon[m]] == '-') && (satr[m] != 0) && ((satr[m] + max[m]) < size))
			{
				n = rand() % 2;
				if (n == 0)
					return Temp = ((satr[m] - 1) * 100) + sotoon[m];
				else
					return Temp = ((satr[m] + max[m]) * 100) + sotoon[m];
			}
			else if ((board[satr[m] - 1][sotoon[m]] == '-') && (satr[m] != 0))
				return Temp = ((satr[m] - 1) * 100) + sotoon[m];
			else
				return Temp = ((satr[m] + max[m]) * 100) + sotoon[m];
		}
		else if (type[m] == 3)/*movarab nozuli*/
		{
			if ((board[satr[m] - 1][sotoon[m] - 1] == '-') && (board[satr[m] + max[m]][sotoon[m] + max[m]] == '-') && (sotoon[m] != 0) && ((sotoon[m] + max[m]) < size) && (satr[m] != 0) && ((satr[m] + max[m]) < size))
			{
				n = rand() % 2;
				if (n == 0)
					return Temp = ((satr[m] - 1) * 100) + (sotoon[m] - 1);
				else
					return Temp = ((satr[m] + max[m]) * 100) + (sotoon[m] + max[m]);
			}
			else if ((board[satr[m] - 1][sotoon[m] - 1] == '-') && (sotoon[m] != 0) && (satr[m] != 0))
				return Temp = ((satr[m] - 1) * 100) + (sotoon[m] - 1);
			else
				return Temp = ((satr[m] + max[m]) * 100) + (sotoon[m] + max[m]);
		}
		else if (type[m] == 4)/*mavarb soudi*/
		{
			if ((board[satr[m] + 1][sotoon[m] - 1] == '-') && (board[satr[m] - max[m]][sotoon[m] + max[m]] == '-') && (sotoon[m] != 0) && ((sotoon[m] + max[m]) < size) && (satr[m] != (size - 1)) && ((satr[m] - max[m]) >= 0))
			{
				n = rand() % 2;
				if (n == 0)
					return Temp = ((satr[m] + 1) * 100) + (sotoon[m] - 1);
				else
					return Temp = ((satr[m] - max[m]) * 100) + (sotoon[m] + max[m]);
			}
			else if ((board[satr[m] + 1][sotoon[m] - 1] == '-') && (sotoon[m] != 0) && (satr[m] != (size - 1)))
				return Temp = ((satr[m] + 1) * 100) + (sotoon[m] - 1);
			else
				return Temp = ((satr[m] - max[m]) * 100) + (sotoon[m] + max[m]);
		}
	}
	else/*************************halati ke bayad dar yek goshe mohreha ra bechinim*****************************/
	{
		t = 0;
		check = 0;/*vojood 5 jaye khali ya y*/
		maximum = 1;/*bishtarin meghdar tedad y ha*/
		win = 0;/* tedad y ha dar un 5 ja*/
		for (k = 0; k < 400; k++)
		{
			max[k] = 0;
			satr[k] = 0;
			sotoon[k] = 0;
			type[k] = 0;
		}/*********barresi ghabeliat chidan 5 mohre poshte ham**********/
		for (i = 0; i < size; i++)/**********sotoon************/
		{
			for (j = 0; j <= (size - 5); j++)
			{
				if ((board[i][j] == y) || (board[i][j] == '-'))
				{
					for (k = 0; k < 5; k++)
					{
						if (board[i][j + k] == y)
							win++;
						if ((board[i][j + k] == y) || (board[i][j + k] == '-'))
							check++;
						else
							break;
					}
					if (check == 5)
					{
						if (win > maximum)
						{
							maximum = win;
							for (k = 0; k < 400; k++)
							{
								max[k] = 0;
								satr[k] = 0;
								sotoon[k] = 0;
								type[k] = 0;
							}
							t = 0;
							max[t] = maximum;
							satr[t] = i;
							sotoon[t] = j;
							type[t] = 1;
							t++;
						}
						else if (win == maximum)
						{
							max[t] = maximum;
							satr[t] = i;
							sotoon[t] = j;
							type[t] = 1;
							t++;
						}
					}
					win = 0;
					check = 0;
				}
			}
		}
		for (j = 0; j < size; j++)/**********satr************/
		{
			for (i = 0; i <= (size - 5); i++)
			{
				if ((board[i][j] == y) || (board[i][j] == '-'))
				{
					for (k = 0; k < 5; k++)
					{
						if (board[i + k][j] == y)
							win++;
						if ((board[i + k][j] == y) || (board[i + k][j] == '-'))
							check++;
						else
							break;
					}
					if (check == 5)
					{
						if (win > maximum)
						{
							maximum = win;
							for (k = 0; k < 400; k++)
							{
								max[k] = 0;
								satr[k] = 0;
								sotoon[k] = 0;
								type[k] = 0;
							}
							t = 0;
							max[t] = maximum;
							satr[t] = i;
							sotoon[t] = j;
							type[t] = 2;
							t++;
						}
						else if (win == maximum)
						{
							max[t] = maximum;
							satr[t] = i;
							sotoon[t] = j;
							type[t] = 2;
							t++;
						}
					}
					check = 0;
					win = 0;
				}
			}
		}
		for (i = 0; i <= (size - 5); i++)/*******movarrab nozooli*******/
		{
			for (j = 0; j <= (size - 5); j++)
			{
				if ((board[i][j] == y) || (board[i][j] == '-'))
				{
					for (k = 0; k < 5; k++)
					{
						if (board[i + k][j + k] == y)
							win++;
						if ((board[i + k][j + k] == y) || (board[i + k][j + k] == '-'))
							check++;
						else
							break;
					}
					if (check == 5)
					{
						if (win > maximum)
						{
							maximum = win;
							for (k = 0; k < 400; k++)
							{
								max[k] = 0;
								satr[k] = 0;
								sotoon[k] = 0;
								type[k] = 0;
							}
							t = 0;
							max[t] = maximum;
							satr[t] = i;
							sotoon[t] = j;
							type[t] = 3;
							t++;
						}
						else if (win == maximum)
						{
							max[t] = maximum;
							satr[t] = i;
							sotoon[t] = j;
							type[t] = 3;
							t++;
						}
					}
					check = 0;
					win = 0;
				}
			}
		}
		for (i = 4; i < size; i++)/********movarrab suodi**********/
		{
			for (j = 0; j <= (size - 5); j++)
			{
				if ((board[i][j] == y) || (board[i][j] == '-'))
				{
					for (k = 0; k < 5; k++)
					{
						if (board[i - k][j + k] == y)
							win++;
						if ((board[i - k][j + k] == y) || (board[i - k][j + k] == '-'))
							check++;
						else
							break;
					}
					if (check == 5)
					{
						if (win > maximum)
						{
							maximum = win;
							for (k = 0; k < 400; k++)
							{
								max[k] = 0;
								satr[k] = 0;
								sotoon[k] = 0;
								type[k] = 0;
							}
							t = 0;
							max[t] = maximum;
							satr[t] = i;
							sotoon[t] = j;
							type[t] = 4;
							t++;
						}
						else if (win == maximum)
						{
							max[t] = maximum;
							satr[t] = i;
							sotoon[t] = j;
							type[t] = 4;
							t++;
						}
					}
					check = 0;
					win = 0;
				}
			}
		}
		k = 0;/*k = tedad anasori ke havi bishtarin tedad y hastand*/
		j = 0;
		for (i = 0; i < 400; i++)
		{
			if (max[i] != 0)
				k++;
			else
				break;
		}
		if (k != 0)/***********hadaghal yek y dar 5 khane motevali yaftim**********/
		{
			m = rand() % k;
			if (type[m] == 1)/*sotoon*/
			{
				for (i = 0; i <= 4; i++)
					if (board[satr[m]][sotoon[m] + i] == '-')
					{
						satrkhali[j] = satr[m];
						sotoonkhali[j] = sotoon[m] + i;
						j++;
					}
				k = rand() % j;
				return Temp = (satrkhali[k] * 100) + sotoonkhali[k];
			}
			else if (type[m] == 2)/*satr*/
			{
				for (i = 0; i <= 4; i++)
					if (board[satr[m] + i][sotoon[m]] == '-')
					{
						satrkhali[j] = satr[m] + i;
						sotoonkhali[j] = sotoon[m];
						j++;
					}
				k = rand() % j;
				return Temp = (satrkhali[k] * 100) + sotoonkhali[k];
			}
			else if (type[m] == 3)/*movarab nozooli*/
			{
				for (i = 0; i <= 4; i++)
					if (board[satr[m] + i][sotoon[m] + i] == '-')
					{
						satrkhali[j] = satr[m] + i;
						sotoonkhali[j] = sotoon[m] + i;
						j++;
					}
				k = rand() % j;
				return Temp = (satrkhali[k] * 100) + sotoonkhali[k];
			}
			else if (type[m] == 4)/*mavarb soudi*/
			{
				for (i = 0; i <= 4; i++)
					if (board[satr[m] - i][sotoon[m] + i] == '-')
					{
						satrkhali[j] = satr[m] - i;
						sotoonkhali[j] = sotoon[m] + i;
						j++;
					}
				k = rand() % j;
				return Temp = (satrkhali[k] * 100) + sotoonkhali[k];
			}
		}
		else/***********hich y dar 5 khane motevali nayaftim**********/
		{
			for (k = 0; k < 400; k++)
			{
				satr[k] = 0;
				sotoon[k] = 0;
			}
			z = 0;
			check = 0;
			for (i = 0; i < size; i++)
				for (j = 0; j < size; j++)
				{
					if (board[i][j] == '-')
					{
						for (t = 1; t <= 4; t++)
							if ((j + t) < size)
							{
								if ((board[i][j + t] == '-') || (board[i][j + t] == y))
									check++;
							}
						if (check != 4)
						{
							check = 0;
							for (t = 1; t <= 4; t++)
								if ((i + t) < size)
								{
									if ((board[i + t][j] == '-') || (board[i + t][j] == y))
										check++;
								}
						}
						if (check != 4)
						{
							check = 0;
							for (t = 1; t <= 4; t++)
								if (((i + t) < size) && ((j + t) < size))
								{
									if ((board[i + t][j + t] == '-') || (board[i + t][j + t] == y))
										check++;
								}
						}
						if (check != 4)
						{
							check = 0;
							for (t = 1; t <= 4; t++)
								if (((i - t) >= 0) && ((j + t) < size))
								{
									if ((board[i - t][j + t] == '-') || (board[i - t][j + t] == y))
										check++;
								}
						}
						if (check == 4)
						{
							flag = 1;
							satr[z] = i;
							sotoon[z] = j;
							z++;
						}
						check = 0;
					}
				}
			if (flag == 1)
			{
				k = rand() % z;
				return Temp = (satr[k] * 100) + sotoon[k];
			}
		}
	}
	return -1;
}

int checkwinning(char board[][21], int size, char x, char y)/*barrsi vojoode barande dar bazi*/
{
	int checkwin = 0, i = 0, j = 0, k = 0, win = 0, satr = 0, sotoon = 0, type = 0, temporary = 0;
	for (i = 0; i < size; i++)/*******sotoon********/
	{
		for (j = 0; j <= (size - 5); j++)
		{
			if (board[i][j] != '-')
			{
				for (k = 1; k < 5; k++)
					if (board[i][j + k] == board[i][j])
						checkwin++;
					else
						break;
			}
			if (checkwin == 4)
			{
				if (board[i][j] == x)
					win = 1;
				else
					win = 2;
				satr = i;
				sotoon = j;
				type = 1;
				break;
			}
			else
				checkwin = 0;
		}
		if (checkwin == 4)
			break;
	}
	if (checkwin != 4)/*******satr*******/
	{
		checkwin = 0;
		for (j = 0; j < size; j++)
		{
			for (i = 0; i <= (size - 5); i++)
			{
				if (board[i][j] != '-')
				{
					for (k = 1; k < 5; k++)
						if (board[i + k][j] == board[i][j])
							checkwin++;
						else
							break;
				}
				if (checkwin == 4)
				{
					if (board[i][j] == x)
						win = 1;
					else
						win = 2;
					satr = i;
					sotoon = j;
					type = 2;
					break;
				}
				else
					checkwin = 0;
			}
			if (checkwin == 4)
				break;
		}
	}
	if (checkwin != 4)/*******movarrab nozuli*******/
	{
		checkwin = 0;
		for (i = 0; i <= (size - 5); i++)
		{
			for (j = 0; j <= (size - 5); j++)
			{
				if (board[i][j] != '-')
				{
					for (k = 1; k < 5; k++)
						if (board[i + k][j + k] == board[i][j])
							checkwin++;
						else
							break;
				}
				if (checkwin == 4)
				{
					if (board[i][j] == x)
						win = 1;
					else
						win = 2;
					satr = i;
					sotoon = j;
					type = 3;
					break;
				}
				else
					checkwin = 0;
			}
			if (checkwin == 4)
				break;
		}
	}
	if (checkwin != 4)/********movarrab suodi**********/
	{
		checkwin = 0;
		for (i = 4; i < size; i++)
		{
			for (j = 0; j <= (size - 5); j++)
			{
				if (board[i][j] != '-')
				{
					for (k = 1; k < 5; k++)
						if (board[i - k][j + k] == board[i][j])
							checkwin++;
						else
							break;
				}
				if (checkwin == 4)
				{
					if (board[i][j] == x)
						win = 1;
					else
						win = 2;
					satr = i;
					sotoon = j;
					type = 4;
					break;
				}
				else
					checkwin = 0;
			}
			if (checkwin == 4)
				break;
		}
	}
	if (checkwin == 4)
		return temporary = sotoon + (satr * 100) + (type * 10000) + (win * 100000);
	else
		return 0;
}

void game(int size, char X, char Y, int mode)/******************tabe bazi gomoku************************/
{
	char player, Row;
	char str[4];
	player = X;
	char winner = '\0';
	int col = 0, row = 0, i = 0, j = 0, k = 0, isfull = 1, chap = 0, temp = 0, Temp = 0, satr = 0, sotoon = 0, type = 0, flag = 0;
	char khoroji[27];/*marbut be tabe reshte saz snprintf*/
	char Board[21][21];
	for (i = 0; i < 20; i++)
		for (j = 0; j < 20; j++)
			Board[i][j] = '-';
	while (winner == '\0')/********************halgheye bazi************************/
	{
		if ((mode == 0) || ((mode == 1) && (player == X)) || ((mode == 2) && (player == X)))
			while (1)
			{
				isfull = 1;
				int shenas = 0;
				int tool = 0;
				char checkn1, checkn2;
				avvalie();
				printboard(Board, size, X, Y, 0, 0, 0, 0);
				avvalie();
				outtextxy(0, (80 + (size * 20)), "[Announcement]:Input must be string with[1]character and a maximum[2]numbers!");/*elamie barye vorood reshte*/
				setcolor(15);
				snprintf(khoroji, sizeof(khoroji), "[Player [%c]]", player);
				outtextxy(0, (130 + (size * 20)), khoroji);
				outtextxy(10, (180 + (size * 20)), "Make your move :");
				if (chap == 1)
				{
					chap = 0;
					ekhtar((265 + (size * 20)));
					setcolor(14);
					outtextxy(70, ((265 + (size * 20)) + 35), "It is already occupied here!");
					printing((265 + (size * 20)));
					continue;
				}
				fflush(stdout);
				system("cls");
				if (scanf_s("%4s", str, (unsigned)sizeof(str)) == 1)
					tool = strlen(str);
				if (tool == 1)
				{
					ekhtar((265 + (size * 20)));
					setcolor(14);
					outtextxy(70, ((265 + (size * 20)) + 35), "Your input's length is less than allowed!");
					printing((265 + (size * 20)));
					continue;
				}
				else if (tool == 0)
				{
					str[3] = checkchar(str[3], 1, 0);
					ekhtar((265 + (size * 20)));
					setcolor(14);
					outtextxy(70, ((265 + (size * 20)) + 35), "Your input's length is more than allowed!");
					printing((265 + (size * 20)));
					continue;
				}
				else if (tool == 2)
					col = ((int)str[1] - 48);
				else if (tool == 3)
					col = (((int)str[1]) - 48) * 10 + (((int)str[2]) - 48);
				Row = str[0];
				k = (int)Row;
				if ((checkn1 = checkint(Row)) == '\0')
				{
					ekhtar((265 + (size * 20)));
					setcolor(14);
					outtextxy(70, ((265 + (size * 20)) + 35), "Your Column cannot be a number =((");
					printing((265 + (size * 20)));
					continue;
				}
				if (((checkn1 = checkint(str[1])) == '\0') && ((checkn2 = checkint(str[2])) == '\0'))
					shenas = 1;/*ghatiat dar sahih boodan adad*/
				if (shenas == 0)
				{
					ekhtar((265 + (size * 20)));
					setcolor(14);
					outtextxy(70, ((265 + (size * 20)) + 35), "Your Row cannot be a character =((");
					printing((265 + (size * 20)));
					continue;
				}
				if ((k >= 97) && (k <= 122))
				{
					ekhtar((265 + (size * 20)));
					setcolor(14);
					outtextxy(70, ((265 + (size * 20)) + 35), "Your Column must be capitalized!");
					printing((265 + (size * 20)));
					continue;
				}
				char check = 65 + size;
				if (((shenas == 1) && (Row >= check)) && ((shenas == 1) && (col > size)))
				{
					ekhtar((265 + (size * 20)));
					setcolor(14);
					outtextxy(70, ((265 + (size * 20)) + 35), "Both of your column and row are larger than allowed!");
					printing((265 + (size * 20)));
					continue;
				}
				if ((shenas == 1) && (Row >= check))
				{
					ekhtar((265 + (size * 20)));
					setcolor(14);
					outtextxy(70, ((265 + (size * 20)) + 35), "Your column is larger than allowed!");
					printing((265 + (size * 20)));
					continue;
				}
				if ((shenas == 1) && (col == 0))
				{
					ekhtar((265 + (size * 20)));
					setcolor(14);
					outtextxy(70, ((265 + (size * 20)) + 35), "Your row must start with one!");
					printing((265 + (size * 20)));
					continue;
				}
				if ((shenas == 1) && (col > size))
				{
					ekhtar((265 + (size * 20)));
					setcolor(14);
					outtextxy(70, ((265 + (size * 20)) + 35), "Your row is larger than allowed!");
					printing((265 + (size * 20)));
					continue;
				}
				else
				{
					cleardevice();
					row = (int)Row - 65;
					col--;
					break;
				}

			}
		srand((unsigned int)time(0));
		if ((mode == 2) && (player == Y))
		{
			temp = cpuselection(Board, size, X, Y);
			if (temp != -1)
			{
				col = temp % 100;
				row = (temp - col) / 100;
			}
			else
				mode = 1;
		}
		while (1)
		{
			if ((mode == 1) && (player == Y))
			{
				row = rand() % size;
				col = rand() % size;
			}
			if ((row >= 0) && (col >= 0) && (row <= 20) && (col <= 20))
				if (Board[row][col] == '-')
				{
					Board[row][col] = player;
					Temp = checkwinning(Board, size, X, Y);
					if (Temp == 0)
					{
						winner = '\0';
					}
					else
					{
						sotoon = Temp % 100;
						Temp = (Temp - sotoon) / 100;
						satr = Temp % 100;
						Temp = (Temp - satr) / 100;
						type = Temp % 10;
						if (((Temp - type) / 10) == 1)
							winner = X;
						else
							winner = Y;
					}
					break;
				}
				else
				{
					if ((mode == 1) && (player == Y))
						continue;
					else
					{
						chap = 1;
						break;
					}
				}
		}
		if (chap == 1)
			continue;
		if (player == X)
			player = Y;
		else
			player = X;
		for (i = 0; i < size; i++)/*****tabel isfull*****/
			for (j = 0; j < size; j++)
				if (Board[i][j] == '-')/* empty square, so game ain't over yet*/
				{
					isfull = 0;
				}
		if (isfull == 1)/*agar isfull 0 nabud = zamin bazi kamelan eshghal shode*/
			break;
	}
	if (winner == X || winner == Y)
		flag = 1;
	printboard(Board, size, X, Y, satr, sotoon, type, flag);
	avvalie();
	if (flag == 1)
	{
		if (winner == Y)
			setcolor(15);
		else
			setcolor(0);
		snprintf(khoroji, sizeof(khoroji), "Congratulations player %c", winner);
		outtextxy(10, (80 + (size * 20)), khoroji);
		outtextxy(10, (130 + (size * 20)), "You won the game...");
	}
	else if (isfull == 1)
	{
		setcolor(4);
		outtextxy(10, (80 + (size * 20)), "Game ends in a draw!");
		outtextxy(10, (130 + (size * 20)), "Both players are equal...");
	}
	for (i = 0; i < 4; i++)
		str[i] = '\0';
}