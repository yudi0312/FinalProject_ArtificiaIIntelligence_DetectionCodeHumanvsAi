def shell_sort(arr: list) -> list:
    """Sorts a list in ascending order using the Shell Sort algorithm."""
    n = len(arr)
    gap = n // 2

    # Start with a big gap, then reduce the gap
    while gap > 0:
        # Do a gapped insertion sort for this gap size.
        for i in range(gap, n):
            temp = arr[i]
            j = i
            
            # Shift earlier gap-sorted elements up until the correct location for arr[i] is found
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap

            # Put temp (the original arr[i]) in its correct location
            arr[j] = temp
            
        # Reduce the gap size for the next pass
        gap //= 2
        
    return arr

# Example Usage
if __name__ == "__main__":
    sample_data = [12, 34, 54, 2, 3]
    print("Original array:", sample_data)
    sorted_data = shell_sort(sample_data.copy())
    print("Shell Sorted array:", sorted_data)