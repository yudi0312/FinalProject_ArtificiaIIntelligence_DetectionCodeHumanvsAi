# Python program for implementation of Shell Sort

# shell sort function
def shell_sort(arr):
	# gap / incrementor
    gap = len(arr) // 2
    while gap > 0:
    	# sorting the sublist using insertion sort
        for i in range(gap, len(arr)):
            t = arr[i]
            j = i
            while j >= gap and arr[j - gap] > t:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = t
        gap = gap // 2		# reducing the gap
