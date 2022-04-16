#ifndef EXAMPLES_SYSTEMS_H
#define EXAMPLES_SYSTEMS_H


#include <cmath>


struct AbstractSystemExample {
    virtual double get_x_begin() = 0;
    virtual double get_x_end() = 0;
    //y(x_0) = y_0;
    virtual double get_y0() = 0;
    virtual double get_z0() = 0;

    virtual double f_sol(double x) = 0;
    virtual double g_sol(double x) = 0;

    virtual double f_shtrih(const double x, const double y, const double z) = 0;
    virtual double g_shtrih(const double x, const double y, const double z) = 0;

    virtual ~AbstractSystemExample() {}

    virtual double get_ab_interval_step() {
        return 0.01;
    }
};

struct SystemExample1 : public AbstractSystemExample {
    double get_x_begin() override {
        return 0;
    }
    
    double get_x_end() override {
        return 0.5;
    }

    double get_y0() override {
        return 0;
    }

    double get_z0() override {
        return 4;
    }

    double f_shtrih(const double x, const double y, const double z) {
        return 2*y + z;
    }

    double g_shtrih(const double x, const double y, const double z) {
        return 3*y+ 4*z;
    }


    double f_sol(double x) {
        return -1 * std::exp(x) + std::exp(5*x);
    }

    double g_sol(double x) {
        return std::exp(x) + 3*std::exp(5*x);
    }

};

#endif /* EXAMPLES_SYSTEMS_H */