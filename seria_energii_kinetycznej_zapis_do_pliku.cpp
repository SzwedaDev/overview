// plik liczy serie energii kinetycznych dla podanych mas i predkosci + zapisuje do pliku dane obliczen.
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int m_min, m_max, krokm, v1, v2, krokv, liczbam, e_k, i, zakres_e; 
	fstream plik;
	/*
	m_min=dolny przedzial masy, m_max=gorny przedzial masy, krokm=krok narastania masy
    v1=dolny przedzial predkosci, v2=gorny przedzial predkosci, krokv=krok narastania predkosci
    e_k=energia kinetyczna
    liczbam=liczba pomagajaca wypisac e_k od wszystkich mas pomiedzy widelkami m_min i m_max
    
	*/
	cout<<"Program wylicza serie energii kinetycznej"<<endl;
	do
	{
		cout<<"Podaj dolny przedzial masy pojazdu w kg: ";
		cin>>m_min;
		if(m_min<0)
			cout<<"Zla podana masa! Nie moze byc mniejsza od 0, podaj mase ponownie."<<endl;
	}
	while (m_min<0);
	do
	{
		cout<<"Podaj gorny przedzial masy pojazdu w kg: ";
		cin>>m_max;
		if(m_max<m_min)
			cout<<"Zla podana masa! Nie moze byc mniejsza od 0, podaj mase ponownie."<<endl;
	}
	while (m_max<m_min);
	do
	{
		cout<<"Podaj krok narastania masy pojazdu w kg: ";
		cin>>krokm;
		if(krokm<0)
			cout<<"Krok narastania ujemny, podaj ponownie."<<endl;
	}
	while (krokm<0);
	do
	{
		cout<<"Podaj dolny przedzial predkosci pojazdu w m/s: ";
		cin>>v1;
		if(v1<0)
			cout<<"Predkosc jest ujemna! Podaj wartosc predkosci jeszcze raz."<<endl;
	}
	while(v1<0);
	do
	{
		cout<<"Podaj gorny przedzial predkosci pojazdu w m/s: ";
		cin>>v2;
		if(v2<v1)
			cout<<"Predkosc mniejsza od minimalnej, podaj ponownie."<<endl;
	}
	while(v2<v1);
	do
	{
		cout<<"Podaj krok narastania predkosci pojazdu: ";
		cin>>krokv;
		if(krokv<0)
			cout<<"Za mala ilosc krokow, podaj jeszcze raz: "<<endl;
	}
	while (krokv<0);
	zakres_e=((m_max-m_min)/krokm+1)*((v2-v1)/krokv+1);
	float energie[zakres_e];
	plik.open("energia_kinetyczna_zapis.txt",ios::out);
	plik<<""; //wyczyszczenie wczesniejszych rekordow.
	plik.close();
	for (int liczbam = m_min; liczbam <= m_max; liczbam += krokm)
	{
	cout<<"------------------------------------------------"<<endl<<"Licze dla masy rownej "<< liczbam<<endl<<endl;
	plik.open("energia_kinetyczna_zapis.txt",ios::out | ios::app);
	plik<<"------------------------------------------------"<<endl<<"Licze dla masy rownej "<< liczbam<<endl<<endl;
	plik.close();
		for (int v=v1; v<=v2;v+=krokv)
		{
		    e_k=(liczbam*v*v)/2;
		    energie[i]=e_k;
			cout <<"Dla predkosci "<<v<<" m/s"<< " i masy="<< liczbam<<" kg, energia kinetyczna wynosi: "<<energie[i]<<" J"<<endl;
			plik.open("energia_kinetyczna_zapis.txt",ios::out | ios::app);
			plik <<"Dla predkosci "<<v<<" m/s"<< " i masy="<< liczbam<<" kg, energia kinetyczna wynosi: "<<energie[i]<<" J"<<endl;
			plik.close();
			i++;
		}
	}
} 