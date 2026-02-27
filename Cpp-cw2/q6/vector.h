#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>      // for std::size_t
#include <stdexcept>    // for std::out_of_range

class Vector {
private:
    std::size_t nn;
    double* v;

public:
    // constructors
    Vector();
    explicit Vector(std::size_t n);
    Vector(std::size_t n, double a);
    Vector(std::size_t n, const double* a);
    
    // copy and assignment
    Vector(const Vector& rhs);
    Vector& operator=(const Vector& rhs);

    // element access
    inline double& operator[](const std::size_t i);
    inline const double& operator[](const std::size_t i) const;
    
    // size size
    inline std::size_t size() const;
    
    // mofifiers
    void resize(std::size_t newn);
    void assign(std::size_t newn, double a);
    
    // destructor
    ~Vector();
};


// get element at index i
inline double& Vector::operator[](const std::size_t i) {
    if (i >= nn)
        throw std::out_of_range("Index out of range");
    return v[i];
}
    
// get element at index i (const version)
inline const double& Vector::operator[](const std::size_t i) const {
    if (i >= nn)
        throw std::out_of_range("Index out of range");
    return v[i];
}

// get size of vector
inline std::size_t Vector::size() const{
    return nn;
}
#endif