#include <iostream>
#include <cstdlib>
#include <cmath>

#include "second/runge_second_order.h"

double f_sol(double x) {
    return 2.0 - 4.0 * std::cos(x);
}

double f_shtrih(const double x, const double y) {
    return (2.0 - y) * std::tan(x);
}


int main () {
    
    double N = 10000;                 //Amount of the intervals of [a,b]
    double x_begin = 3.14 / 3.0;      // a
    double x_end = x_begin + 0.5;     // b
    //y(x_0) =y_0;
    double y0 = 0;
    std::cout << "Runge-kutta: " << runge_kutta_2nd_order_1f_(x_begin, x_end, y0, N, f_shtrih) <<std::endl;
    std::cout << "Strict solution: " << f_sol(x_end) <<std::endl;

    return 0;
}