def fibonacci_search(sorted_collection, target):
    """Divide a sorted list using Fibonacci numbers to locate the target."""
    length = len(sorted_collection)
 
    # Generate Fibonacci numbers up to length
    fib_m2 = 0  # (m-2)th Fibonacci number
    fib_m1 = 1  # (m-1)th Fibonacci number
    fib_m = fib_m1 + fib_m2  # mth Fibonacci number
 
    while fib_m < length:
        fib_m2 = fib_m1
        fib_m1 = fib_m
        fib_m = fib_m1 + fib_m2
 
    offset = -1  # Tracks the eliminated range from the front
 
    while fib_m > 1:
        # Check validity of fib_m2 position
        index = min(offset + fib_m2, length - 1)
 
        if sorted_collection[index] < target:
            # Move Fibonacci numbers two steps down; shift offset
            fib_m = fib_m1
            fib_m1 = fib_m2
            fib_m2 = fib_m - fib_m1
            offset = index
        elif sorted_collection[index] > target:
            # Move Fibonacci numbers one step down
            fib_m = fib_m2
            fib_m1 = fib_m1 - fib_m2
            fib_m2 = fib_m - fib_m1
        else:
            return index  # Target found
 
    # Compare last element
    if fib_m1 and offset + 1 < length and sorted_collection[offset + 1] == target:
        return offset + 1
 
    return -1  # Target not found
 
 
if __name__ == "__main__":
    sorted_numbers = [10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100]
    result = fibonacci_search(sorted_numbers, 85)
    print(f"[Fibonacci Search] Target 85 found at index: {result}")      # → 8