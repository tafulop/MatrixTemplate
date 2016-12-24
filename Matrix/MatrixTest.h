

#include <cppunit\TestFixture.h>
#include <cppunit\extensions\HelperMacros.h>
#include "TMatrix.h"

using namespace CppUnit;
using namespace tobechanged;

class MatrixTest : public TestFixture
{

private:
    Matrix<double>* m1;
    Matrix<double>* m2;
public:

    void setUp() {
        m1 = new Matrix<double>(2, 2);
        m2 = new Matrix<double>(2, 2);
    }

    void tearDown() {
        delete m1;
        delete m2;
    }

    void initTest() {
        m1->init_all(0);

        CPPUNIT_ASSERT((*m1)(0, 0) == 0);
        CPPUNIT_ASSERT(false);
    }


    MatrixTest();
    ~MatrixTest();
};

