#ifndef FORTH_EQUATION_RUNGE_FORTH_ORDER_H
#define FORTH_EQUATION_RUNGE_FORTH_ORDER_H

#include <functional>

#include "common/definitions.h"
#include "common/examples.h"

//formula (11.10)
double runge_kutta_4rh_order_1f_(const double x_begin,
                           const double x_end,
                           const double y_0,
                           const int N, 
                           AbstractExample* function);


#endif /* FORTH_EQUATION_RUNGE_FORTH_ORDER_H */