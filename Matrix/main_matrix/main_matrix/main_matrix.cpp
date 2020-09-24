
#include "matrix.h"


int main(int argc, const char * argv[]) {
    // tworzy macierze 3x3
    Matrix<double> M(3, 3);
    Matrix<double> C({{1, 0, 0},
                      {0, 1, 0},
                        {0, 0, 1}});
    
    
    
    Matrix<double> D;

    std::cin >> D; // pobiera dane od użytkownika (zarówno jej wymiar jak i wartości poszczególnych elementów)
//
    Matrix<int>  X = Matrix<int>::eye(3,3); // metoda statyczna, zwraca macierz jednostkową
    //std::cout<< X; //wypisuje macierz automatycznie przy konstruktorze.

//
//    // inicjalizacja zmienną losową
//    static std::default_random_engine e{};
//    std::uniform_int_distribution<int> distriubution{0, 100};
//   // Matrix<int>  Y = Matrix<int>::fill(3, 3, [&distriubution](){ return distriubution(e); });
//
//    Matrix<int>  Y = Matrix<int>::fill(3, 3, distriubution(e));
//    // metoda statyczna, zwraca macierz o wymiarze 3x3, wypełnioną wartościami generowanymi przez funkcję będącą trzecim argumentem
//
    Matrix<double>  B = 5 * M  * 5 + 1; // operacje arytmetyczne na macierzach - zdefiniuj wszystkie niezbędne operatory
    std::cout << B << std::endl;
//
    return 0;
}
