// Matrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "TMatrix.h"
#include "MatrixTest.h"
#include <cppunit\Exception.h>
#include <cppunit\ui\text\TestRunner.h>
#include <cppunit\ui\text\TextTestRunner.h>



int main()
{

    CPPUNIT_TEST_SUITE_REGISTRATION(MatrixTest);
    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest(registry.makeTest());
    runner.run();


/*
    using namespace tobechanged;

    Matrix<double> matrix = Matrix<double>(2, 2);
    matrix.init_all(0);

    matrix(0, 0) = 1;
    matrix(0, 1) = 2;
    matrix(1, 0) = 3;
    matrix(1, 1) = 4;
    matrix.print_out();

    Matrix<double> matrix2 = Matrix<double>(2, 2);
    matrix2.init_all(0);

    matrix2(0, 0) = 1;
    matrix2(0, 1) = 2;
    matrix2(1, 0) = 3;
    matrix2(1, 1) = 4;
    matrix2.print_out();

    Matrix<double> matrix3 = matrix + matrix + matrix;
    matrix3.print_out();
    try {
        Matrix<double> matrix4(2, 2);
        matrix4.print_out();
        matrix4 = matrix3;
        matrix4.print_out();
    }
    catch (std::range_error& e) {
        std::cout << e.what() << "\n";
    }
    

    // multiplication
    Matrix<double> m_mult_op_1(3, 3);
    m_mult_op_1(0, 0) = 1;
    m_mult_op_1(0, 1) = 2;
    m_mult_op_1(0, 2) = 3;

    m_mult_op_1(1, 0) = 4;
    m_mult_op_1(1, 1) = 5;
    m_mult_op_1(1, 2) = 6;

    m_mult_op_1(2, 0) = 7;
    m_mult_op_1(2, 1) = 8;
    m_mult_op_1(2, 2) = 9;


    Matrix<double> m_mult_op_2(3, 1);
    m_mult_op_2(0, 0) = -1;
    m_mult_op_2(1, 0) = 2;
    m_mult_op_2(2, 0) = -3;

    Matrix<double> multiply = m_mult_op_1 * m_mult_op_2;
    multiply.print_out();
  */

    return 0;
}

