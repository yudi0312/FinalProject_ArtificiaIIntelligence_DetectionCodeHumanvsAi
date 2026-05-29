import random
 
def hill_climbing(objective_function, initial_solution, step_size=1, max_iterations=1000):
    """
    Maximise objective_function by moving to better neighbours.
 
    Parameters
    ----------
    objective_function : callable  – function to maximise
    initial_solution   : float     – starting x value
    step_size          : float     – how far to try each step
    max_iterations     : int       – safety cap on iterations
    """
    current_solution = initial_solution
    current_score = objective_function(current_solution)
 
    for _ in range(max_iterations):
        # Evaluate left and right neighbours
        left_neighbour = current_solution - step_size
        right_neighbour = current_solution + step_size
 
        left_score = objective_function(left_neighbour)
        right_score = objective_function(right_neighbour)
 
        best_neighbour_score = max(left_score, right_score)
 
        if best_neighbour_score <= current_score:
            break  # No improvement found – at a local maximum
 
        # Move to the better neighbour
        if left_score > right_score:
            current_solution = left_neighbour
        else:
            current_solution = right_neighbour
 
        current_score = best_neighbour_score
 
    return current_solution, current_score
 
 
if __name__ == "__main__":
    # Maximise f(x) = -(x - 3)^2 + 9  →  peak at x = 3, f(3) = 9
    def peak_function(x):
        return -(x - 3) ** 2 + 9
 
    best_x, best_score = hill_climbing(peak_function, initial_solution=0.0, step_size=0.1)
    print(f"[Hill Climbing] Best x={best_x:.2f}, f(x)={best_score:.2f}")  # x≈3, f≈9
