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

    virtual double get_ab_interval_step() {
        return 0.5;
    }

    virtual double get_x_end() {
        return get_x_begin() + get_ab_interval_step();
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

    double get_x_begin() override {
        // 0
        return 0;
    }

    double get_y0() override {
        // y(0) = 3;
        return 3;
    }

    double f_sol(double x) override {
        return 2.0 * std::exp(x) - 2.0*x + 1;
    }

    double f_shtrih(const double x, const double y) override {
        return y + 2.0*x - 3;
    }
};
/* !example 5 */

/* page 332, example24 */
struct Example24 : public AbstractExample {

    double get_x_begin() override {
        // 1
        return 1;
    }

    double get_y0() override {
        // y(1) = 0;
        return 0;
    }

    double f_sol(double x) override {
        return (x-1) /(x+1);
    }

    double f_shtrih(const double x, const double y) override {
        return (1 - std::pow(y, 2.0)) / (2.0*x);
    }
};
/* !example 24 */


/* https://math.okstate.edu/people/yqwang/teaching/math4513_fall11/Notes/rungekutta.pdf */
struct InternetExample : public AbstractExample {

    double get_x_begin() override {
        return 0;
    }

    double get_y0() override {
        // y(0) = 0.5;
        return 0.5;
    }

    double f_sol(double x) override {
        return std::pow(x, 2) + 2*x + 1 - 1/2.0 * std::exp(x);
    }

    double f_shtrih(const double x, const double y) override {
        return y - std::pow(x, 2) +1;
    }
};
/* !example 24 */


#endif /* FUNCTIONS_H */