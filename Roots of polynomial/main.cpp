//
//  main.cpp
//  lab 3 Miejsca zerowe
//
//  Created by Bartłomiej Gasyna on 19/03/2020.
//  Copyright © 2020 Bartłomiej Gasyna. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

//double get_poly( double x)
//{
//    return x*x*x-2*x*x-x-1;
//}
//vector<double> p;
double x_min =-10;
double x_max =20;
//void get_poly (double x_min, double x_max)
//{
//    for (double x = x_min; x < x_max+1; x++)
//        p.emplace_back(x*x*x-2*x*x-x-1);
//}
vector<double> p;
void get_poly (int n)
{
    //x^:4  3 2 1 0
    p = {0,-1,1,1,0}; //przypisanie wspolrzednych wielomianu na sztywno
    //p = {1,2,3,-4,-5};
    cout<<"Zostaniesz poproszony o podanie wspolczynnikow, aby wyjsc, podaj znak inny niz liczba"<<endl;

 //**********************************************
 //wlacz, by wczytac od uzytkownika
 //**********************************************
    /*
    for(int i=n; i>-1; i--)
    {
        
        cout<<endl<<"Podaj wspolczynnik x^"<<i <<": ";
        double wspolczynnik;
        string double_str;
        //cin.ignore();
        getline(cin, double_str);
        
        try {
            wspolczynnik = stod(double_str);
            
        }
        catch (...) {
            cout<<"Exit!"<<endl;
            exit(0);

        }
        p.emplace(p.begin(), wspolczynnik);
    }
 */
     
}
double res(double x)
{
    double y =0;
    for (int i =0; i!=p.size(); i++)
    {
        y+=p[i] * pow(x,i);
    }
    return y;
}
vector<double> zeros;
vector<double> temp;
double step = 1;

void zero_r(double bottom,double top)
{

    double mid=(bottom+top)/2;
    while(bottom<=top)
        {
            cout<<"bottom: "<<bottom<<endl;
            cout<<"mid: "<<mid<<endl;
            cout<<"top: "<<top<<endl;
            cout<<res(mid)<<endl;
            cout <<endl;
            mid=(bottom+top)/2;
            if (res(mid) >= 0-(1e-9) && res(mid) <= 0 +(1e-9))
                {
                    break;
                }

            if (res(mid) > 0 +(1e-9))
                {
                    //top = mid-0.1;
                    top -=0.01;
                }

            if (res(mid) < 0 +(1e-9))
                {
                    //bottom = mid+0.1;
                    bottom+=0.01;
                }
        }
    cout << "miejsce zerowe z binarnego to: " << mid << endl;
    zeros.emplace_back(mid);
}


void zero (double x_min, double x_max,vector<double> p, double step)
{
    cout << "Wartosci funkcji w przedziale <"<< x_min <<", " << x_max<<">:"<<endl;
    for (double x = x_min; x < x_max+1; x+=step)
    {
        double wynik = res(x);
        cout <<"x = "<< x << ": " << wynik << endl;
        
        
        if(wynik == 0)
        {
            zeros.emplace_back(x);
            //cout << " wyzej jest miejsce zerowe" << endl;
        }
        temp.emplace_back(wynik);
    }
        for (int i =0; i!=temp.size()-1; i++)
               {
//                   if ((temp[i]<0+(1e-9) && temp[i+1] >0) || (temp[i]>0+(1e-9) && temp[i+1] <0))
                       //if ((temp[i]<-0.05 && temp[i+1] >0.05) || (temp[i]>0.05 && temp[i+1] <-0.05))
                  if ((temp[i]<=0 && temp[i+1] >0) || (temp[i]>=0 && temp[i+1] <0))
                   {
//                   cout << endl << endl;
//                       cout << " temp: " << i << " wynik: " << temp[i] << endl;
//                   cout << " temp: " << i+1 << " wynik: " << temp[i+step] << endl << endl;
//
               cout << "ZMIANA ZNAKU" << endl << endl;
                       zero_r(x_min+i, x_min+i+step);
                   }
               }
    }

int main() {
    get_poly(4); //pobranie wspolrzednych wielomianu
    
    for (int i = 0; i!=p.size(); i++) {
        cout << p[i] <<endl;
    }
    cout << res( 2 ) << endl;
    
    zero(x_min, x_max, p, step);
    
    cout << "miejsca zerowe: " << endl;
    for (int i = 0; i!= zeros.size(); i++) {
        cout << zeros[i] << endl;
        
    }

    return 0;
}
