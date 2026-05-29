def merge_sort(arr: list) -> list:
    """Sorts a list in ascending order using the Merge Sort algorithm."""
    if len(arr) <= 1:
        return arr

    # Find the middle point to divide the array into two halves
    mid = len(arr) // 2
    left_half = arr[:mid]
    right_half = arr[mid:]

    # Recursively sort both halves
    merge_sort(left_half)
    merge_sort(right_half)

    # Iterators for traversing the two halves and the main array
    i = j = k = 0

    # Copy data to temporary arrays left_half and right_half
    while i < len(left_half) and j < len(right_half):
        if left_half[i] <= right_half[j]:
            arr[k] = left_half[i]
            i += 1
        else:
            arr[k] = right_half[j]
            j += 1
        k += 1

    # Checking if any element was left in left_half
    while i < len(left_half):
        arr[k] = left_half[i]
        i += 1
        k += 1

    # Checking if any element was left in right_half
    while j < len(right_half):
        arr[k] = right_half[j]
        j += 1
        k += 1

    return arr

# Example Usage
if __name__ == "__main__":
    sample_data = [38, 27, 43, 3, 9, 82, 10]
    print("Original array:", sample_data)
    sorted_data = merge_sort(sample_data.copy())
    print("Merge Sorted array:", sorted_data)