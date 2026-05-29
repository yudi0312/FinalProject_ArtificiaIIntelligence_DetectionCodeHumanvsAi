def interpolation_search(sorted_collection, target):
    """Search a sorted, uniformly distributed list via position interpolation."""
    low = 0
    high = len(sorted_collection) - 1
 
    while low <= high and sorted_collection[low] <= target <= sorted_collection[high]:
        # Avoid division by zero when all remaining elements are equal
        if sorted_collection[low] == sorted_collection[high]:
            if sorted_collection[low] == target:
                return low
            return -1
 
        # Interpolate the probable position of the target
        position = low + (
            (target - sorted_collection[low])
            * (high - low)
            // (sorted_collection[high] - sorted_collection[low])
        )
 
        if sorted_collection[position] == target:
            return position
        elif sorted_collection[position] < target:
            low = position + 1   # Target is to the right
        else:
            high = position - 1  # Target is to the left
 
    return -1  # Target not found
 
 
if __name__ == "__main__":
    uniform_numbers = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
    result = interpolation_search(uniform_numbers, 70)
    print(f"[Interpolation Search] Target 70 found at index: {result}")  # → 6
