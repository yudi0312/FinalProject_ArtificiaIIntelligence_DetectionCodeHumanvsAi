def counting_sort_for_radix(arr: list, exponent: int):
    """A helper counting sort function to sort elements based on significant digit."""
    n = len(arr)
    output = [0] * n
    count = [0] * 10

    # Store occurrences in count array
    for i in range(n):
        index = arr[i] // exponent
        count[index % 10] += 1

    # Change count[i] so that it contains the actual position of this digit in output array
    for i in range(1, 10):
        count[i] += count[i - 1]

    # Build the output array by tracking digits from back to front
    for i in range(n - 1, -1, -1):
        index = arr[i] // exponent
        output[count[index % 10] - 1] = arr[i]
        count[index % 10] -= 1

    # Copy the sorted output array back to the original array
    for i in range(n):
        arr[i] = output[i]

def radix_sort(arr: list) -> list:
    """Sorts a list of integers in ascending order using Radix Sort."""
    if not arr:
        return arr

    # Find the maximum number to know the number of digits
    max_val = max(arr)

    # Do counting sort for every digit. Instead of passing digit number, 
    # exponent (10^i) is passed where i is the current digit number
    exponent = 1
    while max_val // exponent > 0:
        counting_sort_for_radix(arr, exponent)
        exponent *= 10
        
    return arr

# Example Usage
if __name__ == "__main__":
    sample_data = [170, 45, 75, 90, 802, 24, 2, 66]
    print("Original array:", sample_data)
    sorted_data = radix_sort(sample_data.copy())
    print("Radix Sorted array:", sorted_data)