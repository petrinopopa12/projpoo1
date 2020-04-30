//
//  Matrix.cpp
//  proiect
//
//  Created by Petrino Popa on 21/03/2020.
//  Copyright © 2020 Petrino Popa. All rights reserved.
//

#include "Matrice.hpp"
#include <vector>
#include <string.h>
using namespace std;

Matrix::Matrix(int rowSize, int colSize, double initial){
    m_rowSize = rowSize;
    m_colSize = colSize;
    m_matrix.resize(rowSize);
    for (int i = 0; i < m_matrix.size(); i++)
    {
        m_matrix[i].resize(colSize, initial);
    }
}

Matrix Matrix::operator+(Matrix &B){
    Matrix sum(m_colSize, m_rowSize, 0.0);
    int i,j;
    for (i = 0; i < m_rowSize; i++)
    {
        for (j = 0; j < m_colSize; j++)
        {
            sum(i,j) = this->m_matrix[i][j] + B(i,j);
        }
    }
    return sum;
}


Matrix Matrix::operator-(Matrix & B){
    Matrix diff(m_colSize, m_rowSize, 0.0);
    int i,j;
    for (i = 0; i < m_rowSize; i++)
    {
        for (j = 0; j < m_colSize; j++)
        {
            diff(i,j) = this->m_matrix[i][j] - B(i,j);
        }
    }
    
    return diff;
}

Matrix Matrix::operator*(Matrix & B){
    Matrix multi(m_rowSize,B.getCols(),0.0);
    if(m_colSize == B.getRows())
    {
        int i,j,k;
        double temp = 0.0;
        for (i = 0; i < m_rowSize; i++)
        {
            for (j = 0; j < B.getCols(); j++)
            {
                temp = 0.0;
                for (k = 0; k < m_colSize; k++)
                {
                    temp += m_matrix[i][k] * B(k,j);
                }
                multi(i,j) = temp;
            }
        }
        return multi;
    }
    else
    {
        return "Error";
    }
}

Matrix Matrix::operator*(double scalar){
    Matrix result(m_rowSize,m_colSize,0.0);
    int i,j;
    for (i = 0; i < m_rowSize; i++)
    {
        for (j = 0; j < m_colSize; j++)
        {
            result(i,j) = this->m_matrix[i][j] * scalar;
        }
    }
    return result;
}


double& Matrix::operator()(const int &rowNo, const int & colNo)
{
    return this->m_matrix[rowNo][colNo];
}


double& Matrix::operator[](const int & colNo)
{
    return this->m_matrix[rowNo];
}


int Matrix::getRows() const
{
    return this->m_rowSize;
}


int Matrix::getCols() const
{
    return this->m_colSize;
}


Matrix Matrix::transpusa()
{
    Matrix Transpusa(m_colSize,m_rowSize,0.0);
    for (int i = 0; i < m_colSize; i++)
    {
        for (int j = 0; j < m_rowSize; j++) {
            Transpusa(i,j) = this->m_matrix[j][i];
        }
    }
    return Transpusa;
}


void Matrix::print() const
{
    cout << "Matrix: " << endl;
    for (int i = 0; i < m_rowSize; i++) {
        for (int j = 0; j < m_colSize; j++) {
            cout << "[" << m_matrix[i][j] << "] ";
        }
        cout << endl;
    }
}

//nu am facut determinantul, dar l-am folosit la inversabilitate
Matrix Matrix::determinant();

int Matrix::inversabila() const
{
    if (m_matrix.determinant == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
