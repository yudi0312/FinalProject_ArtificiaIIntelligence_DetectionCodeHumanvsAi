def simple_binary_search(sorted_collection, target, low=0, high=None):
    """Recursively halve the search space to find target in a sorted list."""
    if high is None:
        high = len(sorted_collection) - 1
 
    if low > high:
        return -1  # Base case: target not found
 
    mid = (low + high) // 2
 
    if sorted_collection[mid] == target:
        return mid
    elif sorted_collection[mid] < target:
        return simple_binary_search(sorted_collection, target, mid + 1, high)
    else:
        return simple_binary_search(sorted_collection, target, low, mid - 1)
 
 
if __name__ == "__main__":
    sorted_numbers = [2, 4, 6, 8, 10, 12, 14]
    result = simple_binary_search(sorted_numbers, 10)
    print(f"[Simple Binary Search] Target 10 found at index: {result}")  # → 4