def comb_sort(arr: list) -> list:
    """Sorts a list using the Comb Sort algorithm by eliminating small values near the end."""
    n = len(arr)
    gap = n
    shrink_factor = 1.3
    swapped = True

    # Keep running while gap is more than 1 or a swap happened
    while gap > 1 or swapped:
        # Update the gap value
        gap = int(gap / shrink_factor)
        if gap < 1:
            gap = 1

        # Initialize swapped as False to check if a swap happens in this loop
        swapped = False

        # Compare all elements with current gap
        for i in range(0, n - gap):
            if arr[i] > arr[i + gap]:
                arr[i], arr[i + gap] = arr[i + gap], arr[i]
                swapped = True
                
    return arr

# Example Usage
if __name__ == "__main__":
    sample_data = [8, 4, 1, 56, 3, -44, 23, -6, 28, 0]
    print("Original array:", sample_data)
    sorted_data = comb_sort(sample_data.copy())
    print("Comb Sorted array:", sorted_data)