#include <cppunit\TestFixture.h>
#include <cppunit\extensions\HelperMacros.h>
#include "TMatrix.h"

using namespace CppUnit;
using namespace tobechanged;

class MatrixTest : public TestFixture
{
    CPPUNIT_TEST_SUITE(MatrixTest);

    CPPUNIT_TEST(simple_construct);
    CPPUNIT_TEST(init_all);

    CPPUNIT_TEST(assign_test);
    CPPUNIT_TEST(copy_construct);

    CPPUNIT_TEST(add_m22);
    CPPUNIT_TEST(add_incompatible);

    CPPUNIT_TEST(sub_m22);
    CPPUNIT_TEST(sub_incompatible);

    CPPUNIT_TEST_SUITE_END();

    // construction related tests
    void simple_construct();
    void init_all();
    void copy_construct();

    // addition related tests
    void add_m22();
    void add_incompatible();

    // substraction related tests
    void sub_m22();
    void sub_incompatible();

    // assign
    void assign_test();

};
