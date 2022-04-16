#ifndef FUNCTIONS_H
#define FUNCTIONS_H


#include <cmath>


struct AbstractExample {
    //y(x_0) = y_0;
    virtual double get_x_begin() = 0;
    virtual double get_y0() = 0;

    virtual double f_sol(double x) = 0;
    virtual double f_shtrih(const double x, const double y) = 0;
    virtual ~AbstractExample() {}

    double get_step() {
        return 0.5;
    }

    double get_x_end() {
        return get_x_begin() + get_step();
    }
};

/* page 330, example3 */
struct Example3 : public AbstractExample {
    double get_x_begin() override {
        // pi/3
        return 3.14/3.0;
    }
    
    double get_y0() override {
        // y(pi/3) = 0;
        return 0;
    }

    double f_sol(double x) override {
        return 2.0 - 4.0 * std::cos(x);
    }

    double f_shtrih(const double x, const double y) override {
        return (2.0 - y) * std::tan(x);
    }
};
/* !example 3 */

/* page 330, example5 */
struct Example5 : public AbstractExample {
    double f_sol(double x) override {
        return 2 * std::exp(x) - 2*x + 1;
    }

    double f_shtrih(const double x, const double y) override {
        return y + 2*x - 3;
    }
};
/* !example 3 */


#endif /* FUNCTIONS_H */