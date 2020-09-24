//
//  main.cpp
//  Lab 8 obsługa wyjątków
//
//  Created by Bartłomiej Gasyna on 04/12/2019.
//  Copyright © 2019 Bartłomiej Gasyna. All rights reserved.
//

#include <iostream>
using namespace std;
class Wyjatek
{
    private:
        int numer;
        string opis;
    public:
    Wyjatek(int nr, string op) {cout <<"Konstruktor wyjatek\n";numer = nr; opis = op;
        }
    string getOpis() {return opis;}
    int getNum() {return numer;}
    ~Wyjatek(){cout << "Destrkuktor wyjatek\n";};
        
};

class Stos
{
    private:
        int *tablica;
    public:
        Stos() { tablica = new int[10];};
        ~Stos() {delete [] tablica;};
        void push(int a, int i) {
            if (i<10)
            {
                cout << "Wpisuje " << a << " pod komorke " << i << endl;
                tablica[i] = a;
            }
            else
            {
                cout << "Rzucam wyjatkiem." << endl;
                Wyjatek* w = new Wyjatek(1, "Blad metody PUSH");
                throw w;
            }
        };
        int pop(int i) {
            if (i<10){cout << tablica[i] << endl; return tablica[i];}
            
            else
            {
                cout << "Rzucam wyjatkiem." << endl;
                Wyjatek* w = new Wyjatek(2,"Blad metody POP");
                throw w;
            }
            
           
            return i;
        }
};

class Symulacja
{
        Stos* stosik;
    public:
        Symulacja(){ cout << "Konstruktor symulacja " <<endl; stosik = new Stos();};
        ~Symulacja(){ cout << "Destruktor symulacja" << endl; delete stosik;}
        void sim();
};

void Symulacja::sim()
{
    for (int i = 0;i<11;i++)
    {
    try {
            stosik->push(i,i);
        }
    catch (Wyjatek* w) {
        if (w!=NULL)
        {
        cout << w->getOpis() << " ||||Numer bledu: " << w->getNum() << endl;
            delete w;}
    }}
   // napisz petle wypelniajac tablice (push) obejmij to klauzula "try" i celowo przekrocz zakres
   // zlap wyjatek, wyswietl numer bledu i jego opis
for (int i =0; i<11; i++)
{
    try
    {
            stosik->pop(i);
    }
    catch(Wyjatek* w)
    {
        if (w!=NULL){
    cout << w->getOpis() << " ||||Numer bledu: " << w->getNum() << endl;
            delete w;}
    }
}

}

int main()
{
    Symulacja sm;
    sm.sim();
    Stos stosik;
    
}
