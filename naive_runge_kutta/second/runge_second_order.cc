
#include "common/definitions.h"
#include "common/examples.h"
#include "second/runge_second_order.h"

#include <functional>

double runge_kutta_2nd_order_1f_(const double x_begin,
                           const double x_end,
                           const double y_0,
                           const int N, 
                           AbstractExample * function) {
  double h = (x_end - x_begin) / static_cast <double> (N);
  double y_n = y_0;
  for (double x_n = x_begin; x_n < x_end; x_n += h) {
      double k1 = h * function->f_shtrih(x_n,y_n);
      double k2 = h * function->f_shtrih(x_n + h, y_n + k1);
      y_n = y_n + (k1+k2) / 2.0;
  }
  return y_n;
}