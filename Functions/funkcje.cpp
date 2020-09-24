//
//  funkcje.cpp
//  Gasyna final
//
//  Created by Bartłomiej Gasyna on 15/03/2020.
//  Copyright © 2020 Bartłomiej Gasyna. All rights reserved.
//
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <math.h>
#include "funkcje.h"

using namespace std;

void nwd (int a, int b)
{   const int a1 = a;
    const int b1 = b;
    for (;;)
    {
    int c = a%b;
    a = b;
    b = c;
        if (b == 0)
            break;
    }
    cout << "Najwiekszy wspolny dzielnik liczb " << a1 << " i " << b1 << " to " << a << endl;
}

void find_and_replace(string napis, string szukane, string zamiana)
{
    cout<<napis<<endl;
    size_t position = napis.find(szukane);
    
    if (position==string::npos)
    {
        cout << "blad!";
        return;
    }
    do {
        napis.replace(position, szukane.size(), zamiana);
        position = napis.find(szukane, position + szukane.size());
        
    } while (position!=string::npos);
    cout<<"Po zmianie "<< szukane<< " na "<< zamiana<< ":"<<endl;
    cout << napis << endl;
}

void find(string napis, string szukane)
{
    int check=0;
    for (int i = 0; i<=napis.size(); i++)
    {
        for (int j=0; j <=szukane.size(); j++)
        {
            if (napis[i] == szukane[j])
            {
                check++;
                i++;
                if (check==szukane.size()) {
                    cout<<"W zdaniu \"" << napis <<"\" slowo \""<<szukane<<"\""<<endl;
                    cout<<"Znaleziono na: "<<i-szukane.size()<<" pozycji"<<endl;
                    break;
                }
            }
            else
            {
                j=0;
                break;
            }
        }
    }
    if (check!=szukane.size())
    {
        cout << "Nie znaleziono wyrazu";
    }
}




void okrag(int r)
{
    cout << "okrag o promieniu " << r << ":"<< endl;
    for (int y=r; y>= -r; y-=2)
    {
        for (int x=-r; x<=r; x++)
        {
            if((int)sqrt(pow(x,2)+pow(y,2))==r) cout << "#";
            else cout << " ";
        }
        cout << endl;
    }
}

vector <string> split(const string &napis, char sep)
{
    size_t position = napis.find(sep);
    size_t start_position = 0;
    vector <string> result;

    while(position != string::npos)
    {
        result.push_back(napis.substr(start_position, position - start_position));
        start_position = position + 1;
        position = napis.find(sep, start_position);
    }
    result.push_back( napis.substr(start_position, min(position, napis.size()) - start_position + 1));

    return result;
}


void ilosc_wyrazow(string sentence)
{
    int ilosc = 0;
    for (unsigned int i=0; i<sentence.length() ; i++)
    {
        if (sentence[0]!=' ' && sentence[i]==' ' && sentence[i+1]!=' ') {
            ilosc++;
        }
    }
    cout<<"Ilosc wyrazow w zdaniu \"" << sentence << "\": " << ilosc+1 << endl;
}

void najdluzszy(string txt)
{
    char znak = ' ';
    size_t position = txt.find(znak);
    size_t start_position = 0;
    vector <string> result;

    while(position != string::npos)
    {
        result.push_back(txt.substr(start_position, position - start_position));
        start_position = position + 1;
        position = txt.find(znak, start_position);
    }
    result.push_back( txt.substr(start_position, min(position, txt.size()) - start_position + 1));

    unsigned long m;

    m=result[0].size();

    for (unsigned int i = 0; i < result.size(); i++)
    {
        if(result[i].size() > m) m=result[i].size();
    }
    for (unsigned int i = 0; i < result.size(); i++)
    {
        if(result[i].size() == m)
        {
            cout << "Najdluzszym wyrazem w zdaniu \"" << txt << "\" jest: " << result[i] << endl;
        }
    }
}
