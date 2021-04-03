#ifndef _UTIL_HPP_
#define _UTIL_HPP_

/********************* Header Files ***********************/
#include <exception>
#include <iostream>
#include <set>
#include <vector>
#include <cmath>
#include <random>

namespace util {

/******************* Constants/Macros *********************/
    // Predictable
    // static std::default_random_engine generator;

    // Seeded
    std::random_device rd;
    static std::mt19937_64 generator(rd());


/******************* Type Definitions *********************/


/************** Class & Func Declarations *****************/
    auto roll_d4() -> int {
        static std::uniform_int_distribution<int> dis(1, 4);
        return dis(generator);
    }

    auto roll_d6() -> int {
        static std::uniform_int_distribution<int> dis(1, 6);
        return dis(generator);
    }

    auto roll_d8() -> int {
        static std::uniform_int_distribution<int> dis(1, 8);
        return dis(generator);
    }

    auto roll_d10() -> int {
        static std::uniform_int_distribution<int> dis(1, 10);
        return dis(generator);
    }

    auto roll_d12() -> int {
        static std::uniform_int_distribution<int> dis(1, 12);
        return dis(generator);
    }

    auto roll_d20() -> int {
        static std::uniform_int_distribution<int> dis(1, 20);
        return dis(generator);
    }

    auto roll_d100() -> int {
        static std::uniform_int_distribution<int> dis(1, 100);
        return dis(generator);
    }
}

#endif /* _UTIL_HPP_ */
