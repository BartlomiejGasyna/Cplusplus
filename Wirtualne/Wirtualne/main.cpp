//
//  main.cpp
//  Wirtualne
//
//  Created by Bartłomiej Gasyna on 12/11/2019.
//  Copyright © 2019 Bartłomiej Gasyna. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;


class Zwierze
{
public:
    Zwierze()
    {
        cout << "Konstruktor klasy zwierze" << endl;
    }
    ~Zwierze()
    {
        cout << "Destruktor klasy zwierze" << endl;
    }
    virtual void opis(void)
    {
        cout << "Metoda klasy zwierze" << endl;
    }
};

class Ssak :public Zwierze
{
public:
    Ssak()
    {
        cout << "Konstruktor klasy ssak " << endl;
    }
    ~Ssak()
    {
        cout << "Destruktor klasy ssak" << endl;
    }
    void opis(void)
    {
        cout << "Metoda klasy ssak" << endl;
    }
};

class Czlowiek :public Zwierze
{
public:
    Czlowiek()
    {
        cout << "Konstruktor klasy czlowiek " << endl;
    }
    ~Czlowiek()
    {
        cout << "Destruktor klasy czlowiek" << endl;
    }
    void opis(void)
    {
        cout << "Metoda klasy czlowiek" << endl;
    }
};

class Ptak :public Zwierze
{
public:
    Ptak()
    {
        cout << "Konstruktor klasy ptak" << endl;
    }
    ~Ptak()
    {
        cout << "Destruktor klasy ptak" << endl;
    }
    void opis(void)
    {
        cout << "Metoda klasy ptak" << endl;
    }
};
    Zwierze *wsk_zwierze;

    void SwitchCase(int liczba)
{
    
       switch (liczba) {
           case 0:
               wsk_zwierze = new Zwierze;
               wsk_zwierze -> opis();
               break;
           case 1:
               wsk_zwierze = new Ssak;
               wsk_zwierze -> opis();
               break;
           case 2:
               wsk_zwierze = new Czlowiek;
               wsk_zwierze -> opis();
               break;
           case 3:
               wsk_zwierze = new Ptak;
               wsk_zwierze -> opis();
               break;
           case 4:
               wsk_zwierze = NULL;
               break;
           default:
               break;
       }
}


int main()
{
    cout << "Ile iteracji pętli wykonać? " << endl;
    cout << "Liczba iteracji: ";
    int liczba_iteracji;
    
    cin >> liczba_iteracji;
    long liczba[liczba_iteracji];
     srand((int)time(NULL));
                for (int i = 0; i < liczba_iteracji; ++i)
                {
                    liczba[i] = rand () % 5;
                }
    for (int i = 0; i<liczba_iteracji; i++)
    {
        cout << "Wylosowany numer: " << liczba[i] << endl;
            if(liczba[i] == 4)
                cout << "NIE WOLNO PPZYPISYWAĆ WSKAZNIKA DO WARTOSI \"NULL\" " << endl;
            else
            {
                switch (liczba[i]) {
                    case 0:
                        wsk_zwierze = new Zwierze;
                        wsk_zwierze -> opis();
                        break;
                    case 1:
                        wsk_zwierze = new Ssak;
                        wsk_zwierze -> opis();
                        break;
                    case 2:
                        wsk_zwierze = new Czlowiek;
                        wsk_zwierze -> opis();
                        break;
                    case 3:
                        wsk_zwierze = new Ptak;
                        wsk_zwierze -> opis();
                        break;
                    case 4:
                        wsk_zwierze = NULL;
                        break;
                    default:
                        break;
                }
                delete wsk_zwierze;
            }

    };
    
    

    
    return 0;
};
