#include "tests/tests.h"

#include <iostream>
#include <cstdlib>
#include <cmath>

#include "common/examples.h"
#include "common/examples_systems.h"
#include "second/runge_second_order.h"
#include "forth/equation/runge_forth_order.h"
#include "forth/system/sys_runge_forth_order.h"

void mock_example3() {
    // Example5 functions;
    
    // double N = 10000;                 //Amount of the intervals of [a,b]
    // double x_begin = functions.get_x_begin();    // a
    // double x_end = functions.get_x_end();     // b
    // //y(x_0) = y_0;
    // double y0 = functions.get_y0();
    // std::cout << "Runge-kutta 2nd order: " << runge_kutta_2nd_order_1f_(x_begin, x_end, y0, N, &functions) <<std::endl;
    // std::cout << "Strict solution: " << functions.f_sol(x_end) <<std::endl;
    
    // std::cout << "-----------------" << std::endl;
    // std::cout << "Runge-kutta 4rh order: " << runge_kutta_4rh_order_1f_(x_begin, x_end, y0, N, &functions) <<std::endl;
    // std::cout << "Strict solution: " << functions.f_sol(x_end) <<std::endl;

    SystemExample1 functions;

    std::pair<double, double> result = system_ode_runge_kutta_4rh_order_1f_(0, &functions);
    std::cout<< "Runge-kutta 4rh order" << std::endl;
    std::cout<< "Calculated y_n: "<< result.first << std::endl;
    std::cout<< "Calculated z_n: "<< result.second << std::endl;

    std::cout<< "Strict solution y_n: "<< functions.f_sol(functions.get_x_end()) << std::endl;
    std::cout<< "Strict solution z_n: "<< functions.g_sol(functions.get_x_end()) << std::endl;

}


void mock_system_example1() {
    SystemExample1 functions;

    system_ode_runge_kutta_4rh_order_1f_(0,&functions);
}