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

/*
  Name of the article:
  "An Approximation to the Solution of the Brusselator System by Adomian Decomposition Method and Comparing the Results with Runge-Kutta Method"

  To apply their notations to those which are more familiar to me
  I have performed following text substitutions:
  t -> x
  x -> y
  y -> z
  (e.g)  was: f(t,x,y) --become--> f(x,y,z)
*/
struct BrusselatorSystem : public AbstractSystemExample {
    double get_x_begin() override {
        return 0;
    }
    
    double get_x_end() override {
        return 0.7;
    }

    double get_y0() override {
        return 1.0;
    }

    double get_z0() override {
        return 1.0;
    }

    double f_shtrih(const double x, const double y, const double z) {
        return -2.0*y + std::pow(y,2)*z;
    }

    double g_shtrih(const double x, const double y, const double z) {
        return y - std::pow(y,2)*z;
    }

    double f_sol(double x) {
        //NOTIMPLEMENTED
        return -12;
    }

    double g_sol(double x) {
        //NOTIMPLEMENTED
        return -12;
    }
    
   double get_ab_interval_step() override {
        return 0.1;
    }
};

#endif /* EXAMPLES_SYSTEMS_H */