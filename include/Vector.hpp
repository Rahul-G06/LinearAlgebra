#pragma once
#include <stdexcept>
#include <type_traits>
#include <initializer_list>

template <class T, int size>
class Vector
{
    // this ensures that the vector is of a numeric type
    // also, the size of the vector must be greater than 0
    static_assert(std::is_arithmetic<T>::value, "Vector<T, size>: T must be a numeric type");
    static_assert(size > 0, "Size of vector must be greater than 0");

public:
        
    // Default constructor
    Vector();
    // Constructor from an array
    Vector(T a[size]);
    // Constructor from an initializer list
    Vector(std::initializer_list<T> A);

    T data[size];
};

// Default constructor
// We don't initialize the values since that is unnecessary computation
// Therefore this creates a Vector with garbage values.
/*
Example usage:
    
    Vector<float, 2> X;
    Vector<double, 3> Y(); 
*/
template <class T, int size>
Vector<T, size>::Vector()
{

}


// Constructor from an array
/*
Example usage:

    float a[] = {1.0, 2.0};
    Vector<float, 2> X(a);     
*/
template <class T, int size>
Vector<T, size>::Vector(T a[size])
{
    for(int i = 0; i < size; ++i) data[i] = a[i];
}


// Constructor from an initializer list
/*
Example usage:
    Vector<float, 2> X{1.0, 2.0};
    Vector<double, 3> Y({1.0, 2.0, 3.0});
*/
template <class T, int size>
Vector<T, size>::Vector(std::initializer_list<T> A)
{
    if(A.size() != size)
        throw std::runtime_error("Incorrect size of initializer list for Vector");

    int i = 0;
    for(T a : A)
        data[i++] = a;
}
