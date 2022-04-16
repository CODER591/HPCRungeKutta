#ifndef FORTH_SYSTEM_SYS_RUNGE_FORTH_ORDER_H
#define FORTH_SYSTEM_SYS_RUNGE_FORTH_ORDER_H

#include <functional>

#include "common/definitions.h"
#include "common/examples_systems.h"


std::pair<double, double> system_ode_runge_kutta_4rh_order_1f_(const int N, AbstractSystemExample* function);

#endif /* FORTH_SYSTEM_SYS_RUNGE_FORTH_ORDER_H */