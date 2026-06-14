# Python program for implementation of Heap Sort

# heapify
def heapify(arr, n, i):
    largest = i   # largest value
    left = 2 * i + 1   # left
    right = 2 * i + 2   # right
    # if left child exists
    if left < n and arr[i] < arr[left]:
        largest = left
    # if right child exits
    if right < n and arr[largest] < arr[right]:
        largest = right
    # root
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]   # swap
        # root.
        heapify(arr, n, largest)


# sort
def heap_sort(arr):
    n = len(arr)
    # max_heap
    for i in range(n, -1, -1):
        heapify(arr, n, i)
    # element extraction
    for i in range(n-1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]   # swap
        heapify(arr, i, 0)
