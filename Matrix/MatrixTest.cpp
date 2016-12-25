#include "stdafx.h"
#include "MatrixTest.h"

void MatrixTest::simple_construct() {
    
    Matrix<double> m_double(3, 4);
    
    CPPUNIT_ASSERT(m_double.row_number() == (3));
    CPPUNIT_ASSERT(m_double.col_number() == (4));
}


void MatrixTest::init_all() {
    
    Matrix<int> a(3, 2);

    a.init_all(5);

    for (int i = 0; i < 3; i++) {
        for (int k = 0; k < 2; k++) {
            CPPUNIT_ASSERT(a(i,k) == 5);
        }
    }
}


void MatrixTest::add_m22(){
    
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

void MatrixTest::add_incompatible() {

    Matrix<int> a(2, 2);
    a.init_all(1);

    Matrix<int> b(1, 2);
    b.init_all(2);

    Matrix<int> sum(2, 2);

    CPPUNIT_ASSERT_THROW(sum = a + b, std::range_error);
}


void MatrixTest::sub_m22(){
   
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

    Matrix<int> result = a - b;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            CPPUNIT_ASSERT(result(i, j) == (a(i, j) - b(i, j)));
        }
    }

}

void MatrixTest::sub_incompatible() {
    
    Matrix<int> a(2, 2);
    a.init_all(1);

    Matrix<int> b(1, 2);
    b.init_all(2);

    Matrix<int> result(2, 2);

    CPPUNIT_ASSERT_THROW(result = a - b, std::range_error);

}

void MatrixTest::assign_test() {

    Matrix<int> a(2, 3);
    int number = 1;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            a(i, j) = number++;
        }
    }

    number = 1;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            CPPUNIT_ASSERT(a(i, j) == number++);
        }
    }
}

void MatrixTest::copy_construct() {
    
    Matrix<int> a(2, 3);
    int number = 1;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            a(i, j) = number++;
        }
    }

    Matrix<int> b = a;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            CPPUNIT_ASSERT(a(i, j) == b(i,j));
        }
    }


}