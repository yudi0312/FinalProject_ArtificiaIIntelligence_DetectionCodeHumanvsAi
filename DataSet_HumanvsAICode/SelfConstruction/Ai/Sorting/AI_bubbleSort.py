def bubble_sort(arr: list) -> list:
    """Sorts a list in ascending order using the Bubble Sort algorithm."""
    n = len(arr)
    # Traverse through all array elements
    for i in range(n):
        # Track if any swap happens in this pass
        swapped = False
        
        # Last i elements are already in place
        for j in range(0, n - i - 1):
            # Traverse the array from 0 to n-i-1
            # Swap if the element found is greater than the next element
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
                
        # If no two elements were swapped by inner loop, then break
        if not swapped:
            break
            
    return arr

# Example Usage
if __name__ == "__main__":
    sample_data = [64, 34, 25, 12, 22, 11, 90]
    print("Original array:", sample_data)
    sorted_data = bubble_sort(sample_data.copy())
    print("Bubble Sorted array:", sorted_data)