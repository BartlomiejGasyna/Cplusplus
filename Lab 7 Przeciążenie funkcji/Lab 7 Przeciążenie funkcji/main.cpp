#include <iostream>

using namespace std;

class Punkt3D {
  public:
    float x,y,z;
    Punkt3D() {x=y=z=0.0f;}
    Punkt3D operator+(int);
};

Punkt3D Punkt3D::operator+(int arg){
  Punkt3D tmp;
  tmp.x = x+(float)arg;
  tmp.y = y+(float)arg;
  tmp.z = z+(float)arg;
  return tmp;
}

ostream& operator<< (ostream &wyjscie, Punkt3D& s)
{
  wyjscie<<"["<<s.x<<", "<<s.y<<", "<<s.z<<"]"<<endl;
  return wyjscie;
}


class wektor {
  public:
    float dx,dy,dz;
    wektor() {dz=dy=dz=0.0f;}
};

ostream& operator<< (ostream &wyjscie, wektor &s)
{
  wyjscie<<"["<<s.dx<<", "<<s.dy<<", "<<s.dz<<"]"<<endl;
  return wyjscie;
}

Punkt3D operator+(Punkt3D temp, wektor wek)
{
    Punkt3D przesuniecie;
    przesuniecie.x = temp.x+wek.dx;
    przesuniecie.y = temp.y+wek.dy;
    przesuniecie.z = temp.z+wek.dz;
    return przesuniecie;
}
wektor operator*(wektor x, wektor y)
{
    wektor mnozenie;
    mnozenie.dx=((x.dy*y.dz)-(x.dz*y.dy));
    mnozenie.dy=((x.dz*y.dx)-(x.dx*y.dz));
    mnozenie.dz=((x.dx*y.dy)-(x.dy*y.dx));
    return mnozenie;
}

int main() {
  Punkt3D a;
  a.x = 3.0f;
  a.y = 5.0f;
  a.z = 0.0f;

  cout << a << endl;
  Punkt3D b = a+1;
  cout << b << endl;
    wektor A;
    A.dx=2;
    A.dy=2;
    A.dz=2;
    wektor mnoz1;
    mnoz1.dx=1;
    mnoz1.dy=2;
    mnoz1.dz=3;
    
    wektor mnoz2;
    mnoz2.dx=4;
    mnoz2.dy=5;
    mnoz2.dz=6;
    wektor iloczyn=mnoz1*mnoz2;
    Punkt3D X =a+mnoz1;
    //cout << X << endl;
    //cout<<iloczyn << endl;
    
    cout << "Translacja 1 punktu o 1 wektor: " << endl;
    cout << "Punkt: " << a << endl;
    cout << "Wektor: " << mnoz1 << endl;
    cout << "WYNIK: " << X << endl;
    
    cout << "Mnozenie wektorowe obu wektorow: " << endl;
    cout << "Wektor 1: " << mnoz1 << endl;
    cout << "Wektor 2: " << mnoz2 << endl;
    cout << "WYNIK: " << iloczyn << endl;
    
    cout << "Translacja drugiego punktu o wynik mnozenia: "<< endl;
    cout << "Punkt 2: " << b << endl;
    cout << "Wynik mnozenia: " << iloczyn << endl;
    Punkt3D wynik = b+iloczyn;
    cout << "Wynik: " << wynik << endl;
    
    cout << "Dodanie do drugiego punkut 3: " << endl;
    cout << "Punkt: " << b << endl;
    Punkt3D b_w=b+3;
    cout << b_w;
}
