//
//  main.cpp
//  proiect
//
//  Created by Petrino Popa on 20/03/2020.
//  Copyright © 2020 Petrino Popa. All rights reserved.
//


#include <vector>
#include <string.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <cmath>
#include "Matrice.hpp"

using namespace std;

int main() {
    int mat6,row,col;
    Matrix mat1(10,10,1.0);
    Matrix mat2(10,10,2.0);
    Matrix mat3 = mat1 + mat2;
    Matrix mat4 = mat1 - mat2;
    Matrix mat5 = mat1 * mat2;
    mat6 = mat1(1,1);
    int mat7 = mat1[1];
    row = mat1.getRows();
    col = mat1.getCols();
    mat1.print();
    cout<<endl;
    mat2.print();
    cout<<endl;
    mat3.print();
    cout<<endl;
    mat4.print();
    cout<<endl;
    mat5.print();
    cout<<endl;
    Matrix mat8 = mat1.transpusa();
    mat8.print();
    cout<<endl;
    cout<<mat6<<" "<<mat7<<" "<<row<<" "<<col;
    
    return 0;
}
