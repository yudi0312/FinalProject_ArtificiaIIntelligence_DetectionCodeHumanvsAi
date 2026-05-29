import math
import random
 
def simulated_annealing(
    objective_function,
    initial_solution,
    initial_temperature=1000.0,
    cooling_rate=0.995,
    min_temperature=1e-3,
    max_iterations=10_000,
):
    """
    Minimise objective_function starting from initial_solution.
 
    The algorithm occasionally accepts worse solutions (controlled by
    temperature) to escape local minima, then cools down over time.
    """
    current_solution = initial_solution
    current_cost = objective_function(current_solution)
    best_solution = current_solution
    best_cost = current_cost
    temperature = initial_temperature
 
    for _ in range(max_iterations):
        if temperature < min_temperature:
            break
 
        # Generate a random neighbouring solution (small perturbation)
        neighbour = current_solution + random.uniform(-1, 1)
        neighbour_cost = objective_function(neighbour)
        cost_delta = neighbour_cost - current_cost
 
        # Accept the neighbour if it's better, or with a probability if worse
        if cost_delta < 0 or random.random() < math.exp(-cost_delta / temperature):
            current_solution = neighbour
            current_cost = neighbour_cost
 
            if current_cost < best_cost:
                best_solution = current_solution
                best_cost = current_cost
 
        temperature *= cooling_rate  # Cool down
 
    return best_solution, best_cost
 
 
if __name__ == "__main__":
    # Minimise f(x) = (x - 5)^2  →  minimum at x = 5, f(5) = 0
    def bowl_function(x):
        return (x - 5) ** 2
 
    random.seed(42)
    best_x, best_cost = simulated_annealing(bowl_function, initial_solution=0.0)
    print(f"[Simulated Annealing] Best x={best_x:.4f}, cost={best_cost:.6f}")
