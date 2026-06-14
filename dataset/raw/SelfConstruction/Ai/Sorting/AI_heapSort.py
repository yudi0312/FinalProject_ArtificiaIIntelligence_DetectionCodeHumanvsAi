def heapify(arr: list, n: int, i: int):
    """Helper function to maintain the max-heap property."""
    largest = i       # Initialize largest as root
    left = 2 * i + 1   # Left child index
    right = 2 * i + 2  # Right child index

    # See if left child of root exists and is greater than root
    if left < n and arr[left] > arr[largest]:
        largest = left

    # See if right child of root exists and is greater than the largest so far
    if right < n and arr[right] > arr[largest]:
        largest = right

    # Change root, if needed
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]  # Swap

        # Heapify the root recursively
        heapify(arr, n, largest)

def heap_sort(arr: list) -> list:
    """Sorts a list in ascending order using the Heap Sort algorithm."""
    n = len(arr)

    # Build a max-heap (rearrange array)
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    # One by one extract elements from the heap
    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]  # Swap current root to the end
        heapify(arr, i, 0)               # Call max heapify on the reduced heap
        
    return arr

# Example Usage
if __name__ == "__main__":
    sample_data = [12, 11, 13, 5, 6, 7]
    print("Original array:", sample_data)
    sorted_data = heap_sort(sample_data.copy())
    print("Heap Sorted array:", sorted_data)