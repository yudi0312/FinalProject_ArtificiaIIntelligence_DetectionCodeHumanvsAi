def gnome_sort(arr: list) -> list:
    """Sorts a list using the Gnome Sort algorithm."""
    n = len(arr)
    index = 0

    while index < n:
        if index == 0:
            index += 1
        # If the current element is greater or equal to the previous, step forward
        if arr[index] >= arr[index - 1]:
            index += 1
        else:
            # If smaller, swap them and step backward to verify sorting
            arr[index], arr[index - 1] = arr[index - 1], arr[index]
            index -= 1
            
    return arr

# Example Usage
if __name__ == "__main__":
    sample_data = [34, 2, 10, -9, 0, 11, 5]
    print("Original array:", sample_data)
    sorted_data = gnome_sort(sample_data.copy())
    print("Gnome Sorted array:", sorted_data)