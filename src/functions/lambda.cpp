#include "lambda.h"

#include <functional>
#include <iostream>

namespace Lambda {
void lamdbaHello() {
    [out = std::ref(std::cout << "Hello")]() { out.get() << " World\n"; }();
}
}  // namespace Lambda
