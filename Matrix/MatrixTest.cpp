#include "stdafx.h"
#include "MatrixTest.h"

void MatrixTest::addM22(){
    
    Matrix<int> a(2, 2);
    
    a(0, 0) = 1;
    a(0, 1) = 2;

    a(1, 0) = -1;
    a(1, 1) = -2;

    Matrix<int> b(2, 2);

    b(0, 0) = 1;
    b(0, 1) = 2;

    b(1, 0) = -1;
    b(1, 1) = -2;


    Matrix<int> sum = a + b;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            CPPUNIT_ASSERT(sum(i,j) == (a(i,j) + b(i,j)));
        }
    }

}

void MatrixTest::addIncompatible() {

    Matrix<int> a(2, 2);
    a.init_all(1);

    Matrix<int> b(1, 2);
    b.init_all(2);

    Matrix<int> sum(2, 2);

    CPPUNIT_ASSERT_THROW(sum = a + b, std::range_error);


}