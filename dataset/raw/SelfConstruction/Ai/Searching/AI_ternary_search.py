def ternary_search(sorted_collection, target, low=None, high=None):
    """Divide the sorted list into thirds recursively to find the target."""
    if low is None:
        low = 0
    if high is None:
        high = len(sorted_collection) - 1
 
    if low > high:
        return -1  # Base case: target not found
 
    # Divide into three equal parts
    mid1 = low + (high - low) // 3
    mid2 = high - (high - low) // 3
 
    if sorted_collection[mid1] == target:
        return mid1
    if sorted_collection[mid2] == target:
        return mid2
 
    if target < sorted_collection[mid1]:
        return ternary_search(sorted_collection, target, low, mid1 - 1)
    elif target > sorted_collection[mid2]:
        return ternary_search(sorted_collection, target, mid2 + 1, high)
    else:
        return ternary_search(sorted_collection, target, mid1 + 1, mid2 - 1)
 
 
if __name__ == "__main__":
    sorted_numbers = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19]
    result = ternary_search(sorted_numbers, 13)
    print(f"[Ternary Search] Target 13 found at index: {result}")        # → 6
