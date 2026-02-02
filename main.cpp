#include <iostream>
#include "Vector.hpp"


int main()
{
    Vector<float, 2> u;
    std::cout << u.data[0] << u.data[1] << std::endl;
    
    float a[] = {2,4};
    Vector<float, 2> v(a);
    std::cout << v.data[0] << v.data[1] << std::endl;

    Vector<float, 2> w({5.0, 6.0});
    std::cout << w.data[0] << w.data[1] << std::endl;
  
    Vector<float, 2> x{56.0, 64.0};
    std::cout << x.data[0] << x.data[1] << std::endl;
    return 0;
}

