#ifndef RUNGE_FORTH_ORDER_H
#define RUNGE_FORTH_ORDER_H

#include <functional>

#include "common/definitions.h"

//formula (11.10)
double runge_kutta_4rh_order_1f_(const double x_begin,
                           const double x_end,
                           const double y_0,
                           const int N, 
                           std::function<double(c_double,c_double)> f_shtrih);


#endif /* RUNGE_FORTH_ORDER_H */