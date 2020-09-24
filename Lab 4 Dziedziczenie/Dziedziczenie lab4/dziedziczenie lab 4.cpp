//
//  main.cpp
//  Dziedziczenie lab4
//
//  Created by Bartłomiej Gasyna on 06/11/2019.
//  Copyright © 2019 Bartłomiej Gasyna. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Zwierzak
{
public:
    int Masa;
    int Wiek;
    Zwierzak()
    {cout << "Kontstruktor Zwierzak" << endl;}
    void Patrz();
    void Oddychaj();
    void Zyj()
    {cout << "Zyje i mam sie dobrze" << endl;}
};
void Zwierzak::Patrz()
{
    cout << "patrz" << endl;
}

void Zwierzak::Oddychaj()
{
    cout << "oddychaj" << endl;
}

class Ssak : public Zwierzak
{
public:
    Ssak()
    {cout << "Konstruktor Ssak" << endl;}
    void Biegaj();
};

void Ssak::Biegaj()
{
    cout << "Biegaj" << endl;
}

class Lew :public Ssak
{
public:
    Lew()
    {cout << "Konstruktor Lew" << endl;}
    
};
class Pies :public Ssak
{};
class Slon :public Ssak
{};

class Ptak : public Zwierzak
{
public:
    Ptak()
    {cout << "Konstruktor Ptak" << endl;}
    void Lataj();
};
class Papuga :public Ptak
{
public:
    Papuga()
    {cout << "Konstruktor Papuga" << endl;}
};
class Kanarek :public Ptak
{};
class Golab :public Ptak
{};

class Ryba : public Zwierzak
{
public:
    void Plywaj();
    Ryba()
    {cout << "Konstruktor Ryba" << endl;}
};

class Welonek :public Ryba
{
public:
    Welonek()
    {cout << "Konstruktor Welonek" << endl;}
};

class Nemo :public Ryba
{};
class Karp :public Ryba
{};





/*6. W pętli głównej programu napisz kod pozwalający na demonstrację wykorzystania klas
i dziedziczenia, oraz wyświetlający na ekranie komputera etapy wykonywania programu, np.: „Stworzono obiekt Azor będący elementem klasy Pies dziedziczącym z klasy Ssak która dziedziczyła z klasy Zwierzak”
7. W klasie Zwierzak dodaj metodę Zyj() znajdująca się w sekcji publicznej, ustaw operatory dziedziczenia tak aby każda kolejna klasa dziedziczyła tą metodę (Metoda ma za zadanie wyświetlenie na ekranie tekstu „Żyję i mam się dobrze”).
 */
int main(int argc, const char * argv[]) {
    Lew Krol;
    Krol.Zyj();
    return 0;
}
