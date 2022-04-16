
#include "common/definitions.h"
#include "common/examples_systems.h"
#include "forth/system/sys_runge_forth_order.h"

#include <functional>

std::pair<double, double> system_ode_runge_kutta_4rh_order_1f_(
                           const int N, 
                           AbstractSystemExample* function) {
  double x_begin = function->get_x_begin();
  double x_end = function->get_x_end();
  //double h = (x_end - x_begin) / static_cast <double> (N); //not this case
  double h = function->get_ab_interval_step();
  double y_n = function->get_y0();
  double z_n = function->get_z0();
  double one_sixth = 1.0/6.0;

  for (double x_n = x_begin; x_n < x_end; x_n += h) {
      
      double k1 = h * function->f_shtrih(x_n, y_n, z_n);
      double l1 = h * function->g_shtrih(x_n, y_n, z_n);
      
      double k2 = h * function->f_shtrih(x_n + h/2.0, y_n + k1/2.0, z_n + l1/2.0);
      double l2 = h * function->g_shtrih(x_n + h/2.0, y_n + k1/2.0, z_n + l1/2.0);

      double k3 = h * function->f_shtrih(x_n + h/2.0, y_n + k2/2.0, z_n + l2/2.0);
      double l3 = h * function->g_shtrih(x_n + h/2.0, y_n + k2/2.0, z_n + l2/2.0);

      double k4 = h * function->f_shtrih(x_n + h, y_n + k3, z_n + l3);
      double l4 = h * function->g_shtrih(x_n + h, y_n + k3, z_n + l3);

      y_n = y_n + one_sixth*(k1 + 2.0*k2 + 2.0*k3 + k4);
      z_n = z_n + one_sixth*(l1 + 2.0*l2 + 2.0*l3 + l4);
  }
  return std::pair<double, double>(y_n, z_n);
}