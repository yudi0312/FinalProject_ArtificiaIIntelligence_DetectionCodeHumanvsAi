def cocktail_sort(arr: list) -> list:
    """Sorts a list using the bidirectional Cocktail Shaker Sort algorithm."""
    n = len(arr)
    swapped = True
    start = 0
    end = n - 1

    while swapped:
        # Reset the flag on entering the loop, as it might be true from a previous iteration
        swapped = False

        # Forward pass: behaves exactly like bubble sort
        for i in range(start, end):
            if arr[i] > arr[i + 1]:
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
                swapped = True

        # If nothing moved, the list is completely sorted
        if not swapped:
            break

        # Otherwise, reset the flag for the backward pass
        swapped = False

        # Move the end point back by one since that item is now placed correctly
        end = end - 1

        # Backward pass: bubble sort from right to left
        for i in range(end - 1, start - 1, -1):
            if arr[i] > arr[i + 1]:
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
                swapped = True

        # Move the starting point forward by one for the next run
        start = start + 1
        
    return arr

# Example Usage
if __name__ == "__main__":
    sample_data = [5, 1, 4, 2, 8, 0, 2]
    print("Original array:", sample_data)
    sorted_data = cocktail_sort(sample_data.copy())
    print("Cocktail Sorted array:", sorted_data)