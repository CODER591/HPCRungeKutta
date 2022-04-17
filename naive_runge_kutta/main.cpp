
#include "tests/tests.h"

#include <chrono>
#include <iostream>
#include <functional>
using namespace std::chrono;


void run_and_measure_time(std::function<void()> func) {
    auto start = high_resolution_clock::now();

    func();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time taken by function: "
         << duration.count() << " microseconds" << std::endl;
}

int main () {

    run_and_measure_time(&mock_example3);

    //mock_system_example_brusselator();

    return 0;
}