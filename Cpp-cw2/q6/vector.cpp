#include "vector.h"

// default constructor
Vector::Vector() : nn(0), v(nullptr) {}

// constructor with size
Vector::Vector(std::size_t n) : nn(n), v(new double[n]) {} 

// constructor with size and initial value
Vector::Vector(std::size_t n, double a) : nn(n), v(new double[n]) {
    for (std::size_t i = 0; i < nn; ++i) {
        v[i] = a;
    }
}

// constructor with size and array
Vector::Vector(std::size_t n, const double* a): nn(n), v(new double[n]) {
    for (std::size_t i = 0; i < nn; ++i) {
        v[i] = a[i];
    }
}

// copy constructor
Vector::Vector(const Vector& rhs): nn(rhs.nn), v(new double[rhs.nn]) {
    for (std::size_t i = 0; i < nn; ++i) {
        v[i] = rhs.v[i];
    }
}

// assignment operator
Vector& Vector::operator=(const Vector& rhs) {
    if(this != &rhs) {
        delete[] v; // free existing resource
        nn = rhs.nn;
        v = new double[nn]; // allocate new resource
        for (std::size_t i = 0; i < nn; ++i) {
            v[i] = rhs.v[i]; // copy elements
        }
    }
    return *this;
}

// resize vector to new size newn (content is not preserved)
void Vector::resize(std::size_t newn) {
    delete[] v; // free existing resource
    nn = newn;
    v = new double[nn]; // allocate new resource
}
    
// resize vector to new size newn and assign a constant value a to all elements
void Vector::assign(std::size_t newn, double a) {
    delete[] v; // free existing resource
    nn = newn;
    v = new double[nn]; // allocate new resource
    for (std::size_t i = 0; i < nn; ++i) {
        v[i] = a; // assign constant value
    }
}

// destructor
Vector::~Vector() {
    delete[] v; // free allocated memory
}
