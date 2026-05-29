def odd_even_sort(arr: list) -> list:
    """Sorts a list by alternating between odd-even and even-odd index sorting."""
    n = len(arr)
    is_sorted = False

    while not is_sorted:
        is_sorted = True

        # Perform Bubble sort on odd indexed items
        for i in range(1, n - 1, 2):
            if arr[i] > arr[i + 1]:
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
                is_sorted = False

        # Perform Bubble sort on even indexed items
        for i in range(0, n - 1, 2):
            if arr[i] > arr[i + 1]:
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
                is_sorted = False
                
    return arr

# Example Usage
if __name__ == "__main__":
    sample_data = [34, 2, 10, -9, 0, 11, 5, 99]
    print("Original array:", sample_data)
    sorted_data = odd_even_sort(sample_data.copy())
    print("Odd-Even Sorted array:", sorted_data)