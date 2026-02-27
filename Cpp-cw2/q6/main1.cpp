#include <iostream>

class Vector {
private:
    int nn; // size of array; upper index is nn - 1 
    double* v;

public:
    // default constructor
    Vector() : nn(0), v(nullptr) {}

    // constructor with size
    explicit Vector(int n) : nn(n), v(new double[n]) {} 

    // constructor with size and initial value
    Vector(int n, double a) : nn(n), v(new double[n]) {
        for (int i = 0; i < nn; ++i) {
            v[i] = a;
        }
    }

    // constructor with size and array
    Vector(int n, const double* a): nn(n), v(new double[n]) {
        for (int i = 0; i < nn; ++i) {
            v[i] = a[i];
        }
    }

    // copy constructor
    Vector(const Vector& rhs): nn(rhs.nn), v(new double[rhs.nn]) {
        for (int i = 0; i < nn; ++i) {
            v[i] = rhs.v[i];
        }
    }

    // assignment operator
    Vector& operator=(const Vector& rhs) {
        if(this != &rhs) {
            delete[] v; // free existing resource
            nn = rhs.nn;
            v = new double[nn]; // allocate new resource
            for (int i = 0; i < nn; ++i) {
                v[i] = rhs.v[i]; // copy elements
            }
        }
        return *this;
    }

    // get element at index i
    inline double& operator[](const int i) {
        return v[i];
    }
    
    // get element at index i (const version)
    inline const double& operator[](const int i) const {
        return v[i];
    }

    // get size of vector
    inline int size() const{
        return nn;
    }

    // resize vector to new size newn (content is not preserved)
    void resize(int newn) {
        delete[] v; // free existing resource
        nn = newn;
        v = new double[nn]; // allocate new resource
    }
    
    // resize vector to new size newn and assign a constant value a to all elements
    void assign(int newn, double a) {
        delete[] v; // free existing resource
        nn = newn;
        v = new double[nn]; // allocate new resource
        for (int i = 0; i < nn; ++i) {
            v[i] = a; // assign constant value
        }
    }

    // destructor
    ~Vector() {
        delete[] v; // free allocated memory
    }
};

// helper function to print vector contents
static void print_vec(const char* name, const Vector& x) {
    std::cout << name << " (n=" << x.size() << "): ";
    for (int i = 0; i < x.size(); ++i) std::cout << x[i] << " ";
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