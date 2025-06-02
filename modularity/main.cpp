// USAGE FILE

#include <iostream>
#include <cmath>
#include "Vector.h" // Get Vector's interface

double sqrt_sum(Vector& v){
    double sum = 0;
    for (int i = 0; i < v.size(); ++i) {
        sum += sqrt(v[i]);
    }
    return sum;
}

int main() {
    // Define `Vector` with 6 elements
    Vector v(6);

    // Initialize elements with values
    std::cout << "Enter " << v.size() << " numbers to calculate sum of there square roots:\n";
    for (int i = 0; i != v.size(); ++i) {
        std::cin >> v[i];
    }

    double sqrtSum = sqrt_sum(v);
    std::cout << "Square root summation of the elements of the Vector is:  " << sqrtSum;

}
