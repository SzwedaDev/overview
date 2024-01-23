#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
void gotoxy(int ix, int iy)
{
	COORD c;
	c.X = ix-1;
	c.Y = iy-1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
using namespace std;
int main()
{	
	int ix=12, iy=12, i;
	char znak;
	string spacje="                              ", napis="Witaj w symulatorze chodzenia!";
	for (i=0;i<31;i++)
	{
		gotoxy(10, 1);
		cout<<napis;
		gotoxy(10+i, 1);
		cout<<spacje;
		Sleep(100);
	}
	gotoxy(ix, iy);
	cout<<"*";
	do
	{
		znak=getch();
		switch(znak)
		{
			case 72:	if(iy>4)  //gora
						{
							iy--;
							gotoxy(ix, iy+1);
							cout<<" ";
							gotoxy(ix, iy);
							cout<<"*";
						}
						break;
			case 80:	if (iy<24)   //dol
						{
							iy++;
							gotoxy(ix, iy-1);
							cout<<" ";
							gotoxy(ix, iy);
							cout<<"*";
						}
						break;
			case 77:	if (ix<50) //prawo
						{
							ix++;
							gotoxy(ix-1, iy);
							cout<<" ";
							gotoxy(ix, iy);
							cout<<"*";
						}
						break;
			case 75:	if (ix>8) //lewo
						{
							ix--;
							gotoxy(ix+1, iy);
							cout<<" ";
							gotoxy(ix, iy);
							cout<<"*";
						}
						break;
		}
	}
	while (znak!=27);
	system("pause");
}