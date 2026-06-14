def quick_sort(arr: list) -> list:
    """Sorts a list in ascending order using the Quick Sort algorithm."""
    # Base case: arrays with 0 or 1 element are already sorted
    if len(arr) <= 1:
        return arr
    
    # Choosing the middle element as pivot
    pivot = arr[len(arr) // 2]
    
    # Partition the elements into three categories
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    
    # Recursively sort the sub-arrays and combine them
    return quick_sort(left) + middle + quick_sort(right)

# Example Usage
if __name__ == "__main__":
    sample_data = [10, 7, 8, 9, 1, 5]
    print("Original array:", sample_data)
    sorted_data = quick_sort(sample_data.copy())
    print("Quick Sorted array:", sorted_data)