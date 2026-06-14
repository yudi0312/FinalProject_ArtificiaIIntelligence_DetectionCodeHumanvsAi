# Python program for implementation of Counting Sort

# counting sort function
def countingSort(arr):
    n = len(arr)  # can be given as a function parameter too.
    k = max(arr)  # better to have a function to find max value in an array.
    
    # initializing count array.
    count = [0 for _ in range(k + 1)]
    
    # array required to add the sorted values.
    b = [0 for _ in range(n)]
    
    # to get the frequency of each number in the given array.
    for i in range(n):
        count[arr[i]] += 1

    # updating count array.
    for i in range(1, k + 1):
        count[i] += count[i - 1]

    # iterating over the given array and creating the sorted array.
    for i in range(n - 1, -1, -1):  # backward iteration will provide STABILITY to the sorting algorithm.
        count[arr[i]] -= 1  # initially we have to decrease the the count inorder to obtain the proper index.
        b[count[arr[i]]] = arr[i]  
        
    # just copying the elements in sorted b to unsorted arr [similar to, arr = b].
    for i in range(n):
        arr[i] = b[i]
