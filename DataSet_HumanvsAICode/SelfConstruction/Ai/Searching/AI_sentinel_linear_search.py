def sentinel_linear_search(collection, target):
    """
    Linear search optimised by placing a sentinel value at the end,
    removing the need to check the index boundary on every iteration.
    """
    items = list(collection)  # Copy so we don't modify the original
    length = len(items)
 
    items.append(target)  # Place sentinel – loop will always terminate
 
    index = 0
    while items[index] != target:
        index += 1
 
    items.pop()  # Remove sentinel
 
    if index < length:
        return index   # Target found within the original list
    return -1          # Target was only the sentinel → not found
 
 
if __name__ == "__main__":
    numbers = [4, 7, 2, 9, 1, 5]
    result = sentinel_linear_search(numbers, 9)
    print(f"[Sentinel Linear Search] Target 9 found at index: {result}") # → 3