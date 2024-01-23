#include <iostream>
#include <math.h>

using namespace std;
int main()
{
	float a_fkw, b_fkw, c_fkw, delta, delta_p, x_j, x_d, x_z, odpowiedz; // cos_fkw= skladowa funkcji kwadratowej, x_j=x jeden...
	do
	{
		system("cls");
		cout<<"-----------------------------------------------"<<endl<<"Program wylicza rozwiazania funkcji kwadratowej "<<endl<<"-----------------------------------------------"<<endl;
		cout<<"Podaj wspolczynniki liczbowe"<<endl;
		do
		{
			cout<<"-> Podaj wspolczynnik a: ";
			cin>>a_fkw;
			if (a_fkw==0)
				cout<<"Wspolczynnik a nie moze byc 0!"<<endl;
		}
		while (a_fkw==0);
			cout<<"Podaj wspolczynnik b: ";
			cin>>b_fkw;
			cout<<"Podaj wspolczynnik c: ";
			cin>>c_fkw;
		delta=(b_fkw*b_fkw)-(4*a_fkw*c_fkw);
		if (delta<0)
			cout<<"Funkcja nie posiada rozwiazan, delta jest ujemna!";
		else
		{
			if (delta==0)
			{
				x_z=(-b_fkw)/(2*a_fkw);
				cout<<"Dla delty rownej zero istnieje jedno rowzwiazanie, x0="<<x_z;
			}
			else
			{ 
				delta_p=sqrt(delta);
				x_j=((-b_fkw)-(delta_p))/(2*a_fkw);
				x_d=(-b_fkw+(delta_p))/(2*a_fkw);
				cout<<"Dla delty rownej "<<delta;
				cout<<", istnieja dwa rozwiazania: x1="<<x_j;
				cout<<", x2="<<x_d;
			}
		}
		do
		{
			cout<<endl<<"Czy chcesz powtorzyc obliczenia? (1-tak, 0-nie): ";
			cin>>odpowiedz;
			if ((odpowiedz!=1) && (odpowiedz!=0))
				cout<<"Zla odpowiedz, sprobuj jeszcze raz! \n";
		}
		while ((odpowiedz!=1) && (odpowiedz!=0));
	}
	while(odpowiedz==1);
	return 0;
}
