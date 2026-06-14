def double_linear_search(collection, target):
    """Search from both ends of the list towards the middle simultaneously."""
    left = 0
    right = len(collection) - 1
 
    while left <= right:
        if collection[left] == target:
            return left   # Found from the left pointer
        if collection[right] == target:
            return right  # Found from the right pointer
        left += 1
        right -= 1
 
    return -1  # Target not found
 
 
if __name__ == "__main__":
    numbers = [5, 3, 8, 1, 9, 2, 7, 4, 6]
    result = double_linear_search(numbers, 7)
    print(f"[Double Linear Search] Target 7 found at index: {result}")   # → 6