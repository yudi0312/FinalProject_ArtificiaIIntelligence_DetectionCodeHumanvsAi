def selection_sort(arr: list) -> list:
    """Sorts a list in ascending order using the Selection Sort algorithm."""
    n = len(arr)
    
    # Move the boundary of the unsorted subarray one by one
    for i in range(n):
        # Find the minimum element in remaining unsorted array
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
                
        # Swap the found minimum element with the first element
        arr[i], arr[min_index] = arr[min_index], arr[i]
        
    return arr

# Example Usage
if __name__ == "__main__":
    sample_data = [64, 25, 12, 22, 11]
    print("Original array:", sample_data)
    sorted_data = selection_sort(sample_data.copy())
    print("Selection Sorted array:", sorted_data)