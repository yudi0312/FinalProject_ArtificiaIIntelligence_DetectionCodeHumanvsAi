def binary_search(sorted_collection, target):
    """Search a sorted list by repeatedly halving the search space."""
    low = 0
    high = len(sorted_collection) - 1
 
    while low <= high:
        mid = (low + high) // 2
        mid_value = sorted_collection[mid]
 
        if mid_value == target:
            return mid           # Target found at mid
        elif mid_value < target:
            low = mid + 1        # Target is in the right half
        else:
            high = mid - 1       # Target is in the left half
 
    return -1  # Target not found
 
 
if __name__ == "__main__":
    sorted_numbers = [1, 3, 5, 7, 9, 11, 13]
    result = binary_search(sorted_numbers, 7)
    print(f"[Binary Search] Target 7 found at index: {result}")    # → 3