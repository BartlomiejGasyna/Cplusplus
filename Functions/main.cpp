//
//  main.cpp
//  Gasyna final
//
//  Created by Bartłomiej Gasyna on 15/03/2020.
//  Copyright © 2020 Bartłomiej Gasyna. All rights reserved.
//
#include <iostream>
#include "funkcje.h"
#include <vector>

using namespace std;
class program
{   public:
    program(){cout << "Witaj w programie, wybierz od 1 do 7, aby wywolac funkcje" << endl;}
};
int main() {
    program pierwszy;
    int wybor;
    for(;;)
    {
        cout<<"1. Najwiekszy wspolny dzielnik"<<endl;
        cout<<"2. Find and replace"<<endl;
        cout<<"3. Find"<<endl;
        cout<<"4. Okrag"<<endl;
        cout<<"5. Split"<<endl;
        cout<<"6. Ilosc wyrazow w zdaniu"<<endl;
        cout<<"7. Najdluzszy wyraz w zdaniu"<<endl;
        cout<<"8. Wyjscie z programu"<<endl;
        
    cout<<"wybor: ";
    
    cin>>wybor;
    switch (wybor) {
        case 1:
            cout<<endl;
            nwd(144, 60);
            cout<<endl;
            break;
        case 2:
            cout<<endl;
            find_and_replace("Ala ma kota, kot zjadl Ale!", "kot", "hefalump");
            cout<<endl;
            break;
        case 3:
            cout<<endl;
            find("Ala ma kota", "kota");
            cout<<endl;
            break;
        case 4:
            cout<<endl;
            okrag(20);
            cout<<endl;
        break;
        case 5:
        {
            cout<<endl;
            vector <string> words = split("Ala ma kota");
            for (unsigned int i = 0; i<= words.size(); i++) cout << words[i] << endl;
            cout<<endl;
        }
        break;
        case 6:
            cout<<endl;
            ilosc_wyrazow("Ala ma kota");
            cout<<endl;
        break;
        case 7:
            cout<<endl;
            najdluzszy("Ala ma kota");
            cout<<endl;
        break;
        case 8:
            cout<<endl;
            cout<<"Dziekuje za skorzystanie z programu!"<<endl;
            exit(0);
        break;
        default:
            break;
    }
    }
    
    
    
    
    
    
    
    return 0;
}
