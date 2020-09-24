//
//  funkcje.hpp
//  Gasyna final
//
//  Created by Bartłomiej Gasyna on 15/03/2020.
//  Copyright © 2020 Bartłomiej Gasyna. All rights reserved.
//

#ifndef funkcje_h
#define funkcje_h

#include <stdio.h>

using namespace std;

void nwd(int a, int b);


void gcd(int a, int b);
void find_and_replace(string napis, string szukane, string zamiana);
void find(string napis, string szukane);
void okrag(int r);
vector <string> split(const string &napis, char sep=' ');
vector <string> split(const string &napis, char sep);
void ilosc_wyrazow(string sentence);
void najdluzszy(string txt);
#endif /* funkcje_h */
