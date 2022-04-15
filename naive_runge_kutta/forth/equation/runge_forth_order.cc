
#include "common/definitions.h"
#include "forth/equation/runge_forth_order.h"

#include <functional>

double runge_kutta_4rh_order_1f_(const double x_begin,
                           const double x_end,
                           const double y_0,
                           const int N, 
                           std::function<double(c_double,c_double)> f_shtrih) {
  
  double h = (x_end - x_begin) / static_cast <double> (N);
  double y_n = y_0;
  double one_sixth = 1.0/6.0;

  for (double x_n = x_begin; x_n < x_end; x_n += h) {
      double k1 = h*f_shtrih(x_n, y_n);
      double k2 = h*f_shtrih(x_n + h/2.0, y_n + k1/2.0);
      double k3 = h*f_shtrih(x_n + h/2.0, y_n + k2/2.0);
      double k4 = h*f_shtrih(x_n + h, y_n + k3);
      y_n = y_n + one_sixth * (k1+k2+k3+k4);
  }
  return y_n;
}