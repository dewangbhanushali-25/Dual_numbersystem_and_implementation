#include "Dual.hpp"
#include <iostream>

// A generic template function that can take standard doubles OR our Dual type
template <typename T>
T my_complex_function(const T& x) {
    using std::sin;
    using std::exp;
    return (x * x) * sin(x) + exp(x);
}

int main() {
    // To find the derivative with respect to x,
    // set the real value to 1.5, and seed the derivative part to 1.0 (dx/dx = 1)
    Dual x(1.5, 1.0);

    Dual result = my_complex_function(x);

    std::cout << "--- Dual Number AutoDiff Engine ---" << std::endl;
    std::cout << "Value at x=1.5:       " << result.val << std::endl;
    std::cout << "Derivative at x=1.5:  " << result.der << std::endl;

    return 0;
}
