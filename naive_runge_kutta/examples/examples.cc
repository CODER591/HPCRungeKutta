#include "examples/examples.h"

#include <iostream>
#include <cstdlib>
#include <cmath>

#include "common/functions.h"
#include "second/runge_second_order.h"
#include "forth/equation/runge_forth_order.h"

void mock_example3() {
    Example3 functions;
    
    double N = 10000;                 //Amount of the intervals of [a,b]
    double x_begin = 3.14 / 3.0;      // a
    double x_end = x_begin + 0.5;     // b
    //y(x_0) = y_0;
    double y0 = 0;
    std::cout << "Runge-kutta 2nd order: " << runge_kutta_2nd_order_1f_(x_begin, x_end, y0, N, &functions) <<std::endl;
    std::cout << "Strict solution: " << functions.f_sol(x_end) <<std::endl;
    
    std::cout << "-----------------" << std::endl;
    std::cout << "Runge-kutta 4rh order: " << runge_kutta_4rh_order_1f_(x_begin, x_end, y0, N, &functions) <<std::endl;
    std::cout << "Strict solution: " << functions.f_sol(x_end) <<std::endl;

}