//
//  Matrix.hpp
//  proiect
//
//  Created by Petrino Popa on 21/03/2020.
//  Copyright © 2020 Petrino Popa. All rights reserved.
//

#ifndef Matrice_hpp
#define Matrice_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Matrix{
    int m_rowSize;
    int m_colSize;
    vector<vector<double> > m_matrix;

public:
    Matrix(int, int, double);
    Matrix(const char *);
    Matrix(const Matrix &);
    ~Matrix();
    Matrix operator+(Matrix &);
    Matrix operator-(Matrix &);
    Matrix operator*(Matrix &);
    Matrix transpusa();
    Matrix operator*(double);
    double& operator()(const int &, const int &);
    double& operator[](const int &, const int &);
    void print() const;
    int getRows() const;
    int getCols() const;
    Matrix determinant();
    int inversabila() const;

};

#endif
