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

    // wait for user input
    char c;
    std::cin >> c;

    return 0;
}

