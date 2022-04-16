#ifndef RUNGE_FORTH_ORDER_H
#define RUNGE_FORTH_ORDER_H

#include <functional>

#include "common/definitions.h"
#include "common/functions.h"

//formula (11.10)
double runge_kutta_4rh_order_1f_(const double x_begin,
                           const double x_end,
                           const double y_0,
                           const int N, 
                           AbstractExample* function);


#endif /* RUNGE_FORTH_ORDER_H */