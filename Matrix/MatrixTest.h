#include <cppunit\TestFixture.h>
#include <cppunit\extensions\HelperMacros.h>
#include "TMatrix.h"

using namespace CppUnit;
using namespace tobechanged;



class MatrixTest : public TestFixture
{

    CPPUNIT_TEST_SUITE( MatrixTest );
    CPPUNIT_TEST(addM22);
    CPPUNIT_TEST(addIncompatible);
    CPPUNIT_TEST_SUITE_END();
    

    void addM22();
    void addIncompatible();


    
};

