//
//  main.cpp
//  Lab 5 Abstrakcje
//
//  Created by Bartłomiej Gasyna on 19/11/2019.
//  Copyright © 2019 Bartłomiej Gasyna. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
//Stwórz klasę element oraz klasy od niej pochodne: rezystor, cewka, kondensator.
//2. Wszystkie klasy powinny mieć wbudowane właściwości niepubliczne: prąd, napięcie, moc, częstotliwość. Ponadto zależnie od danego elementu powinny posiadać parametry charakterystyczne: rezystancja, indukcyjność, pojemność
//(również niepubliczne) oraz parametr nazwa.
//3. Dla wszystkich klas zaimplementuj następujące metody:
// Konstruktor inicjujący pola nazwa oraz właściwość charakterystyczną danego elementu (w wersjach bez parametrów i z parametrami w różnych kombinacjach)
// Metody getName i setName pozwalające na pobranie nazwy oraz jej ustawienie dla danego obiektu
// Metody wymuszenie, pobierające różne parametry wymuszenia (napięcie, prąd, napięcie i częstotliwość, prąd i częstotliwość) i aktualizujące pozostałe parametry.
//Przykład metody: void wymuszenieU(int napiecie);
class Element
{
protected:
    int prad;
    int napiecie;
    int moc;
    int czestotliwosc;
    string nazwa;
public:
    
    Element()
    {nazwa = "element";
    czestotliwosc = 1.0;
    napiecie = prad = moc = 0.0;
    }
    
    Element(const string arg)
    {nazwa = arg;
    napiecie = czestotliwosc = 1.0; prad = moc = 0.0;
    }
    virtual void wymuszenieU(double) = 0;
    friend void obwod(Element*, Element*);

};

class Rezystor :public Element
{
protected:
    int rezystancja;
public:
    string nazwa;
    Rezystor()
    {
        nazwa="Rezystor";
        czestotliwosc=0;
        napiecie=prad=moc=1;
    }
    Rezystor(string arg)
    {
        nazwa="Rezystor_arg";
        czestotliwosc=1;
        napiecie=prad=moc=0;
    }
    
};

class Cewka :public Element
{
protected:
    int indukcyjnosc;
public:
    Cewka()
    {
        nazwa="Cewka";
        czestotliwosc=prad=moc=1;
        napiecie=0;
    }
    Cewka(string arg)
    {
        nazwa="Cewka_arg";
        czestotliwosc=prad=moc=0;
        napiecie=1;
    }
    
};

class Kondensator :public Element
{
protected:
    int pojemnosc;
public:
    Kondensator()
    {
        nazwa="Kondesator";
        prad=moc=napiecie=1;
        czestotliwosc=0;
    }
    Kondensator(string arg)
    {
        nazwa = "Kondensator_arg";
        prad=moc=napiecie=0;
        czestotliwosc=1;
    }
};


int main(int argc, const char * argv[]) {
    Kondensator::wymuszenieg(double i);
    
    return 0;
}
