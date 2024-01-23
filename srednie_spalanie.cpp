#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
	int pojazd, i;
	double srednia, paliwo, droga;
	cout<<"---------- Program oblicza srednie spalanie pojazdow ----------"<<endl;
	Sleep(1750);
	system("cls");
	cout<<"--------------- Wybierz pojazd, dla ktorego chcesz obliczyc srednie spalanie ---------------"<<endl;
	cout<<"Ktora opcje wybierasz?: '1'-samochod osobowy, '2'-samochod ciezarowy, '3'-motocykl, '4'-quad."<<endl<<"--------------------------------------------------------------------------------------------"<<endl;
	do
	{
		cout<<"Wybieram: ";
		cin>>pojazd;
		i=0;
		switch (pojazd)
		{
			case 1: cout<<endl<<"Wybrales samochod osobowy.";
					break;
			case 2: cout<<endl<<"Wybrales samochod ciezarowy.";
					break;
			case 3: cout<<endl<<"Wybrales motocykl.";
					break;
			case 4: cout<<endl<<"Wybrales quad.";
					break;
			default: cout<<endl<<"Zle wybrany pojazd, zakres wyboru od 1 do 4! Wpisz dana ponownie."<<endl;
						i++;
		}
	}
	while (i==1);
	Sleep(500);
	do
	{
		cout<<endl<<"Podaj spalone paliwo w litrach: ";
		cin>>paliwo;
		if(paliwo<=0)
			cout<<"Bledna ilosc spalonego paliwa, sprobuj jeszcze raz!"<<endl;
	}
	while(paliwo<=0);
	Sleep(150);
	do
	{
		cout<<"Podaj przejechany dystans w kilometrach dla "<<paliwo<<"l: ";
		cin>>droga;
		if(droga<=0)
			cout<<"Zle podany dystans, sprobuj jeszcze raz!"<<endl;
	}
	while(droga<=0);
	srednia=(paliwo/droga)*100;
	if (pojazd==1)
		cout<<"Srednie spalanie dla samochodu osobowego: "<<srednia<<"L/KM";
	if (pojazd==2)
		cout<<"Srednie spalanie dla samochodu ciezarowego: "<<srednia<<"L/KM";
	if (pojazd==3)
		cout<<"Srednie spalanie dla motocykla: "<<srednia<<"L/KM";
	if (pojazd==4)
		cout<<"Srednie spalanie dla quada: "<<srednia<<"L/KM";
}