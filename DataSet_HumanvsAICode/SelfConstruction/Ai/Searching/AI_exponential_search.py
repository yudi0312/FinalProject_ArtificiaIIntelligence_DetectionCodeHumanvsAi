def exponential_search(sorted_collection, target):
    """Find target by exponentially expanding the search range, then binary search."""
    length = len(sorted_collection)
    if length == 0:
        return -1
 
    if sorted_collection[0] == target:
        return 0  # Target is the first element
 
    # Find the range by doubling the bound
    bound = 1
    while bound < length and sorted_collection[bound] <= target:
        bound *= 2
 
    # Binary search within [bound//2, min(bound, length-1)]
    low = bound // 2
    high = min(bound, length - 1)
 
    while low <= high:
        mid = (low + high) // 2
        if sorted_collection[mid] == target:
            return mid
        elif sorted_collection[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
 
    return -1  # Target not found
 
 
if __name__ == "__main__":
    sorted_numbers = [1, 2, 4, 8, 16, 32, 64, 128, 256]
    result = exponential_search(sorted_numbers, 64)
    print(f"[Exponential Search] Target 64 found at index: {result}")    # → 6