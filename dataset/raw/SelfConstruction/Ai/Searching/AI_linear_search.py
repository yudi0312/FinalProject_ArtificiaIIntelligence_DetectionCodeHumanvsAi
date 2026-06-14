def linear_search(collection, target):
    """Search for target by scanning every element left to right."""
    for index, element in enumerate(collection):
        if element == target:
            return index  # Return the index where target was found
    return -1             # Target not found
 
 
if __name__ == "__main__":
    numbers = [4, 2, 7, 1, 9, 3]
    result = linear_search(numbers, 9)
    print(f"[Linear Search] Target 9 found at index: {result}")   # → 4