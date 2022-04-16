#ifndef RUNGE_SECOND_ORDER_H
#define RUNGE_SECOND_ORDER_H

#include <functional>

#include "common/definitions.h"
#include "common/examples.h"

//formula (11.5)
double runge_kutta_2nd_order_1f_(const double x_begin,
                           const double x_end,
                           const double y_0,
                           const int N, 
                           AbstractExample * f_shtrih);

//formula (11.6) TODO
// double runge_kutta_2nd_order_2f_(const double x_begin,
//                            const double x_end,
//                            const double y_0,
//                            const int N, 
//                            std::function<double(c_double,c_double)> f_shtrih);



#endif /* RUNGE_SECOND_ORDER_H */