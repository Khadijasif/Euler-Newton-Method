#include <iostream>
#include <cmath>

using namespace std;

// Function representing the differential equation dy/dx = f(x, y)
double f(double x, double y) {
    return y - x*x + 1;
}

// Function to perform the Euler step
double euler_step(double x, double y, double h) {
    return y + h * f(x, y);
}

// Function to perform the Newton-Raphson iteration for better accuracy
double newton_raphson(double x, double y, double h, int max_iter = 10, double tol = 1e-6) {
    double y_new = euler_step(x, y, h);
    for (int i = 0; i < max_iter; ++i) {
        double fx = y_new - y - h * f(x + h, y_new);
        double f_prime_x = 1 - h * f(x + h, y_new);
        double delta_y = fx / f_prime_x;
        y_new -= delta_y;
        if (abs(delta_y) < tol) break;
    }
    return y_new;
}

int main() {
    double x0 = 0.0; // Initial x
    double y0 = 0.5; // Initial y
    double x_end = 2.0; // End of interval
    double h = 0.1; // Step size

    cout << "x\ty" << endl;

    for (double x = x0; x <= x_end; x += h) {
        cout << x << "\t" << y0 << endl;
        y0 = newton_raphson(x, y0, h);
    }

    return 0;
}
