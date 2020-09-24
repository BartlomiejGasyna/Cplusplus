//
//  main.cpp
//  lab 3 PSIO
//
//  Created by Bartłomiej Gasyna on 17/03/2020.
//  Copyright © 2020 Bartłomiej Gasyna. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

struct Exchange_rate
{
    string date_usd;
    string date_eur;
    double usd;
    double eur;
    string table_id;
};

vector<Exchange_rate> rates;
Exchange_rate er;

void sort_usd()
{
    double temp =0;
    string date_temp;
    string data_usd;
    
    for (auto i = rates.begin()+1; i!= rates.end()+1; i++)
    {
        if ((*i).usd<((i-1)->usd))
        {
            temp = (*i).usd;
            (*i).usd = (i-1)->usd;
            (i-1)->usd = temp;
            
            
            date_temp = (*i).date_usd;
            (*i).date_usd = (i-1)->date_usd;
            (i-1)->date_usd = date_temp;
            i=rates.begin();
        }
        
    }
    
    cout << "10 najwyzszych kursow dolara:" << endl;
    for (auto i=rates.end(); i != rates.end()-10; i--)
    {

        cout << (*i).date_usd<<":  "<<(*i).usd << endl;

    }
}
void sort_eur()
{
    double temp =0;
    string date_eur;
    for (auto i = rates.begin()+1; i!= rates.end()+1; i++)
    {
        if ((*i).eur<((i-1)->eur))
        {
            temp = (*i).eur;
            (*i).eur = (i-1)->eur;
            (i-1)->eur = temp;
            
            
            date_eur = (*i).date_eur;
            (*i).date_eur = (i-1)->date_eur;
            (i-1)->date_eur= date_eur;
            i=rates.begin();
        }
        
    }
    cout << "10 najnizszych kursow euro:" << endl;
       for( auto i = rates.begin()+5; i != rates.begin()+15; i++ )
       {
           cout << ( * i ).date_eur << " " <<  ( * i ).eur << endl;
       }
}


void binary_search (double val)
 {
     double min = 0, max =rates.size()-1;
     double mid;
     while (min!=max)
     {
         mid=(min+max)/2;
         if (rates[mid].usd == val)
             {
                 cout<<"kurs dolara: " << val << " w dniu "<< rates[mid].date_usd<<endl;
             }
         
         if (rates[mid].usd > val)
             {
                 max =mid-1;
             }
         
         if (rates[mid].usd <val)
             {
                 min=mid+1;
             }
     }
     cout<<"kurs dolara: " << val << " w dniu "<< rates[min].date_usd<<endl;
 }
int main(int argc, const char * argv[]) {
    fstream file("kursy_usd_eur.csv"); //plik znajduje się w tym samym katalogu co pliki źródłowe projektu, inaczej trzeba podać pełną ścieżkę np. "c:\\Users\\nazwa_uzytkownika\\Downloads\\kursy_usd_eur.csv"
    
    if (file.is_open()) {
        string line;
        getline(file, line); // wczytuje pierwszą linię z nagłówkiem i ją ignoruje
        while (std::getline(file, line)) {//wczytuje kolejne linie aż do końca pliku
            std::stringstream str(line);//tworzy strumień, którego źródłem jest wczytana linia

            
            getline(str, er.date_usd, ','); //wczytuje date (pierwszy element wiersza)
            er.date_eur=er.date_usd;
            string double_str;
            getline(str, double_str, ',');  // wczytuje kurs USD (jako tekst)
            ///er.usd = std::stod(double_str);      //zamiana na string->double///zamienione
            er.usd = atof(double_str.c_str());      //zamiana na string->double
            getline(str, double_str, ',');  // wczytuje kurs EUR (jako tekst)
            er.eur = atof(double_str.c_str());      //zamiana na string->double
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////
            getline(str, er.table_id, ','); // wczytuje ostatnią kolumnę z numerem tabeli NBP
            rates.emplace_back(er); //dodaje element do kolekcji
            
            }
        
    }
    sort_usd();
    cout<<endl;
    sort_eur();
    cout<<endl;
    binary_search(3.9011);
    return 0;
}
