def bitonic_merge(arr: list, low: int, cnt: int, direction: int):
    """Recursively merges two bitonic sequences in a specified direction."""
    if cnt > 1:
        k = cnt // 2
        for i in range(low, low + k):
            if (direction == 1 and arr[i] > arr[i + k]) or (direction == 0 and arr[i] < arr[i + k]):
                arr[i], arr[i + k] = arr[i + k], arr[i]
        bitonic_merge(arr, low, k, direction)
        bitonic_merge(arr, low + k, k, direction)

def bitonic_sort_recursive(arr: list, low: int, cnt: int, direction: int):
    """Produces a bitonic sequence by sorting its two halves in opposite directions."""
    if cnt > 1:
        k = cnt // 2
        # Sort in ascending order (direction = 1)
        bitonic_sort_recursive(arr, low, k, 1)
        # Sort in descending order (direction = 0)
        bitonic_sort_recursive(arr, low + k, k, 0)
        # Merge the entire sequence
        bitonic_merge(arr, low, cnt, direction)

def bitonic_sort(arr: list) -> list:
    """Sorts lists whose total length is a strict power of 2 using Bitonic Sort."""
    bitonic_sort_recursive(arr, 0, len(arr), 1)
    return arr

# Example Usage (Length must be a power of 2)
if __name__ == "__main__":
    sample_data = [3, 7, 4, 8, 6, 2, 1, 5]
    print("Original array:", sample_data)
    sorted_data = bitonic_sort(sample_data.copy())
    print("Bitonic Sorted array:", sorted_data)