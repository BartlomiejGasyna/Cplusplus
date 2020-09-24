//
//  main.cpp
//  Kolokwium
//
//  Created by Bartłomiej Gasyna on 11/12/2019.
//  Copyright © 2019 Bartłomiej Gasyna. All rights reserved.
//

#include <iostream>
#define ELFY 5
using namespace std;
class elf{
protected:
    int prod,zycie;
public:
    static int liczbaElfow;
    elf(){
        cout<<"Tu elf 1." << endl;
        prod=zycie=5;
        liczbaElfow++;

    };
    elf(int x, int y)
    {
        cout<<"Tu elf 2." << endl;
        prod=x;
        zycie=y;
        liczbaElfow++;
    };
    virtual ~elf(){};
    virtual int ZrobZabawke(int dzien){
    if (dzien<zycie)
        return prod;
        return 0;
    }
};



class superElf :public elf{
private:
    int sila;
public:
    static int liczbaSuperElfow;
    superElf(int x, int y, int z)
    {
        cout<<"Tu superElf"<<endl;
        prod=x;
        sila=y;
        zycie=z;
        liczbaSuperElfow++;
    }
    virtual int ZrobZabawke (int dzien){
        if (dzien<zycie)
            return sila*prod;
        return 0;
    }
};
int elf::liczbaElfow=0;
int superElf::liczbaSuperElfow=0;

string czyElfySieWyrobia(elf* tablicaElfow[ELFY], int d, const int z){
    int wynik=0;
    for (int i = 0; i<ELFY; i++)
    {
        wynik+=(tablicaElfow[i]->ZrobZabawke(d));
        //cout<<endl<<"elf :"<<wynik<<endl;
    }
    if (wynik>=z)
        return "Dadza rade";
    return "Nie dadza rady!";
};
// czy danego dnia d elfy nalezace do talicy tablica elfow wyrobia sie z zadaniami z funkcja musi wykorzystywac zrobZabawke
int main () {
  elf* tablicaElfow[ELFY];
  tablicaElfow[0] = new elf();
  tablicaElfow[1] = new elf(2,10);
  tablicaElfow[2] = new elf(3,6);
  tablicaElfow[3] = new superElf(4, 2, 5);
  tablicaElfow[4] = new superElf(2, 15, 1);
  cout << "Elfow jest: " << elf::liczbaElfow << endl;
  cout << "W tym super elfow jest: " << superElf::liczbaSuperElfow << endl;
  const int dni = 7;
  int tablicaZadan[dni] = {18, 33, 13, 12, 5, 2, 20};
  for (int i=0; i<dni; i++) {
    cout << "Dzien " << i << ". Czy elfy dadza rade: " << czyElfySieWyrobia(tablicaElfow, i,tablicaZadan[i]) << endl;
  }
  for (int i=0; i<ELFY; i++) {
    delete  tablicaElfow[i];
  }
}
