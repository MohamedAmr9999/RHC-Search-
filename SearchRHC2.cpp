#include <iostream>
#include <random>
#include <utility>

using namespace std;

// Objective function fFrog
double fFrog(double x, double y) {
    return x * cos(sqrt(abs(x + y + 1))) * sin(sqrt(abs(y - x + 1))) +
           (1 + y) * sin(sqrt(abs(x + y + 1))) * cos(sqrt(abs(y - x + 1)));
}

// Random Hill Climbing (RHC) function
pair<double, double> RHC(pair<double, double> sp, double z, int p, int seed) {
    default_random_engine generator(seed);
    uniform_real_distribution<double> distribution_x(max(-512.0, sp.first - z), min(512.0, sp.first + z));
    uniform_real_distribution<double> distribution_y(max(-512.0, sp.second - z), min(512.0, sp.second + z));

    pair<double, double> best_solution = sp;
    double best_value = fFrog(sp.first, sp.second);

    for (int i = 0; i < p; ++i) {
        double x_new, y_new;
        do {
            x_new = distribution_x(generator);
            y_new = distribution_y(generator);
        } while (x_new < -512.0 || x_new > 512.0 || y_new < -512.0 || y_new > 512.0); // Check if out of range

        double value_new = fFrog(x_new, y_new);

        if (value_new < best_value) {
            best_solution = make_pair(x_new, y_new);
            best_value = value_new;
        }
    }

    return best_solution;
}


// Random Hill Climbing with Resampling (RHCR) function
void RHCR2(pair<double, double> sp, double z, int p, int seed, 
           pair<double, double>& sol1, double& f_sol1, 
           pair<double, double>& sol2, double& f_sol2, 
           pair<double, double>& sol3, double& f_sol3, 
           int& total_solutions_generated) {
    sol1 = RHC(sp, z, p, seed);
    sol2 = RHC(sol1, z / 20, p, seed);
    sol3 = RHC(sol2, z / 400, p, seed);

    f_sol1 = fFrog(sol1.first, sol1.second);
    f_sol2 = fFrog(sol2.first, sol2.second);
    f_sol3 = fFrog(sol3.first, sol3.second);
    total_solutions_generated = p * 3;
}

int main() {
    // Example parameters
    double sp_x = -435, sp_y = -120;
    double z = 80;
    int p = 20000;
    int seed = 220;
    // Run RHCR2
    pair<double, double> sol1, sol2, sol3;
    double f_sol1, f_sol2, f_sol3;
    int total_solutions_generated;

    RHCR2(make_pair(sp_x, sp_y), z, p, seed, sol1, f_sol1, sol2, f_sol2, sol3, f_sol3, total_solutions_generated);
    // Output results
    cout << "sol1: (" << sol1.first << ", " << sol1.second << "), f(sol1): " << f_sol1 << endl;
    cout << "sol2: (" << sol2.first << ", " << sol2.second << "), f(sol2): " << f_sol2 << endl;
    cout << "sol3: (" << sol3.first << ", " << sol3.second << "), f(sol3): " << f_sol3 << endl;
    cout << "Total number of solutions generated: " << total_solutions_generated << endl;

    return 0;
}
