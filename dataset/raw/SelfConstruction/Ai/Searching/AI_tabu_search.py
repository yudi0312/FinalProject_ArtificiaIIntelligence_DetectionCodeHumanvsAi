def tabu_search(
    objective_function,
    initial_solution,
    neighbourhood_function,
    tabu_list_size=10,
    max_iterations=100,
):
    """
    Minimise objective_function using a tabu list to avoid revisiting solutions.
 
    Parameters
    ----------
    objective_function     : callable – function to minimise
    initial_solution       : any      – starting solution
    neighbourhood_function : callable – returns a list of neighbours
    tabu_list_size         : int      – how many past solutions to forbid
    max_iterations         : int      – number of search iterations
    """
    current_solution = initial_solution
    best_solution = current_solution
    best_cost = objective_function(current_solution)
 
    tabu_list = []  # Recently visited solutions (forbidden moves)
 
    for _ in range(max_iterations):
        neighbours = neighbourhood_function(current_solution)
 
        # Find the best non-tabu neighbour (aspiration: allow if it's the global best)
        best_neighbour = None
        best_neighbour_cost = float("inf")
 
        for neighbour in neighbours:
            neighbour_cost = objective_function(neighbour)
            is_tabu = neighbour in tabu_list
            is_aspiration = neighbour_cost < best_cost  # Override tabu if best ever
 
            if not is_tabu or is_aspiration:
                if neighbour_cost < best_neighbour_cost:
                    best_neighbour = neighbour
                    best_neighbour_cost = neighbour_cost
 
        if best_neighbour is None:
            break  # All neighbours are tabu and none beats the global best
 
        # Move to the best allowed neighbour
        current_solution = best_neighbour
 
        # Update the global best
        if best_neighbour_cost < best_cost:
            best_solution = best_neighbour
            best_cost = best_neighbour_cost
 
        # Update tabu list (FIFO – remove oldest if full)
        tabu_list.append(current_solution)
        if len(tabu_list) > tabu_list_size:
            tabu_list.pop(0)
 
    return best_solution, best_cost
 
 
if __name__ == "__main__":
    # Minimise f(x) = x^2  →  minimum at x = 0
    def quadratic(x):
        return x ** 2
 
    def integer_neighbourhood(x):
        """Return ±1 and ±2 integer neighbours."""
        return [x - 2, x - 1, x + 1, x + 2]
 
    best_x, best_cost = tabu_search(
        quadratic,
        initial_solution=10,
        neighbourhood_function=integer_neighbourhood,
        tabu_list_size=5,
        max_iterations=50,
    )
    print(f"[Tabu Search] Best x={best_x}, cost={best_cost}")             # x=0, cost=0
 
