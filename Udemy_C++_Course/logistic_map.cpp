#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// Logistic map function
double logisticMap(double x, double r) {
    return r * x * (1 - x);
}

int main() {
    // Parameters
    double r_min = 1.0;
    double r_max = 4.0;
    int num_points = 10000;
    int num_iterations = 1000;

    // Open a pipe to Gnuplot
    FILE *gp = popen("gnuplot -persist", "w");
    if (!gp) {
        cerr << "Error: Gnuplot not found." << endl;
        return 1;
    }

    // Generate and plot data
    vector<double> x_values;
    vector<double> y_values;

    for (int r_step = 0; r_step < num_points; r_step++) {
        double r = r_min + (r_max - r_min) * r_step / (num_points - 1);
        double x = 0.5; // Initial value

        for (int i = 0; i < num_iterations; i++) {
            x = logisticMap(x, r);
            if (i >= num_iterations / 2) {
                x_values.push_back(r);
                y_values.push_back(x);
            }
        }
    }

    // Plot the data using Gnuplot
    fprintf(gp, "set xlabel 'r'\n");
    fprintf(gp, "set ylabel 'x'\n");
    fprintf(gp, "plot '-' with dots title 'Logistic Map'\n");

    for (size_t i = 0; i < x_values.size(); i++) {
        fprintf(gp, "%lf %lf\n", x_values[i], y_values[i]);
    }

    fprintf(gp, "e\n");
    fflush(gp);

    // Close the Gnuplot pipe
    pclose(gp);

    return 0;
}
