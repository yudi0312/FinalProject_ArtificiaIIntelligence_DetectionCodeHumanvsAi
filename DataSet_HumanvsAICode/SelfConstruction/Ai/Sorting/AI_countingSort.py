def counting_sort(arr: list) -> list:
    """Sorts a list of non-negative integers using the Counting Sort algorithm."""
    if not arr:
        return arr

    # Find the maximum element to determine the size of the count array
    max_val = max(arr)
    count = [0] * (max_val + 1)
    output = [0] * len(arr)

    # Store the count of each element
    for num in arr:
        count[num] += 1

    # Change count[i] so that count[i] contains the actual position of this element in output array
    for i in range(1, len(count)):
        count[i] += count[i - 1]

    # Build the output array
    for num in reversed(arr):
        output[count[num] - 1] = num
        count[num] -= 1

    return output

# Example Usage
if __name__ == "__main__":
    sample_data = [4, 2, 2, 8, 3, 3, 1]
    print("Original array:", sample_data)
    sorted_data = counting_sort(sample_data.copy())
    print("Counting Sorted array:", sorted_data)