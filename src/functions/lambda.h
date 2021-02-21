#pragma once
#include <doctest/doctest.h>

namespace Lambda {
void lamdbaHello(void);
int factorial(int number);
}  // namespace Lambda

TEST_CASE("testing the factorial function") {
    CHECK(Lambda::factorial(1) == 1);
    CHECK(Lambda::factorial(2) == 2);
    CHECK(Lambda::factorial(3) == 6);
    CHECK(Lambda::factorial(10) == 3628800);
}