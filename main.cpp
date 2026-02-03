#include <iostream>
#include "Vector.hpp"


int main()
{
    Vector<float, 2> u;
    std::cout << u.data[0] << " " << u.data[1] << std::endl;

    Vector<float, 2> z(0);
    std::cout << z.data[0] << " " << z.data[1] << std::endl;
    
    float a[] = {2,4};
    Vector<float, 2> v(a);
    std::cout << v.data[0] << " " << v.data[1] << std::endl;

    Vector<float, 2> w({5.0, 6.0});
    std::cout << w.data[0] << " " << w.data[1] << std::endl;
  
    Vector<float, 2> x{6.0, 7.0};
    std::cout << x.data[0] << " " << x.data[1] << std::endl;

    Vector<float, 2> y(x);
    std::cout << y.data[0] << " " << y.data[1] << std::endl;

    Vector<float, 2> p = w + x;
    std::cout << p.data[0] << " " << p.data[1] << std::endl;

    Vector<float, 2> q = 3 * p;
    std::cout << q.data[0] << " " << q.data[1] << std::endl;

    Vector<float, 2> r = p * 2;
    std::cout << r.data[0] << " " << r.data[1] << std::endl;
    r = r / 2;
    std::cout << r.data[0] << " " << r.data[1] << std::endl;

    r += r;
    std::cout << r.data[0] << " " << r.data[1] << std::endl;
    r -= r / 2;
    std::cout << r.data[0] << " " << r.data[1] << std::endl;
    r *= 3;
    std::cout << r.data[0] << " " << r.data[1] << std::endl;
    r /= 4;
    std::cout << r.data[0] << " " << r.data[1] << std::endl;

    p = -r;
    std::cout << p.data[0] << " " << p.data[1] << std::endl;

    Vector<int, 2> s;
    s = p;
    std::cout << s.data[0] << " " << s.data[1] << std::endl;

    Vector<int, 2> t(r);
    std::cout << t.data[0] << " " << t.data[1] << std::endl;
    return 0;
}