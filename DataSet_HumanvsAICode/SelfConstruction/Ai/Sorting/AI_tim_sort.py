MIN_RUN = 32

def insertion_sort_timsort(arr: list, left: int, right: int):
    """A modified localized insertion sort for Timsort blocks."""
    for i in range(left + 1, right + 1):
        key = arr[i]
        j = i - 1
        while j >= left and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def merge_timsort(arr: list, l: int, m: int, r: int):
    """Merges two contiguous sorted segments."""
    len1, len2 = m - l + 1, r - m
    left, right = [], []
    for i in range(0, len1):
        left.append(arr[l + i])
    for i in range(0, len2):
        right.append(arr[m + 1 + i])

    i, j, k = 0, j, l

    while i < len1 and j < len2:
        if left[i] <= right[j]:
            arr[k] = left[i]
            i += 1
        else:
            arr[k] = right[j]
            j += 1
        k += 1

    while i < len1:
        arr[k] = left[i]
        k += 1
        i += 1

    while j < len2:
        arr[k] = right[j]
        k += 1
        j += 1

def tim_sort(arr: list) -> list:
    """Sorts a list using a clean, native implementation of Tim Sort."""
    n = len(arr)

    # Sort individual subarrays of size MIN_RUN
    for i in range(0, n, MIN_RUN):
        insertion_sort_timsort(arr, i, min((i + MIN_RUN - 1), (n - 1)))

    # Start merging from size MIN_RUN. It will double on every iteration.
    size = MIN_RUN
    while size < n:
        for left in range(0, n, 2 * size):
            mid = min(n - 1, left + size - 1)
            right = min((left + 2 * size - 1), (n - 1))

            if mid < right:
                merge_timsort(arr, left, mid, right)
        size = 2 * size
        
    return arr

# Example Usage
if __name__ == "__main__":
    sample_data = [45, -2, 0, 12, 88, 3, 7, 19, 101, 5, 2, 9, 11]
    print("Original array:", sample_data)
    sorted_data = tim_sort(sample_data.copy())
    print("Tim Sorted array:", sorted_data)