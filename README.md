# RHC-Search-
Randomized Hill Climbing with Resampling (RHCR2)

This program implements the Randomized Hill Climbing with Resampling (RHCR2) algorithm to find the local minimum of the objective function frog (x, y). The algorithm iteratively searches for better solutions by generating neighboring solutions around the current solution.

Objective Function The objective function frog (x, y) is defined as: 
Usage Compile the program using a C++ compiler. Run the executable file.

Parameters Starting point (sp): Initial point to start the search.
 Neighborhood size (z): Range for adjusting the neighboring solutions. 
Number of iterations (p): Number of iterations for each run of the algorithm. 
Random seed: Seed for the random number generator.


Interpretation
Solution Quality: The quality of the solutions depends on factors like the starting point, neighborhood size, and the number of iterations.
Algorithm Speed: The speed of the algorithm is influenced by the number of iterations and the complexity of the objective function.
Impact of Parameters:
Starting Point (sp): Different starting points may lead to different local minima.
Neighborhood Size (z): A larger neighborhood size may allow for a more extensive search, while a smaller size may focus the search in a specific area.
Number of Iterations (p): Increasing the number of iterations can improve the likelihood of finding better solutions but also increases computation time.
Complexity: The complexity of the algorithm depends on the size of the search space, the neighborhood size, and the number of iterations.

Resampling Option: The resampling option allows the algorithm to explore different regions of the search space, potentially leading to better solutions.
Parameter Tuning: Experiment with different values for sp, z, and p to find the optimal combination that yields better results.

