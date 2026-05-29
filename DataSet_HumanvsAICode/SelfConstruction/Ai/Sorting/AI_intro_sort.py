import math

def insertion_sort_intro(arr: list, start: int, end: int):
    """Localized helper insertion sort for small partitions."""
    for i in range(start + 1, end + 1):
        key = arr[i]
        j = i - 1
        while j >= start and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def heapify_intro(arr: list, n: int, i: int, start: int):
    """Localized heapify routine for tracking sub-arrays."""
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2

    if left < n and arr[start + left] > arr[start + largest]:
        largest = left
    if right < n and arr[start + right] > arr[start + largest]:
        largest = right

    if largest != i:
        arr[start + i], arr[start + largest] = arr[start + largest], arr[start + i]
        heapify_intro(arr, n, largest, start)

def heap_sort_intro(arr: list, start: int, end: int):
    """Localized heap sort if recursion depth bound limit is violated."""
    n = end - start + 1
    for i in range(n // 2 - 1, -1, -1):
        heapify_intro(arr, n, i, start)
    for i in range(n - 1, 0, -1):
        arr[start + i], arr[start] = arr[start], arr[start + i]
        heapify_intro(arr, i, 0, start)

def partition_intro(arr: list, start: int, end: int) -> int:
    """Standard partitioning scheme using right element as pivot."""
    pivot = arr[end]
    i = start - 1
    for j in range(start, end):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[end] = arr[end], arr[i + 1]
    return i + 1

def intro_sort_util(arr: list, start: int, end: int, depth_limit: int):
    """Utility framework managing fallback heuristics."""
    size = end - start + 1
    
    # If partition size is small, fallback to insertion sort
    if size < 16:
        insertion_sort_intro(arr, start, end)
        return

    # If max depth bound is exceeded, fallback to safe heap sort
    if depth_limit == 0:
        heap_sort_intro(arr, start, end)
        return

    # Otherwise operate like standard quicksort
    pivot_idx = partition_intro(arr, start, end)
    intro_sort_util(arr, start, pivot_idx - 1, depth_limit - 1)
    intro_sort_util(arr, pivot_idx + 1, end, depth_limit - 1)

def intro_sort(arr: list) -> list:
    """Sorts a list using the robust Intro Sort hybrid structure."""
    if not arr:
        return arr
    max_depth = 2 * math.floor(math.log2(len(arr)))
    intro_sort_util(arr, 0, len(arr) - 1, max_depth)
    return arr

# Example Usage
if __name__ == "__main__":
    sample_data = [2, 10, 24, -3, 0, 84, 12, 11, 7, 5, 1, 19]
    print("Original array:", sample_data)
    sorted_data = intro_sort(sample_data.copy())
    print("Intro Sorted array:", sorted_data)