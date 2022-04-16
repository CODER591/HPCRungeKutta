#ifndef FUNCTIONS_H
#define FUNCTIONS_H


#include <cmath>


struct AbstractExample {
    virtual double f_sol(double x) = 0;
    virtual double f_shtrih(const double x, const double y) = 0;
    virtual ~AbstractExample() {}
};

/* page 330, example3 */
struct Example3 : public AbstractExample {
    double f_sol(double x) override {
        return 2.0 - 4.0 * std::cos(x);
    }

    double f_shtrih(const double x, const double y) override {
        return (2.0 - y) * std::tan(x);
    }
};
/* !example 3 */


#endif /* FUNCTIONS_H */