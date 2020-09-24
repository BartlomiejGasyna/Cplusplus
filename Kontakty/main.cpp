#include <iostream>

using namespace std;

struct Kontakty
{
    string imie;
    string nazwisko;
    int wiek;
    int wzrost;
    int NrTel;
    void WprowadzImie();
    void WyswietlImie();
    void WprowadzNazwisko();
    void WyswietlNazwisko();
    void WprowadzWiek();
    void WyswietlWiek();
    void WprowadzWzrost();
    void WyswietlWzrost();
    void WprowadzNrTel();
    void WyswietlNrTel();

};

void Kontakty::WprowadzImie()
{
cout<<"\nPodaj imie: ";
cin>>imie;
}
void Kontakty::WyswietlImie()
{
cout<<endl<<imie;
}



void Kontakty::WprowadzNazwisko()
{
cout<<"\nPodaj nazwisko: ";
cin>>nazwisko;
}
void Kontakty::WyswietlNazwisko()
{
cout<<endl<<nazwisko;
}


void Kontakty::WprowadzWiek()
{
cout<<"\nPodaj wiek: ";
cin>>wiek;
}
void Kontakty::WyswietlWiek()
{
cout<<endl<<wiek;
}



void Kontakty::WprowadzWzrost()
{
cout<<"\nPodaj wzrost: ";
cin>>wzrost;
}
void Kontakty::WyswietlWzrost()
{
cout<<endl<<wzrost;
}


void Kontakty::WprowadzNrTel()
{

cout<<"\nPodaj nr telefonu: ";
cin>>NrTel;
}

void Kontakty::WyswietlNrTel()
{
cout<<endl<<NrTel;
}



Kontakty k[5];
int main()
{   /*
    k.WprowadzImie();
    k.WyswietlImie();
    k.WprowadzNazwisko();
    k.WyswietlNazwisko();
    k.WprowadzWiek();
    k.WyswietlWiek();
    k.WprowadzWzrost();
    k.WyswietlWzrost();
    k.WprowadzNrTel();
    k.WyswietlNrTel();*/
    for(int i=0;i<5;i++)
    {
    wprowadzDane(i);
    }
    return 0;
}
