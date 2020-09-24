//
//  main.cpp
//  Lab 3 konstruktory
//
//  Created by Bartłomiej Gasyna on 05/11/2019.
//  Copyright © 2019 Bartłomiej Gasyna. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Osoba
{
private:
    string imie, nazwisko, data_urodzenia, miasto;
    int wiek;
    char plec;
public:
    Osoba();
    Osoba(string imie_arg);
    Osoba(string imie_arg, string nazwisko_arg);
    Osoba(string imie_arg, string nazwisko_arg, string data_urodzenia_arg);
    Osoba(string imie_arg, string nazwisko_arg, string data_urodzenia_arg, string miasto_arg);
    Osoba(string imie_arg, string nazwisko_arg, string data_urodzenia_arg, string miasto_arg, int wiek_arg);
    Osoba(string imie_arg, string nazwisko_arg, string data_urodzenia_arg, string miasto_arg, int wiek_arg, char plec_arg);
    ~Osoba();
    int id;
    static int id_ostatniego;
    static int aktualna_ilosc;
    static void Info();
    void Pokaz();
};

int main(int argc, const char * argv[])
{
    string temp;
    ifstream wejscie("konstruktor.txt");
    getline(wejscie,temp);
    Osoba::id_ostatniego=atoi(temp.c_str());
    Osoba::aktualna_ilosc=0;
    {
    Osoba o1;
    o1.Pokaz();
    Osoba::Info();
    }
    {
    Osoba o2("aaa");
    o2.Pokaz();
    Osoba::Info();
    }
    {
    Osoba o3("aaa", "bbb");
    o3.Pokaz();
    Osoba::Info();
    }
    {
    Osoba o4("aaa", "bbb", "ccc");
    o4.Pokaz();
    Osoba::Info();
    }
    {
    Osoba o5("aaa", "bbb", "ccc", "ddd");
    o5.Pokaz();
    Osoba::Info();
    }
    
    ofstream wyjscie ("konstruktor.txt", ios::trunc);
    wyjscie << Osoba::id_ostatniego;
    wyjscie.close();
    
    return 0;
}

int Osoba::id_ostatniego;
int Osoba::aktualna_ilosc;

Osoba::Osoba()
{
    imie = "Maciej";
    
    plec = 'M';
    id_ostatniego++;
    id=id_ostatniego;
    aktualna_ilosc++;
}

Osoba::Osoba(string imie_arg)
{
    imie = imie_arg;
    nazwisko = "Nowak";
    data_urodzenia = "5 maja 1976";
    miasto = "Warszawa";
    plec = 'M';
    wiek = 20;
    id_ostatniego++;
    id=id_ostatniego;
    aktualna_ilosc++;
}

Osoba::Osoba(string imie_arg, string nazwisko_arg)
{
   imie = imie_arg;
   nazwisko = nazwisko_arg;
   data_urodzenia = "5 maja 1976";
   miasto = "Warszawa";
   plec = 'M';
    wiek = 20;
   id_ostatniego++;
   id=id_ostatniego;
   aktualna_ilosc++;
}

Osoba::Osoba(string imie_arg, string nazwisko_arg, string data_urodzenia_arg)
{
    imie = imie_arg;
    nazwisko = nazwisko_arg;
    data_urodzenia = data_urodzenia_arg;
    miasto = "Warszawa";
    plec = 'M';
     wiek = 20;
    id_ostatniego++;
    id=id_ostatniego;
    aktualna_ilosc++;
}

Osoba::Osoba(string imie_arg, string nazwisko_arg, string data_urodzenia_arg, string miasto_arg)
{
    imie = imie_arg;
    nazwisko = nazwisko_arg;
    data_urodzenia = data_urodzenia_arg;
    miasto = miasto_arg;
    plec = 'M';
     wiek = 20;
    id_ostatniego++;
    id=id_ostatniego;
    aktualna_ilosc++;
}

Osoba::Osoba(string imie_arg, string nazwisko_arg, string data_urodzenia_arg, string miasto_arg, int wiek_arg)
{
    imie = imie_arg;
    nazwisko = nazwisko_arg;
    data_urodzenia = data_urodzenia_arg;
    miasto = miasto_arg;
    wiek = wiek_arg;
    plec = 'M';
    id_ostatniego++;
    id=id_ostatniego;
    aktualna_ilosc++;
}

Osoba::Osoba(string imie_arg, string nazwisko_arg, string data_urodzenia_arg, string miasto_arg, int wiek_arg, char plec_arg)
{
    imie = imie_arg;
    nazwisko = nazwisko_arg;
    data_urodzenia = data_urodzenia_arg;
    miasto = miasto_arg;
    wiek = wiek_arg;
    plec = plec_arg;
    id_ostatniego++;
    id=id_ostatniego;
    aktualna_ilosc++;
}

Osoba::~Osoba()
{
    cout << "---Destruktor---" << endl;;
    aktualna_ilosc--;
}

void Osoba::Pokaz()
{
    cout << "***********************" << endl;
    cout << "Imie: " << imie << endl;
    cout << "Nazwisko: " << nazwisko << endl;
    cout << "Data urodzin: : " << data_urodzenia << endl;
    cout << "Wiek: " << wiek << endl;
    cout << "Plec: " << plec << endl;
    cout << "***********************" << endl;
}

void Osoba::Info()
{
    cout << "Ostatnie ID: " << id_ostatniego << endl;
    cout << "Aktualne ID: " << aktualna_ilosc << endl;
}
