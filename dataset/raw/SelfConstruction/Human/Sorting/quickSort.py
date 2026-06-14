# Python program for implementation of Quick Sort

# divide function
def partition(arr, low, high):
    i = (low-1)
    pivot = arr[high]  # pivot element
    for j in range(low, high):
        # If current element is smaller
        if arr[j] <= pivot:
            # increment
            i = i+1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i+1], arr[high] = arr[high], arr[i+1]
    return i+1


# quick sort function
def quick_sort(arr, low, high):
    if low < high:
        # index
        pi = partition(arr, low, high)
        # sort the partitions
        quick_sort(arr, low, pi-1)
        quick_sort(arr, pi+1, high)
