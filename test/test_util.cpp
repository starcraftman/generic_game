/**
 * Test the util library.
 */
/********************* Header Files ***********************/
/* C++ Headers */
// #include <iostream> [> Input/output objects. <]
//#include <fstream> /* File operations. */
//#include <sstream> /* String stream. */
// #include <string> [> C++ String class. <]
//#include <exception> /* Top level exception header. */

#include "boost/assign/list_of.hpp"
#include "gtest/gtest.h"

#include "util.hpp"

/**************** Namespace Declarations ******************/
using std::cin;
using std::cout;
using std::endl;
using std::string;

TEST(Util, Roll6) {
    int rolled = util::d6();
    ASSERT_EQ(1, rolled);
}
