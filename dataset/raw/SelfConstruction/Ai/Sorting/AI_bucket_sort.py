def bucket_sort(arr: list) -> list:
    """Sorts a list of floating-point numbers uniformly distributed in [0, 1)."""
    if not arr:
        return arr

    # Create empty buckets
    bucket_count = len(arr)
    buckets = [[] for _ in range(bucket_count)]

    # Put array elements into different buckets based on their values
    for num in arr:
        index = int(bucket_count * num)
        # Handle edge case if num == 1.0
        if index >= bucket_count:
            index = bucket_count - 1
        buckets[index].append(num)

    # Sort individual buckets using built-in sort (which is highly optimized Timsort)
    for i in range(bucket_count):
        buckets[i].sort()

    # Concatenate all buckets into original array
    sorted_arr = []
    for bucket in buckets:
        sorted_arr.extend(bucket)
        
    return sorted_arr

# Example Usage
if __name__ == "__main__":
    sample_data = [0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434]
    print("Original array:", sample_data)
    sorted_data = bucket_sort(sample_data.copy())
    print("Bucket Sorted array:", sorted_data)