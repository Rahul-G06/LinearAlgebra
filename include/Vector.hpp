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
    // Constructor that initializes all values to some constant
    // explicit prevents implicit conversions
    explicit Vector(const T a);
    // Constructor from an array
    Vector(const T (&a)[size]);
    // Constructor from an initializer list
    Vector(std::initializer_list<T> A);
    // Copy constructor
    Vector(const Vector<T, size>& v);

    T data[size];

    Vector<T, size> operator+(const Vector<T, size>& v2) const;
    Vector<T, size> operator-(const Vector<T, size>& v2) const;
    Vector<T, size> operator*(const T c);
    friend Vector<T, size> operator*(const T& c, const Vector<T, size>& v)
    {
        Vector<T, size> temp;
        for(int i = 0; i < size; ++i) temp.data[i] = c * v.data[i];

        return temp;
    }
};

template <class T, int size>
Vector<T, size> operator*(const T& c, const Vector<T, size>& v);
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

//Constructor from a constant
template <class T, int size>
Vector<T, size>::Vector(const T a)
{
    for(int i = 0; i < size; ++i) data[i] = a;
}

// Constructor from an array
/*
Example usage:
    float a[] = {1.0, 2.0};
    Vector<float, 2> X(a);     
*/
template <class T, int size>
Vector<T, size>::Vector(const T (&a)[size])
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

// Copy constructor
/*
Example usage:
    Vector<float, 2> X{1.0, 2.0};
    Vector<float, 2> Y(X);
*/
template <class T, int size>
Vector<T, size>::Vector(const Vector<T, size>& v)
{
    for(int i = 0; i < size; ++i) data[i] = v.data[i];
}

// overload operator+
// This adds two vectors
template<class T, int size>
Vector<T, size> Vector<T, size>::operator+(const Vector<T, size>& v2) const
{
    Vector<T, size> temp;
    for(int i = 0; i < size; ++i) temp.data[i] = data[i] + v2.data[i];

    return temp;
}

// overload operator-
// This subtracts the second vector from the first
template<class T, int size>
Vector<T, size> Vector<T, size>::operator-(const Vector<T, size>& v2) const
{
    Vector<T, size> temp;
    for(int i = 0; i < size; ++i) temp.data[i] = data[i] - v2.data[i];

    return temp;
}

// overload operator*
// First, we have the member operator
// this handles Vector<T, size> * T c
template <class T, int size>
Vector<T, size> Vector<T, size>::operator*(const T c)
{
    Vector<T, size> temp;
    for(int i = 0; i < size; ++i) temp.data[i] = data[i] * c;
    
    return temp;
}