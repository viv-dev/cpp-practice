#include "lambda.h"

#include <functional>
#include <iostream>

namespace Lambda {
void lamdbaHello() {
    [out = std::ref(std::cout << "Hello")]() { out.get() << " World\n"; }();
}

int factorial(int number) {
    return (number > 1) ? (factorial(number - 1) * number) : 1;
}
}  // namespace Lambda
