def double_linear_search_recursive(collection, target, left, right):
    """Recursively search from both ends toward the middle."""
    if left > right:
        return -1  # Base case: search space exhausted
 
    if collection[left] == target:
        return left
    if collection[right] == target:
        return right
 
    # Recurse with narrowed bounds
    return double_linear_search_recursive(collection, target, left + 1, right - 1)
 
 
if __name__ == "__main__":
    numbers = [5, 3, 8, 1, 9, 2, 7, 4, 6]
    result = double_linear_search_recursive(numbers, 9, 0, len(numbers) - 1)
    print(f"[Double Linear Search Recursive] Target 9 at index: {result}")  # → 4