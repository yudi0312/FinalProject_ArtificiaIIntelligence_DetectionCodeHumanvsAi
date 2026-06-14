def flip(arr: list, i: int):
    """Reverses the array from index 0 to i."""
    start = 0
    while start < i:
        arr[start], arr[i] = arr[i], arr[start]
        start += 1
        i -= 1

def find_max_index(arr: list, n: int) -> int:
    """Returns the index of the maximum element in arr[0..n-1]."""
    max_idx = 0
    for i in range(0, n):
        if arr[i] > arr[max_idx]:
            max_idx = i
    return max_idx

def pancake_sort(arr: list) -> list:
    """Sorts a list by continuously flipping structural chunks."""
    curr_size = len(arr)
    while curr_size > 1:
        # Find the index of the maximum element in arr[0..curr_size-1]
        max_idx = find_max_index(arr, curr_size)

        # Move the maximum element to end of current array if it's not already there
        if max_idx != curr_size - 1:
            # To move to the end, first flip it to the front
            if max_idx != 0:
                flip(arr, max_idx)
            
            # Now move the maximum number to end by reversing current array
            flip(arr, curr_size - 1)
            
        curr_size -= 1
    return arr

# Example Usage
if __name__ == "__main__":
    sample_data = [23, 10, 20, 11, 12, 6, 7]
    print("Original array:", sample_data)
    sorted_data = pancake_sort(sample_data.copy())
    print("Pancake Sorted array:", sorted_data)