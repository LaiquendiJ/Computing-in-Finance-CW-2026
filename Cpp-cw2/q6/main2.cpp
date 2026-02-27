#include <iostream>
#include "vector.h"

static void print_vec(const char* name, const Vector& x) {
    std::cout << name << " (n=" << x.size() << "): ";
    for (std::size_t i = 0; i < x.size(); ++i) std::cout << x[i] << " ";
    std::cout << "\n";
}

int main() {
    // Test 1: default constructor
    Vector a;
    std::cout << "a.size() = " << a.size() << "\n";

    // Test 2: Vector(n) zero-init
    Vector b(3);
    print_vec("b", b); // should be 0 0 0

    // Test 3: Vector(n, const)
    Vector c(4, 2.5);
    print_vec("c", c); // 2.5 2.5 2.5 2.5

    // Test 4: Vector(n, array)
    double raw[3] = {1.0, -1.0, 4.0};
    Vector d(3, raw);
    print_vec("d", d); // 1 -1 4

    // Test 5: copy constructor deep copy
    Vector e = d;
    e[0] = 99.0;
    print_vec("d (after e modified)", d); // should still start with 1
    print_vec("e", e);                    // should start with 99

    // Test 6: assignment deep copy
    Vector f(2, 7.0);
    f = c;
    f[1] = -123.0;
    print_vec("c (after f modified)", c); // unchanged
    print_vec("f", f);                    // modified

    // Test 7: self-assignment shouldn’t crash
    Vector& ref = f;
    f = ref;
    print_vec("f (after self-assign)", f);

    // Test 8: resize (contents not preserved)
    d.resize(5);
    std::cout << "d resized to " << d.size() << "\n";
    // contents unspecified, but should not crash:
    d[0] = 10.0;
    d[4] = 20.0;
    print_vec("d", d);

    // Test 9: assign
    d.assign(3, 8.0);
    print_vec("d (after assign)", d); // 8 8 8

    std::cout << "All tests ran.\n";
    return 0;
}