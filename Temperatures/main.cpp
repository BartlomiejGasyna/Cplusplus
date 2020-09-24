//
//  main.cpp
//  lab 3 temperatury
//
//  Created by Bartłomiej Gasyna on 18/03/2020.
//  Copyright © 2020 Bartłomiej Gasyna. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <time.h>


using namespace std;

struct TemperaturaDane
{
    string date;
    string czas;
    double wind;
    double temp_dzwiekiem;
    double cisnienie;
    double temp_outside;
    double wilgotnosc;
    int kompas;
    double predkoscUV;
    double predkosc_wiatru;
    double kierunek;
    double wysokosc;
    double temp_inside;
};

vector<TemperaturaDane> pomiary;
TemperaturaDane td;

void sort_temperatura()
{

auto rozmiar = pomiary.end();
    int zmiana;
do
{

    zmiana = 0;
    for (auto i = pomiary.begin(); i < rozmiar-1 ; i++)
    {
        if ((*i).temp_outside >  (*(i+1)).temp_outside)
        {
            swap ( (*i), (*(i+1)));
            zmiana =1;
        }
       

    }
   rozmiar--;    //do testow mozna wlaczyc i wylaczyc

}while(zmiana);
    int it = 0;
    for (auto i = pomiary.begin(); i < pomiary.end(); i++)
    {
        cout << "temp " << it << ": " << (*i).temp_outside << endl;
        it++;
    }
    cout << "Najwyzsza temperatura: " << (pomiary.end()-1)->temp_outside << endl;
       cout << "Najnizsza temperatura: " << (pomiary.begin())->temp_outside << endl;
       cout << "Mediana temperatur: " << pomiary[(((pomiary.size()/2)-2)+((pomiary.size()/2)-1))/2].temp_outside << endl;
//       cout << "Mediana temperatur: " << (pomiary[((pomiary.size()/2)-2)].temp_outside + pomiary[((pomiary.size()/2)-1)/2].temp_outside)/2 << endl;
}

int main() {
    fstream file("temp02-2020.csv");

    if (file.is_open()) {
        string line;
        getline(file, line);
        while (getline(file, line)) {
            stringstream str(line);
            string double_str;

            getline(str, td.date, ',');
            getline(str, td.czas, ',');

            getline(str, double_str, ',');
            td.wind =atof(double_str.c_str());

            getline(str, double_str, ',');
            td.temp_dzwiekiem =atof(double_str.c_str());

            getline(str, double_str, ',');
            td.cisnienie =atof(double_str.c_str());

            getline(str, double_str, ',');
            td.temp_outside =atof(double_str.c_str());

            getline(str, double_str, ',');
            td.wilgotnosc =atof(double_str.c_str());

            getline(str, double_str, ',');
            td.kompas =atof(double_str.c_str());

            getline(str, double_str, ',');
            td.predkoscUV =atof(double_str.c_str());

            getline(str, double_str, ',');
            td.predkosc_wiatru =atof(double_str.c_str());

            getline(str, double_str, ',');
            td.kierunek =atof(double_str.c_str());

            getline(str, double_str, ',');
            td.wysokosc =atof(double_str.c_str());

            getline(str, double_str, ',');
            td.temp_inside =atof(double_str.c_str());


            pomiary.emplace_back(td);
            }

    }
    
    clock_t tStart = clock();
    sort_temperatura();
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0;
}
