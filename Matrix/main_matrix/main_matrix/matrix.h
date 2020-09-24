//
//  matrix.h
//  main_matrix
//
//  Created by Bartłomiej Gasyna on 26/04/2020.
//  Copyright © 2020 Bartłomiej Gasyna. All rights reserved.
//

#ifndef matrix_h
#define matrix_h
#include <vector>
#include <random>
#include <iostream>


//using namespace std;

template <typename T>
class Matrix {
//    using  row = std::tuple<T,T,T>;
//    std::vector<row> column;
     int rozmiar = 0;
     std::vector<std::vector<T> > mat;
//    static std::vector<int> temp;
//    static std::vector<std::vector<int>> Temp2;
public:
    Matrix()
    {
       std::cout << "pusto" << std::endl;
    }
    
    Matrix(int rows, int columns)
    {
        mat.resize(rows);
        for (auto &row:mat)
        {
            row.resize(columns,0);
        }
    }
    Matrix(std::vector<std::vector<T>> mat_arg)
    {
        mat=mat_arg;
        for (auto &col : mat_arg)
        {
            std::cout << "| ";
            for (auto &row : col)
            {
                
                rozmiar++;
                std::cout << row << " ";
                
            }
            std::cout << "|"<< std::endl;
        }
        if(mat_arg.size())
        rozmiar = rozmiar / mat_arg.size();
        std::cout <<"ilosc wierszy: " << rozmiar << std::endl;
        std::cout <<"ilosc kolumn: " << mat_arg.size() << std::endl;
        
    }

    static Matrix eye(const T &row,const T &b)
    {
        std::vector<int> temp;
        std::vector<std::vector<int>> Temp2;
        for (int j=0; j<row; j++) {
            
            temp.clear();
            for (int k=0; k<row; k++){
                
                    if(j==k) {
                    temp.push_back(1);
                    }
                    else {
                    temp.push_back(0);
                    }
                }
                Temp2.push_back(temp);
            }
        Matrix temp_mat(Temp2);
        temp.clear();
        Temp2.clear();
        return temp_mat;
    }




    static Matrix fill(int row,int col,int random);


    friend Matrix &operator*(int val, Matrix &m)
    {
        for(auto &col: m.mat)
        {
            for(auto &row :col)
            {
                row=val*row;
            }
        }
        return m;
    }
    friend Matrix &operator*(const Matrix &n, Matrix &m)
    {
        return m;
    }
    
    friend Matrix &operator*(Matrix &n, int val)
    {
        for(auto &col: n.mat)
        {
            for(auto &row :col)
            {
                row=row*val;
            }
        }
        return n;
    }
    friend Matrix &operator+(Matrix &n, int val)
    {
        for(auto &col: n.mat)
        {
            for(auto &row :col)
            {
                row=row+val;
            }
        }
        return n;
    }
    
    friend std::ostream &operator<<(std::ostream &out, Matrix &mat)
    {
        for(auto &el : mat.mat)
        {
            out << "|";

            for(auto &val : el)
            {
                out << val << " ";
            }
            out << "|" << std::endl;
        }
        return out;
    }
    
    friend Matrix &operator>>(std::istream &in, Matrix &mat)
    {
        T el;
        int col, row;
        std::cout << "liczba wierszy " << std::endl;
        in >> col;
        std::cout << "liczba kolumn: " << std::endl;
        in >> row;
        std::vector<T> temp;
        std::vector<std::vector<T>> Temp2;
        
        for (int j=0; j<col; j++) {
            temp.clear();
            for (int k=0; k<row; k++){
                std::cout << j+1 <<" , " << k+1 << ":"<< std::endl;
                in>>el;
                    temp.push_back(el);
                    
                }
                Temp2.push_back(temp);
            }
        std::cout<<"Twoja macierz: "<<std::endl;
        Matrix temp_mat(Temp2);
        temp.clear();
        Temp2.clear();
        return temp_mat;
    }
    
};

#endif /* matrix_h */
