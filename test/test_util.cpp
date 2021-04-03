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

#include "gtest/gtest.h"

#include "util.hpp"

/**************** Namespace Declarations ******************/
using std::cin;
using std::cout;
using std::endl;
using std::string;

TEST(Rolls, D4) {
    int rolled = util::roll_d4();
    ASSERT_GE(rolled, 1);
    ASSERT_LE(rolled, 4);
}

TEST(Rolls, D6) {
    int rolled = util::roll_d6();
    ASSERT_GE(rolled, 1);
    ASSERT_LE(rolled, 6);
}

TEST(Rolls, D8) {
    int rolled = util::roll_d8();
    ASSERT_GE(rolled, 1);
    ASSERT_LE(rolled, 8);
}

TEST(Rolls, D10) {
    int rolled = util::roll_d10();
    ASSERT_GE(rolled, 1);
    ASSERT_LE(rolled, 10);
}

TEST(Rolls, D12) {
    int rolled = util::roll_d12();
    ASSERT_GE(rolled, 1);
    ASSERT_LE(rolled, 12);
}

TEST(Rolls, D20) {
    int rolled = util::roll_d20();
    ASSERT_GE(rolled, 1);
    ASSERT_LE(rolled, 20);
}

TEST(Rolls, D100) {
    int rolled = util::roll_d100();
    ASSERT_GE(rolled, 1);
    ASSERT_LE(rolled, 100);
}
