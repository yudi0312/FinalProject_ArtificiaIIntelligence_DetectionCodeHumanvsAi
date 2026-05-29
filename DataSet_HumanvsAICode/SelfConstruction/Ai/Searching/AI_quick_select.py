def quick_select(collection, k):
    """Return the k-th smallest element (0-indexed) using QuickSelect."""
    items = list(collection)  # Work on a copy to avoid mutating the input
 
    def partition(arr, low, high):
        """Partition arr[low..high] around arr[high] as pivot."""
        pivot = arr[high]
        store_index = low
        for i in range(low, high):
            if arr[i] <= pivot:
                arr[i], arr[store_index] = arr[store_index], arr[i]
                store_index += 1
        arr[store_index], arr[high] = arr[high], arr[store_index]
        return store_index
 
    left, right = 0, len(items) - 1
    while left <= right:
        pivot_index = partition(items, left, right)
        if pivot_index == k:
            return items[pivot_index]
        elif pivot_index < k:
            left = pivot_index + 1
        else:
            right = pivot_index - 1
 
    return -1  # k out of bounds
 
 
if __name__ == "__main__":
    numbers = [7, 2, 5, 3, 9, 1, 8]
    result = quick_select(numbers, 2)  # 3rd smallest (0-indexed k=2)
    print(f"[Quick Select] 3rd smallest element: {result}")               # → 3
